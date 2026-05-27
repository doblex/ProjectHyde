// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ProjectHyde/Core/Subsystems/Hint/HintSubsystem.h"
#include "UObject/Interface.h"
#include "Hintable.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHintActivation, FGameplayTag, EventSource);

// This class does not need to be modified.
UINTERFACE()
class UHintable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTHYDE_API IHintable
{
	GENERATED_BODY()
	
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	
public:
	virtual FOnHintActivation& GetOnHintActivationDelegate() = 0;
	
};
