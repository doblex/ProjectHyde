// Fill out your copyright notice in the Description page of Project Settings.


#include "HintSubsystem.h"
#include "ProjectHyde/Core/DevSettings/HintSubsystemSettings.h"
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
	
	const UHintSubsystemSettings* Settings = GetDefault<UHintSubsystemSettings>();
	
	if (Settings)
	{
		const FString ContextString(TEXT("Context"));
		
		TArray<FHintDialogueDataRow*> Rows;
		
		Settings->Hints.Get()->GetAllRows(ContextString, Rows);
		
		if (Rows.IsEmpty()) return;

		for (const FHintDialogueDataRow* Row : Rows)
		{
			HintsDataMap.Add(Row->Tag, Row->Data);
			
			if (Row->Data.HintType == Tutorial)
			{
				HintTriggerMap.Add(Row->Tag, false);
			}
			
		}
	}
}

void UHintSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UHintSubsystem::OnHintActivation(FGameplayTag EventSource)
{
	UE_LOG(LogTemp, Display, TEXT("Hint event activated: %s"),*EventSource.GetTagName().ToString());
	
	FHintData Data = *HintsDataMap.Find(EventSource);

	const bool bIsTutorial = Data.HintType == Tutorial;
	
	if (bIsTutorial)
	{
		bool bAlreadyTriggered = *HintTriggerMap.Find(EventSource);
		if (bAlreadyTriggered)
		{
			UE_LOG(LogTemp,Display,TEXT("Tutorial already played"))
			return;
		} 
	}
	
	UBaseDialogue* Dialogue = Data.Dialogue;
	
	if (!Dialogue) return;
	
	UE_LOG(LogTemp,Display,TEXT("Hint Dialogue found: %s"), *Dialogue->DialogueName.ToString())
	
	OnStartHintDialogue.Broadcast(Dialogue,false, Data.bIsInMenu);
	
	if (bIsTutorial)
	{
		HintTriggerMap[EventSource] = true;
	}
}
