// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DialogueSubsystemSettings.generated.h"

class UCommandExecutorLibrary;
/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName= "Dialogue Subsystem Settings"))
class PROJECTHYDE_API UDialogueSubsystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere, Category = "Dialogue Subsystem")
	TSubclassOf<UCommandExecutorLibrary> CommandExecutorLibrary;
};
