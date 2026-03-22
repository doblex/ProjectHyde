// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CPP_SaveGameIdComponent.h"
#include "../Interface/Saveable.h"
#include "../Save/HydeSaveGame.h"
#include "Serialization/Archive.h"
#include "CPP_Lock.generated.h"

UENUM()
enum class ELockDigits : uint8 {
   One		UMETA(DisplayName = "1"),
   Two		UMETA(DisplayName = "2"),
   Three	UMETA(DisplayName = "3"),
   Four		UMETA(DisplayName = "4"),
   Five		UMETA(DisplayName = "5"),
   Six		UMETA(DisplayName = "6"),
   Seven	UMETA(DisplayName = "7"),
   Eight	UMETA(DisplayName = "8"),
   Nine		UMETA(DisplayName = "9"),
   NaN		UMETA(DisplayName = "Not a Number")
};

UCLASS()
class PROJECTHYDE_API ACPP_Lock : public AActor, public ISaveable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Lock();

	// Lock wheel collisions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock")
	UBoxComponent* Wheel1Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock")
	UBoxComponent* Wheel2Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock")
	UBoxComponent* Wheel3Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock")
	UBoxComponent* Wheel4Collision;

private:
	// Lock combination to insert in inspector
	UPROPERTY(EditAnywhere, Category = "Lock")
	TArray<ELockDigits> LockCombination;

	// Lock combination currently inserted by user
	UPROPERTY(VisibleAnywhere, Category = "Lock")
	TArray<ELockDigits> CurrentUserCombination;

	int LockDigitCount;

	UPROPERTY(VisibleAnywhere, Category = "Lock")
	bool bIsLocked = true;

	UPROPERTY(VisibleAnywhere, Category = "Lock")
	class USceneComponent* RootSceneComponent;

	// Mesh for the lock
	UPROPERTY(EditAnywhere, Category = "Lock")
	USkeletalMeshComponent* Mesh;

	// Animation montage
	UPROPERTY(EditAnywhere, Category = "Lock")
	UAnimMontage* LockMontage;

	// GUID component for saving
	UCPP_SaveGameIdComponent* GUID_Component;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Get digit at the specified position
	UFUNCTION(BlueprintCallable, Category = "Lock")
	ELockDigits GetDigit(int Position);

	UFUNCTION(BlueprintCallable, Category = "Lock")
	void IncrementDigit(int Position);

	// Insert a digit into the user combination at the specified position (starting from 1)
	UFUNCTION(BlueprintCallable, Category = "Lock")
	void InsertDigit(ELockDigits Digit, int Position);

	// Test the user submitted combination against the correct combination
	UFUNCTION(BlueprintCallable, Category = "Lock")
	void TryUnlock();

	// Check if lock is locked
	UFUNCTION(BlueprintCallable, Category = "Lock")
	bool IsLocked();

	// Save system
	virtual void Save_Implementation(UHydeSaveGame* SaveGameInstance) override;

	virtual void Load_Implementation(const UHydeSaveGame* SaveGameInstance, const FGuid GUID) override;

	void SerializeActorData(FArchive& Ar);
};
