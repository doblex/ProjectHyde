// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "HintSubsystem.generated.h"

class UBaseDialogue;
class UHintable;

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UHintSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	TMap<FGameplayTag, UBaseDialogue*> HintsMap;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UFUNCTION(BlueprintCallable)
	void OnHintActivation (FGameplayTag EventSource);
	
public:
	UFUNCTION(BlueprintCallable)
	void RegisterObject (UObject* Obj);
	

};
