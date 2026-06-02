// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"

#include "FHintDialogueDataRow.generated.h"

class UBaseDialogue;

UENUM()
enum EHintType
{
	OverMenu,
	AfterMenu
};

USTRUCT(BlueprintType)
struct FHintData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Tag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBaseDialogue* Dialogue = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInMenu = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOneTime = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EHintType> HintType = OverMenu;
	
	FORCEINLINE bool operator==(FHintData const& Other) const
	{
		return Tag == Other.Tag;
	}
};

USTRUCT(BlueprintType)
struct PROJECTHYDE_API FHintDialogueDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHintData Data;
};


