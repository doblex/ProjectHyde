// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MousePointerSubsystem.generated.h"

UENUM(BlueprintType)
enum class EMousePointerState : uint8
{
	Neutral,
	Movement,
	Observation,
	Interact,
	Object,
	Zoom
};

// Dynamic delegate can be used from blueprints like WBP
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMouseIconChanged, EMousePointerState, NewState);

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UMousePointerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	EMousePointerState MouseState = EMousePointerState::Neutral;
	UTexture2D* NeutralMousePointer;
	UTexture2D* MovementMousePointer;
	UTexture2D* ObservationMousePointer;
	UTexture2D* InteractMousePointer;
	UTexture2D* ObjectMousePointer;
	UTexture2D* ZoomMousePointer;

public:
	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem

	// Event triggered when state is updated to change the mouse icon
	UPROPERTY(BlueprintAssignable, Category = "Mouse Pointer")
	FOnMouseIconChanged OnMouseIconChanged;

	// Update from the player class
	UFUNCTION(BlueprintCallable, Category = "Mouse Pointer")
	void SetPointerState(EMousePointerState NewState);

	// Get the texture corresponding to the state
	UFUNCTION(BlueprintCallable, Category = "Mouse Pointer")
	UTexture2D* GetTextureForState(EMousePointerState State) const;
};
