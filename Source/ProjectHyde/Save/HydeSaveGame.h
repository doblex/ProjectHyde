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

	// LISTARE QUI OGNI VARIABILE CHE SI DESIDERA SALVARE
	// TODO valutare la separazione dei dati di salvataggio in Struct per ogni tipo di oggetto da salvare/caricare

	UPROPERTY(VisibleAnywhere, Category = "Event Flags")
	TMap<FGameplayTag, bool> EventFlagMap;
};
