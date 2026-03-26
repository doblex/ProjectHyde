// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "InputActionDataRow.generated.h"

/**
 * 
 */

class UInputAction;

USTRUCT(BlueprintType)
struct PROJECTHYDE_API FInputActionDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UInputAction> InputAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* DisplayImage;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName DisplayName;
	
};
