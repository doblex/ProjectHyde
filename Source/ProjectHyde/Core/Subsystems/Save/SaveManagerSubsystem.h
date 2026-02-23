// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "../../../Save/HydeSaveGame.h"
#include "../../../Interface/Saveable.h"
#include "../../../Core/Subsystems/EventFlags/CPP_EventFlagSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "SaveManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API USaveManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UHydeSaveGame* SaveGameInstance;

public:
	// Asynchronous save and load that are globally accessible from different GameModes/PlayerControllers
	UFUNCTION(BlueprintCallable)
	void SaveGame(const FString SaveSlotName, const int32 UserIndex);

	UFUNCTION(BlueprintCallable)
	void LoadGame(const FString SaveSlotName, const int32 UserIndex);

	// TODO make delegates to know when saving and loading is finished
	
};
