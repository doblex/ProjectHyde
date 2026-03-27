// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Lock.h"

// Sets default values
ACPP_Lock::ACPP_Lock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = RootSceneComponent;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	// Add wheel collisions
	Wheel1Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Wheel1"));
	Wheel1Collision->SetupAttachment(RootComponent);
	Wheel2Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Wheel2"));
	Wheel2Collision->SetupAttachment(RootComponent);
	Wheel3Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Wheel3"));
	Wheel3Collision->SetupAttachment(RootComponent);
	Wheel4Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Wheel4"));
	Wheel4Collision->SetupAttachment(RootComponent);

	// Add GUID for saving
	GUID_Component = CreateDefaultSubobject<UCPP_SaveGameIdComponent>(TEXT("SaveGameIdComponent"));
}

// Called when the game starts or when spawned
void ACPP_Lock::BeginPlay()
{
	Super::BeginPlay();

	// initialize values
	LockDigitCount = LockCombination.Num();
	//Mesh->SetStaticMesh(ClosedLockMesh);
	CurrentUserCombination.SetNumZeroed(LockDigitCount);
	WheelRotations.SetNumZeroed(LockDigitCount);
	WheelAlphas.SetNumZeroed(LockDigitCount);
	//for (int i = 0; i < WheelAlphas.Num(); i++) WheelAlphas[i] = 1;

	if (UAnimInstance* AnimInst = Mesh->GetAnimInstance())
	{
		AnimInst->OnPlayMontageNotifyBegin.AddDynamic(this, &ACPP_Lock::OnEndRotationNotify);
	}
}

// Called every frame
void ACPP_Lock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ELockDigits ACPP_Lock::GetDigit(int Position)
{
	if (Position >= LockDigitCount || Position < 0)
	{
		// out of bounds case
		check(GEngine); GEngine->AddOnScreenDebugMessage(101, 5.f, FColor::Red, FString::Printf(TEXT("Digit out of bounds at position %d"), Position));
		return ELockDigits::NaN;
	}
	return CurrentUserCombination[Position];
}

void ACPP_Lock::IncrementDigit(int Position)
{
	if (Position >= LockDigitCount || Position < 0)
	{
		// out of bounds case
		check(GEngine); GEngine->AddOnScreenDebugMessage(101, 5.f, FColor::Red, FString::Printf(TEXT("Digit out of bounds at position %d"), Position));
		return;
	}

	UAnimInstance* AnimInst = Mesh->GetAnimInstance();

	// Correctness check
	if (!AnimInst || !LockMontage) return;

	// Do nothing until montage is finished
	if (AnimInst->Montage_IsPlaying(LockMontage)) return;

	ELockDigits OldDigit = CurrentUserCombination[Position];

	switch (CurrentUserCombination[Position])
	{
	case ELockDigits::One:
		CurrentUserCombination[Position] = ELockDigits::Two;
		break;
	case ELockDigits::Two:
		CurrentUserCombination[Position] = ELockDigits::Three;
		break;
	case ELockDigits::Three:
		CurrentUserCombination[Position] = ELockDigits::Four;
		break;
	case ELockDigits::Four:
		CurrentUserCombination[Position] = ELockDigits::Five;
		break;
	case ELockDigits::Five:
		CurrentUserCombination[Position] = ELockDigits::Six;
		break;
	case ELockDigits::Six:
		CurrentUserCombination[Position] = ELockDigits::Seven;
		break;
	case ELockDigits::Seven:
		CurrentUserCombination[Position] = ELockDigits::Eight;
		break;
	case ELockDigits::Eight:
		CurrentUserCombination[Position] = ELockDigits::Nine;
		break;
	case ELockDigits::Nine:
		CurrentUserCombination[Position] = ELockDigits::One;
		break;
	default:
		break;
	}

	int32 FromVal = (int32)OldDigit+1;
	int32 ToVal = ((int32)CurrentUserCombination[Position] % 9) + 1;

	FString SectionString = FString::Printf(TEXT("%dto%d"), FromVal, ToVal);
	FName TargetSection = FName(*SectionString);

	float TargetAngle = FromVal * -40.0f;
	WheelRotations[Position] = FRotator(TargetAngle, 0.f, 0.f);
	WheelAlphas[Position] = 1;

	if (AnimInst)
	{
		FProperty* Prop = AnimInst->GetClass()->FindPropertyByName(TEXT("ActiveWheelIndex"));
		if (Prop)
		{
			int32* IntPtr = Prop->ContainerPtrToValuePtr<int32>(AnimInst);
			if (IntPtr) *IntPtr = Position;
		}
		FProperty* AlphaProp = AnimInst->GetClass()->FindPropertyByName(TEXT("BoneAlphas"));
		if (AlphaProp)
		{
			TArray<int32>* AlphaPtr = AlphaProp->ContainerPtrToValuePtr<TArray<int32>>(AnimInst);
			if (AlphaPtr) *AlphaPtr = WheelAlphas;
			UE_LOGFMT(LogTemp, Warning, "Successfully set BoneAlphas[{0}] to 1", Position);
		}
		else {
			UE_LOGFMT(LogTemp, Error, "BoneAlpha pointer is NULL!");
		}
	}

	UE_LOGFMT(LogTemp, Display, "Current Anim Selection string: {0}", SectionString);

	AnimInst->Montage_Play(LockMontage);
	AnimInst->Montage_JumpToSection(TargetSection, LockMontage);
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

	// Play unlock montage when other montages are finished
	Wheel1Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Wheel2Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Wheel3Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Wheel4Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	UAnimInstance* AnimInst = Mesh->GetAnimInstance();

	if (AnimInst) {
		FProperty* OpenProp = AnimInst->GetClass()->FindPropertyByName(TEXT("bIsOpen"));
		if (OpenProp)
		{
			int32* OpenPtr = OpenProp->ContainerPtrToValuePtr<int32>(AnimInst);
			if (OpenPtr) *OpenPtr = 1;
			UE_LOG(LogTemp, Warning, TEXT("Successfully set bIsOpen to true"));
		}
	}
	
	OnLockOpened.Broadcast();
}

