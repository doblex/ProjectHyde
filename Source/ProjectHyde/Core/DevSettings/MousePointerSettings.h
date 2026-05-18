// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "MousePointerSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Mouse Pointer Settings"))
class PROJECTHYDE_API UMousePointerSettings : public UDeveloperSettings
{
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere, Category = "Mouse Pointer")
	TSoftObjectPtr<UTexture2D> NeutralMousePointer;

	UPROPERTY(Config, EditAnywhere, Category = "Mouse Pointer")
	TSoftObjectPtr<UTexture2D> MovementMousePointer;

	UPROPERTY(Config, EditAnywhere, Category = "Mouse Pointer")
	TSoftObjectPtr<UTexture2D> ObservationMousePointer;

	UPROPERTY(Config, EditAnywhere, Category = "Mouse Pointer")
	TSoftObjectPtr<UTexture2D> InteractMousePointer;

	UPROPERTY(Config, EditAnywhere, Category = "Mouse Pointer")
	TSoftObjectPtr<UTexture2D> ObjectMousePointer;

	UPROPERTY(Config, EditAnywhere, Category = "Mouse Pointer")
	TSoftObjectPtr<UTexture2D> ZoomMousePointer;
	
};
