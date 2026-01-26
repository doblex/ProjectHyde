// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Lock.generated.h"

UENUM()
enum class ELockDigits : uint8 {
   Zero		UMETA(DisplayName = "0"),
   One		UMETA(DisplayName = "1"),
   Two		UMETA(DisplayName = "2"),
   Three	UMETA(DisplayName = "3"),
   Four		UMETA(DisplayName = "4"),
   Five		UMETA(DisplayName = "5"),
   Six		UMETA(DisplayName = "6"),
   Seven	UMETA(DisplayName = "7"),
   Eight	UMETA(DisplayName = "8"),
   Nine		UMETA(DisplayName = "9")
};

UCLASS()
class PROJECTHYDE_API ACPP_Lock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Lock();

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

	// Mesh component for the lock
	UStaticMeshComponent* Mesh;

	// Mesh to use when the lock is closed
	UPROPERTY(EditAnywhere, Category = "Lock")
	UStaticMesh* ClosedLockMesh;

	// Mesh to use when the lock is open
	UPROPERTY(EditAnywhere, Category = "Lock")
	UStaticMesh* OpenLockMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Insert a digit into the user combination at the specified position (starting from 0)
	UFUNCTION(BlueprintCallable, Category = "Lock")
	void InsertDigit(ELockDigits Digit, int Position);

	// Test the user submitted combination against the correct combination
	UFUNCTION(BlueprintCallable, Category = "Lock")
	void TryUnlock();

	// Check if lock is locked
	UFUNCTION(BlueprintCallable, Category = "Lock")
	bool IsLocked();

};