bool ACPP_Lock::IsLocked()
{
	return bIsLocked;
}

void ACPP_Lock::OnEndRotationNotify(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
	if (NotifyName != "EndRotation") return;

	UE_LOGFMT(LogTemp, Display, "Ended montage play, Updating rotations");

	UAnimInstance* AnimInst = Mesh->GetAnimInstance();
	if (AnimInst)
	{
		FProperty* AlphaProp = AnimInst->GetClass()->FindPropertyByName(TEXT("BoneAlphas"));
		if (AlphaProp)
		{
			TArray<int32> Zeroes = { 0, 0, 0, 0 };
			TArray<int32>* AlphaPtr = AlphaProp->ContainerPtrToValuePtr<TArray<int32>>(AnimInst);
			if (AlphaPtr) *AlphaPtr = Zeroes;
			UE_LOG(LogTemp, Warning, TEXT("Successfully set BoneAlphas to 0"));
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("BoneAlpha pointer is NULL!"));
		}
		FProperty* RotProp = AnimInst->GetClass()->FindPropertyByName(TEXT("WheelRotations"));
		if (RotProp)
		{
			TArray<FRotator>* RotPtr = RotProp->ContainerPtrToValuePtr<TArray<FRotator>>(AnimInst);
			if (RotPtr) *RotPtr = WheelRotations;
		}

		// Check for Win Condition
		TryUnlock();
	}
}

void ACPP_Lock::Save_Implementation(UHydeSaveGame* SaveGameInstance)
{
	if (!SaveGameInstance) return;

	// Create struct
	FActorSaveData LockSaveData;
	LockSaveData.Guid = GUID_Component->Guid;
	LockSaveData.ActorClass = GetClass();
	LockSaveData.Transform = GetTransform();

	// Serialize Actor specific variables
	FMemoryWriter Writer(LockSaveData.CustomActorData);
	SerializeActorData(Writer);

	// Save struct
	SaveGameInstance->ActorSaveDatas.Add(LockSaveData.Guid, LockSaveData);
}

void ACPP_Lock::Load_Implementation(const UHydeSaveGame* SaveGameInstance, const FGuid GUID)
{
	if (!SaveGameInstance || !SaveGameInstance->ActorSaveDatas.Contains(GUID)) return;

	// Load Struct
	const FActorSaveData& ThisLockSaveData = SaveGameInstance->ActorSaveDatas[GUID];
	SetActorTransform(ThisLockSaveData.Transform);

	// Deserialize Actor specific variables
	FMemoryReader Reader(ThisLockSaveData.CustomActorData);
	SerializeActorData(Reader);

	// TODO load unlocked pose if unlocked
	//if (!bIsLocked) Mesh->SetStaticMesh(OpenLockMesh);
	//else Mesh->SetStaticMesh(ClosedLockMesh);
}

void ACPP_Lock::SerializeActorData(FArchive& Ar)
{
	Ar << CurrentUserCombination;
	Ar << bIsLocked;
}

