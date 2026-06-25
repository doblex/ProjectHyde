// Fill out your copyright notice in the Description page of Project Settings.


#include "HintSubsystem.h"

#include "ProjectHyde/Core/DevSettings/HintSubsystemSettings.h"
#include "ProjectHyde/Core/Subsystems/UI/WidgetReturnStackSubsystem.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseDialogue.h"
#include "ProjectHyde/Interface/Hintable.h"

void UHintSubsystem::RegisterObject(UObject* Obj)
{
	if (!Obj) return;
	
	if (!Obj->Implements<UHintable>()) return;
	
	IHintable* Hintable = Cast<IHintable>(Obj);
	
	Hintable->GetOnHintActivationDelegate().AddDynamic(this ,&UHintSubsystem::OnHintActivation);
	
	UE_LOG(LogTemp, Display, TEXT("%s has subscribed to the hint system"), *Obj->GetName())
}

void UHintSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	Collection.InitializeDependency<UWidgetReturnStackSubsystem>();
	
	const UHintSubsystemSettings* Settings = GetDefault<UHintSubsystemSettings>();
	
	if (Settings)
	{
		const FString ContextString(TEXT("Context"));
		
		TArray<FHintDialogueDataRow*> Rows;
		
		if (Settings->Hints.IsNull()) return;
		
		UDataTable* DataTable = Settings->Hints.LoadSynchronous();
		
		DataTable->GetAllRows(ContextString, Rows);
		
		if (Rows.IsEmpty()) return;

		for (const FHintDialogueDataRow* Row : Rows)
		{
			HintsDataMap.Add(Row->Data.Tag, Row->Data);
			
			if (Row->Data.bIsOneTime)
			{
				HintTriggerMap.Add(Row->Data.Tag, false);
			}
			
		}
	}
	
	ensure(GetLocalPlayer());
	
	WidgetReturnStack = GetLocalPlayer()->GetSubsystem<UWidgetReturnStackSubsystem>();
	
	ensure(WidgetReturnStack);
	
	WidgetReturnStack->OnEmptyStack.BindDynamic(this, &UHintSubsystem::OnWidgetStackEmpty);
}

void UHintSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UHintSubsystem::PlayOverMenu(FHintData Data)
{
	UBaseDialogue* Dialogue = Data.Dialogue.LoadSynchronous();
	
	if (!Dialogue) return;
	
	OnStartHintDialogue.Broadcast(Dialogue,false, Data.bIsInMenu);
	
	UE_LOG(LogTemp,Display,TEXT("Tutorial played"))
}

void UHintSubsystem::PlayAfterMenu(FHintData Data)
{
	UBaseDialogue* Dialogue = Data.Dialogue.LoadSynchronous();
	
	if (!Dialogue) return;
	
	if (WidgetReturnStack->IsUIOpen())
	{
		OnStartHintDialogue.Broadcast(Dialogue,false, Data.bIsInMenu);
		UE_LOG(LogTemp,Display,TEXT("Hint played"))
	}
	else
	{
		if (!HintQueue.Contains(Data))
		{
			HintQueue.Push(Data);
			UE_LOG(LogTemp,Display,TEXT("Hint Stacked"))
		}
		else
		{
			UE_LOG(LogTemp,Display,TEXT("duplicated Hint"))
		}
	}
}

void UHintSubsystem::OnHintActivation(FGameplayTag EventSource)
{
	UE_LOG(LogTemp, Display, TEXT("Hint event activated: %s"),*EventSource.GetTagName().ToString());
	
	const FHintData Data = *HintsDataMap.Find(EventSource);

	if (HintTriggerMap.Contains(Data.Tag))
	{
		bool bAlreadyTriggered = *HintTriggerMap.Find(Data.Tag);
	
		if (bAlreadyTriggered)
		{
			UE_LOG(LogTemp,Display,TEXT("Hint already played"))
			return;
		} 
	}
	
	switch (Data.HintType)
	{
		case OverMenu:
			PlayOverMenu(Data);
		break;
		case AfterMenu:
			PlayAfterMenu(Data);
		break;
	}
	
	if (HintTriggerMap.Contains(Data.Tag))
	{
		HintTriggerMap[Data.Tag] = true;
	}
}

void UHintSubsystem::OnWidgetStackEmpty()
{
	if (HintQueue.IsEmpty()) return;

	const FHintData Data = HintQueue.Pop();
	
	UBaseDialogue* Dialogue = Data.Dialogue.LoadSynchronous();
	
	if (!Dialogue) return;
	
	OnStartHintDialogue.Broadcast(Dialogue,false, Data.bIsInMenu);
}

void UHintSubsystem::ResetHint()
{
	for (auto& Element : HintTriggerMap)
	{
		Element.Value = false;
	}
}
