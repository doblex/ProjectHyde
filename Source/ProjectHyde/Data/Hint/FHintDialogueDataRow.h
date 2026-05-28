// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"

#include "FHintDialogueDataRow.generated.h"

class UBaseDialogue;
/**
 * 
 */
USTRUCT(BlueprintType)
struct PROJECTHYDE_API FHintDialogueDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Tag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBaseDialogue* Dialogue = nullptr;
};
