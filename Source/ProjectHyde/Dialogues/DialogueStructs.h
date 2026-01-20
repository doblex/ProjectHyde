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
	}

	FDialogueCommandLine(const FName CommandName)
		:CommandName(CommandName)
	{
	}
	
	FDialogueCommandLine(const FName CommandName, const TArray<UValue*> Args)
		:CommandName(CommandName), Args(Args)
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	FName CommandName = FName("");
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	TArray<UValue*> Args;
};
