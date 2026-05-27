// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MouseHoverSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UMouseHoverSubsystem : public ULocalPlayerSubsystem   
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	bool IsMouseInsideWidget(UUserWidget* Widget);
	
private:
	FVector2D GetMousePositionInWidget(UUserWidget* Widget);
};
