// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "../../DevSettings/EventFlagSubsystemSettings.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"
#include "NativeGameplayTags.h"
#include "CPP_EventFlagSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(EventFlagSubSystem, Log, All);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(EventFlags);

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UCPP_EventFlagSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
private:
	UDataTable* EventFlagsData;

	void OnEventFlagTableLoaded(TSoftObjectPtr<UDataTable> TablePtr);

	bool bTagsLoaded = false;


public:
	TMap<FGameplayTag, bool> EventFlagMap;

public:
	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem

	UFUNCTION(BlueprintCallable)
	bool SetEventFlag(FGameplayTag Flag, bool bValue);

	UFUNCTION(BlueprintCallable)
	bool GetEventFlag(FGameplayTag Flag);

	UFUNCTION(BlueprintCallable)
	TMap<FGameplayTag, bool> GetEventFlagMap();

	UFUNCTION(BlueprintCallable)
	bool AreTagsLoaded();
};
