// Fill out your copyright notice in the Description page of Project Settings.


#include "HintSubsystem.h"
#include "GameplayTagContainer.h"
#include "ProjectHyde/Interface/Hintable.h"

void UHintSubsystem::RegisterObject(UObject* Obj)
{
	if (!Obj) return;
	
	if (!Obj->Implements<UHintable>()) return;
	
	IHintable* Hintable = Cast<IHintable>(Obj);
	
	Hintable->GetOnHintActivationDelegate().AddDynamic(this ,&UHintSubsystem::OnHintActivation);
	
	UE_LOG(LogTemp, Display, TEXT("%s has subscribed to the hint system"), *Obj->GetName())
}

void UHintSubsystem::OnHintActivation(FGameplayTag EventSource)
{
	UE_LOG(LogTemp, Display, TEXT("Hint event activated: %s"),*EventSource.GetTagName().ToString());
}
