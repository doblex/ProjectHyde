// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NotebookItemData.generated.h"

/**
 * 
 */

UENUM()
enum class ENotebookItemType : uint8 {
	Scene		UMETA(DisplayName = "Scene"),
	Inventory	UMETA(DisplayName = "Inventory"),
	Person		UMETA(DisplayName = "Person"),
	Dialogue	UMETA(DisplayName = "Dialogue")
};

UCLASS(BlueprintType)
class PROJECTHYDE_API UNotebookItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	FText Title;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	ENotebookItemType NotebookItemType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	TSoftObjectPtr<UTexture2D> Thumbnail;

	// Only in case it's a dialogue bookmark
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	FText Dialogue;
};
