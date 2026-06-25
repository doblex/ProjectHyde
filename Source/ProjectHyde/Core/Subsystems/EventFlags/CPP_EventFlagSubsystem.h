// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "../../../Save/HydeSaveGame.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "CPP_EventFlagSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(EventFlagSubsystem, Log, All);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(EventFlags);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEventFlagChanged);


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
	
	UPROPERTY(BlueprintAssignable)
	FOnEventFlagChanged OnEventFlagChanged;

	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem

	// Sets the boolean value of the given flag
	UFUNCTION(BlueprintCallable)
	bool SetEventFlag(FGameplayTag Flag, bool bValue);

	// Gets the boolean value of the given flag
	UFUNCTION(BlueprintCallable)
	bool GetEventFlag(FGameplayTag Flag);

	// Gets a reference to the map pf event flags and their boolean values
	UFUNCTION(BlueprintCallable)
	TMap<FGameplayTag, bool> GetEventFlagMap();

	UFUNCTION(BlueprintCallable)
	bool GetTagFromString(FString TagString, FGameplayTag& OutTag);
	
	// Returns true if event flag tags have been loaded from table
	UFUNCTION(BlueprintCallable)
	bool AreTagsLoaded();

	// Sets all flags to false
	UFUNCTION(BlueprintCallable)
	void ResetAllFlags();

	// Custom save and load without interface
	void Save(UHydeSaveGame* SaveGameInstance);

	void Load(const UHydeSaveGame* SaveGameInstance);
};
