// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "HintSubsystem.generated.h"

class UHintable;
struct FGameplayTag;
/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UHintSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void OnHintActivation (FGameplayTag EventSource);
	
public:
	UFUNCTION(BlueprintCallable)
	void RegisterObject (UObject* Obj);
	

};
