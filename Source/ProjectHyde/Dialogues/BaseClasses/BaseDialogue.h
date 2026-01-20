// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseLineNode.h"
#include "Engine/DataAsset.h"
#include "BaseDialogue.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UBaseDialogue : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	FName DialogueName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	FString Description;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Command")
	UBaseLineNode* RootLine;
};
