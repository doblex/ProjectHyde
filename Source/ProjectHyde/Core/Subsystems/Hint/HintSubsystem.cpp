// Fill out your copyright notice in the Description page of Project Settings.


#include "HintSubsystem.h"
#include "ProjectHyde/Core/DevSettings/HintSubsystemSettings.h"
#include "ProjectHyde/Data/Hint/FHintDialogueDataRow.h"
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
			HintsMap.Add(Row->Tag, Row->Dialogue);
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
	
	UBaseDialogue* Dialogue = *HintsMap.Find(EventSource);
	
	if (!Dialogue) return;
	
	UE_LOG(LogTemp,Display,TEXT("Hint Dialogue found: %s"), *Dialogue->DialogueName.ToString())
}
