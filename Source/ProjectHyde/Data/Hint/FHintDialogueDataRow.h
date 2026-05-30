// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"

#include "FHintDialogueDataRow.generated.h"

class UBaseDialogue;

UENUM()
enum EHintType
{
	Hint,
	Tutorial
};

USTRUCT(BlueprintType)
struct FHintData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBaseDialogue* Dialogue = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInMenu = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EHintType> HintType = Hint;
};

USTRUCT(BlueprintType)
struct PROJECTHYDE_API FHintDialogueDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Tag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHintData Data;
};


