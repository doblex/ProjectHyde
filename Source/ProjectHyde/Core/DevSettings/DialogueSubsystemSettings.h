// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DialogueSubsystemSettings.generated.h"

class UCommandExecutorLibrary;
/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName= "Dialogue Settings"))
class PROJECTHYDE_API UDialogueSubsystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	/// It limits the amount of linear dialogues to max n. If 0 then it is limitless
	UPROPERTY(Config, EditAnywhere, Category = "Dialogue Subsystem")
	int MaxDialoguesNumber = 3;
	
	/// The path to save the dialogue assets during import of .Yarn files
	UPROPERTY(Config, EditAnywhere, Category = "Dialogue Import")
	FDirectoryPath DialogueImportPath = FDirectoryPath("/Game/Dialogues/");
};
