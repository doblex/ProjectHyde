// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "EventFlagSubsystemSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Event Flag Settings"))
class PROJECTHYDE_API UEventFlagSubsystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	// Data table containing Event Flags for the game
	UPROPERTY(Config, EditAnywhere, Category = "Event Flag Subsystem")
	
	TSoftObjectPtr<UDataTable> EventFlagsDataTable;
	
};
