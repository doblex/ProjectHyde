// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHyde/Dialogues/DialogueStructs.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DialogueCommandSubsystem.generated.h"

class UDialogueRunnerComponent;
class UValue;
/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UDialogueCommandSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	UBlueprintFunctionLibrary* CommandLibrary;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
public:
	void ExecuteCommand(FDialogueCommandLine Command, UDialogueRunnerComponent* Performer);
	
};
