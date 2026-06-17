// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "HintSubsystemSettings.generated.h"

/**
 * 
 */

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Hint Subsystem Settings"))
class PROJECTHYDE_API UHintSubsystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr<UDataTable> Hints;
};
