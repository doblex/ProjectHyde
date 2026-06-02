// Fill out your copyright notice in the Description page of Project Settings.


#include "HintableActor.h"


// Sets default values
AHintableActor::AHintableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHintableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHintableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FOnHintActivation& AHintableActor::GetOnHintActivationDelegate()
{
	return OnHintActivation;
}

