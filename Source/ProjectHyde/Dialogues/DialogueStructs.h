// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseClasses/Value.h"
#include "DialogueStructs.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FDialogueCommandLine
{
	GENERATED_BODY()
	
	FDialogueCommandLine()
	{
		CommandName = "";
		Args.Empty();
	}

	FDialogueCommandLine(const FName CommandName)
		:CommandName(CommandName)
	{
		Args.Empty();
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	FName CommandName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	TArray<UValue*> Args;
};
