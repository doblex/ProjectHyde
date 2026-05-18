// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MousePointerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UMousePointerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
private:
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

	
};
