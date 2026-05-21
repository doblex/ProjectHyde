// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemData.h"
#include "UObject/Object.h"
#include "InventoryCombinationDataRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PROJECTHYDE_API FInventoryCombinationDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UInventoryItemData> Item1;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UInventoryItemData> Item2;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UInventoryItemData> Result;
	
	bool Equal(UInventoryItemData* Itm1, UInventoryItemData* Itm2);
	
// #if WITH_EDITOR
// 	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
// #endif
	
};
