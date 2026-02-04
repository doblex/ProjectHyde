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
	
	UPROPERTY(Instanced, EditAnywhere, BlueprintReadWrite, Category = "Command")
	TArray<UValue*> Args;
};

USTRUCT()
struct FDialogueCommandReturn
{
	GENERATED_BODY()
	
	FDialogueCommandReturn() 
		: HasReturn(false),
		ReturnValue(false),
		HasOutValue(false),
		OutValue(false)
	{}
	
	bool HasReturn;
	bool ReturnValue;
	
	bool HasOutValue;
	bool OutValue;
	
	void SetReturnValue(bool Value)
	{
		this->ReturnValue = Value;
		this->HasReturn = true;
	}
	
	void SetOutValue(bool Value)
	{
		this->OutValue = Value;
		this->HasOutValue = true;
	}
};
