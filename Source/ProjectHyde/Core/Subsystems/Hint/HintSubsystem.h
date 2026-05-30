// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "ProjectHyde/Data/Hint/FHintDialogueDataRow.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "HintSubsystem.generated.h"


struct FHintData;
class UBaseDialogue;
class UHintable;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
	FOnStartHintDialogue,
	UBaseDialogue*, Dialogue,
	bool ,bIsPerson,
	bool, bIsinMenu
	);
/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UHintSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	TMap<FGameplayTag, FHintData> HintsDataMap;
	TMap<FGameplayTag, bool> HintTriggerMap;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
public:
	UPROPERTY(BLueprintAssignable)
	FOnStartHintDialogue OnStartHintDialogue;
	
	UFUNCTION(BlueprintCallable)
	void OnHintActivation (FGameplayTag EventSource);
	
	UFUNCTION(BlueprintCallable)
	void RegisterObject (UObject* Obj);
};
