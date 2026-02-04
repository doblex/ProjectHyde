// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHyde/Dialogues/DialogueStructs.h"
#include "UObject/Object.h"
#include "CommandExecutorLibrary.generated.h"

struct FDialogueCommandLine;
/**
 * 
 */
UCLASS(Blueprintable)
class PROJECTHYDE_API UCommandExecutorLibrary : public UObject
{
	GENERATED_BODY()
	
public:
	bool ExecuteCommand(FDialogueCommandLine Command, FDialogueCommandReturn& ReturnValue);
};
