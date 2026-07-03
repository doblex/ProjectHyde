// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHyde/Data/Inventory/InventoryItemData.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "InventorySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UInventorySubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
private:
	TArray<UInventoryItemData*> InventoryItemData;
	
	UPROPERTY()
	UDataTable* ItemCombinationTable;
	
	int InventorySlotNumber = 24;
	int HotBarSlotNumber = 6;
	
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
public:
	//Getters
	
	//Get the number of slot for inventory and the hotbar
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetInventoryDimension() {return InventorySlotNumber;}
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetHotBarDimension() {return HotBarSlotNumber;}
	
	//Get all the items in the inventory
	UFUNCTION(BlueprintCallable)
	void GetInventoryElements(TArray<UInventoryItemData*>& OutInventoryItemData);
	
	//Get only the items to show in the HotBar
	UFUNCTION(BlueprintCallable)
	void GetHotBarItems(TArray<UInventoryItemData*>& OutHotBarItemData);
	
	//InventoryManaging
	
	/// Add an item to the inventory
	/// @param ItemDataToAdd Item to add
	/// @return Return true if added, false otherwise
	UFUNCTION(BlueprintCallable)
	bool AddItemToInventory(UInventoryItemData* ItemDataToAdd);

	/// Remove an item from the inventory
	/// @param ItemDataToRemove Item to remove
	/// @return Return true if removed, false otherwise
	UFUNCTION(BlueprintCallable)
	bool RemoveItemFromInventory(UInventoryItemData* ItemDataToRemove);
	
	/// Called when an update on position happened
	/// @param FromIndex Index of the object to swap
	/// @param ToIndex Index of the target slot
	/// @return Return true if succes, false otherwise
	UFUNCTION(BlueprintCallable)
	bool SwapItems(int FromIndex, int ToIndex);
	
	/// Called when trying to Combine two items, if the combined item exist it substitute 
	/// the Second item
	/// @param FirstItemIndex Index of the first item (the one dragged)
	/// @param SecondItemIndex Index of the second item (the one dropped on)
	/// @return Return true if succes, false otherwise
	UFUNCTION(BlueprintCallable)
	bool TryCombineItems(int FirstItemIndex, int SecondItemIndex, UInventoryItemData*& OutItemCombined);
};
