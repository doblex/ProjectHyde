// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "../../../Save/HydeSaveGame.h"
#include "../../../Interface/Saveable.h"
#include "../../../Actors/Components/CPP_SaveGameIdComponent.h"
// Actors to save
#include "../../../Actors/CPP_Lock.h"
// Subsystems to save
#include "../../../Core/Subsystems/EventFlags/CPP_EventFlagSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "SaveManagerSubsystem.generated.h"

/**
 * 
 */

DECLARE_LOG_CATEGORY_EXTERN(SaveSubsystem, Log, All);

UCLASS()
class PROJECTHYDE_API USaveManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Delegates to know when saving and loading is finished
	FAsyncSaveGameToSlotDelegate OnSaveCompleted;
	FAsyncLoadGameFromSlotDelegate OnLoadCompleted;

private:
	UHydeSaveGame* SaveGameInstance;

public:
	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem

	// Asynchronous save and load that are globally accessible from different GameModes/PlayerControllers
	UFUNCTION(BlueprintCallable)
	void SaveGame(const FString& SaveSlotName, const int32 UserIndex);

	UFUNCTION(BlueprintCallable)
	void LoadGame(const FString& SaveSlotName, const int32 UserIndex);

private:
	void HandleGameSaveCompleted(const FString& SaveSlotName, const int32 UserIndex, bool SaveSucceeded);
	void HandleGameLoadCompleted(const FString& SaveSlotName, const int32 UserIndex, USaveGame* LoadedSaveFile);
	
};
