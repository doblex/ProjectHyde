// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "PlayerSettings.generated.h"

/**
 * 
 */
class UInventoryItemData;

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Player settings"))
class PROJECTHYDE_API UPlayerSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category = "Inventory settings")
	int InventorySlotNumber = 24;
	
	UPROPERTY(Config, EditAnywhere, Category = "Inventory settings")
	int HotBarSlotNumber = 6;
	
	UPROPERTY(Config, EditAnywhere, Category = "Inventory settings")
	TSoftObjectPtr<UDataTable> ItemCombinationTable;
	
	UPROPERTY(Config, EditAnywhere, Category = "Inventory settings")
	TArray<TSoftObjectPtr<UInventoryItemData>> DefaultItems;
};
