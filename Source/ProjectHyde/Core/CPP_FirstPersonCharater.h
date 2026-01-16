// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "CPP_FirstPersonCharater.generated.h"

class AArtifact;

UCLASS()
class GAUNTLET2_API ACPP_FirstPersonCharater : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_FirstPersonCharater();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player|Input")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player|Input")
	TObjectPtr<UInputAction> PauseAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player|Input")
	TObjectPtr<UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player|Interaction")
	float InteractRange;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Interaction")
	TEnumAsByte<ECollisionChannel> InteractChannel = ECC_GameTraceChannel1;
	
	void Look(const struct FInputActionValue& Value);
	void Pause(const struct FInputActionValue& Value);
	void Interact(const struct FInputActionValue& Value);
};
