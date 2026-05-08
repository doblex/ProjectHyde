// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseLineNode.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "BaseDialogue.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTHYDE_API UBaseDialogue : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")
	FName DialogueName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")
	FString Description;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")
	FGameplayTagContainer Requirements;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Line")
	UBaseLineNode* RootLine;
	
	FDialogueEntry GetDialogueEntry();
	
};
