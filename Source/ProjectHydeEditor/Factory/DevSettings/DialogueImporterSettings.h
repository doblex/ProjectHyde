// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Internationalization/StringTable.h"
#include "DialogueImporterSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName= "Dialogue Importer Settings"))
class PROJECTHYDEEDITOR_API UDialogueImporterSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	
	/// The path to save the dialogue assets during import of .Yarn files
	UPROPERTY(Config, EditAnywhere, Category = "Dialogue Import")
	FDirectoryPath DialogueImportPath = FDirectoryPath("/Game/Dialogues/");
	
	UPROPERTY(Config, EditAnywhere, Category = "Dialogue Subsystem")
	TSoftObjectPtr<UStringTable> DialogueStringTable;
	
};
