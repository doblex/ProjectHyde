// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FirstPersonController.h"
#include "EnhancedInputSubsystems.h"


void ACPP_FirstPersonController::BeginPlay()
{
	Super::BeginPlay();

	if (!InputMapping) return;
	

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem)
	{
		Subsystem->AddMappingContext(InputMapping, 0);
	}
}