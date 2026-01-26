// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Lock.h"

// Sets default values
ACPP_Lock::ACPP_Lock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ACPP_Lock::BeginPlay()
{
	Super::BeginPlay();

	// initialize values
	LockDigitCount = LockCombination.Num();
	Mesh->SetStaticMesh(ClosedLockMesh);
	CurrentUserCombination.SetNumZeroed(LockDigitCount);
}

// Called every frame
void ACPP_Lock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Lock::InsertDigit(ELockDigits Digit, int Position)
{
	if (Position >= LockDigitCount || Position < 0)
	{
		// out of bounds case
		check(GEngine); GEngine->AddOnScreenDebugMessage(101, 5.f, FColor::Red, FString::Printf(TEXT("Digit out of bounds at position %d"), Position));
		return;
	}
	CurrentUserCombination[Position] = Digit;
}

void ACPP_Lock::TryUnlock()
{
	for (int i = 0; i < LockDigitCount; i++)
	{
		if (CurrentUserCombination[i] != LockCombination[i])
		{
			// Incorrect combination
			check(GEngine); GEngine->AddOnScreenDebugMessage(101, 5.f, FColor::Red, TEXT("Incorrect combination!"));
			return;
		}
	}
	
	// Correct combination
	check(GEngine); GEngine->AddOnScreenDebugMessage(102, 5.f, FColor::Red, TEXT("Correct combination!"));
	bIsLocked = false;
	Mesh->SetStaticMesh(OpenLockMesh);
}

bool ACPP_Lock::IsLocked()
{
	return bIsLocked;
}

