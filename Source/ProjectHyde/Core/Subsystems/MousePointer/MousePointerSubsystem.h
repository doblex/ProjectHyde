// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StreamableManager.h"
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
	
private:
	TSharedPtr<FStreamableHandle> PointerLoadHandle;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mouse Pointer")
	EMousePointerState MouseState = EMousePointerState::Neutral;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mouse Pointer")
	UTexture2D* NeutralMousePointer = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mouse Pointer")
	UTexture2D* MovementMousePointer = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mouse Pointer")
	UTexture2D* ObservationMousePointer = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mouse Pointer")
	UTexture2D* InteractMousePointer = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mouse Pointer")
	UTexture2D* ObjectMousePointer = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Mouse Pointer")
	UTexture2D* ZoomMousePointer = nullptr;

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
