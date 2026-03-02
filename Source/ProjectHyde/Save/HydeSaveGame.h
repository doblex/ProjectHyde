// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "NativeGameplayTags.h"

#include "HydeSaveGame.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FActorSaveData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<AActor> ActorClass;

	UPROPERTY()
	FGuid Guid;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	TArray<uint8> CustomActorData;
};

// Classe che definisce il salvataggio
UCLASS()
class PROJECTHYDE_API UHydeSaveGame : public USaveGame
{
	GENERATED_BODY()
	

public:
	// Unreal USaveGame default variables
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;

	// LISTARE QUI OGNI VARIABILE/STRUCT CHE SI DESIDERA SALVARE

	UPROPERTY(VisibleAnywhere, Category = "Event Flags")
	TMap<FGameplayTag, bool> EventFlagMap;

	// Lista di attori salvati
	UPROPERTY(VisibleAnywhere, Category = "Actors")
	TMap<FGuid, FActorSaveData> ActorSaveDatas;
};
