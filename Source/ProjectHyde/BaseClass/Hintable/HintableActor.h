// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectHyde/Interface/Hintable.h"
#include "HintableActor.generated.h"

UCLASS()
class PROJECTHYDE_API AHintableActor : public AActor, public IHintable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHintableActor();

protected:
	UPROPERTY(BlueprintCallable)
	FOnHintActivation OnHintActivation;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual FOnHintActivation& GetOnHintActivationDelegate() override;
};
