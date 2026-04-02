// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySubsystem.h"

void UInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	InventoryItemData.SetNum(InventorySlotNumber);
}

void UInventorySubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UInventorySubsystem::GetInventoryElements(TArray<UInventoryItemData*>& OutInventoryItemData)
{
	OutInventoryItemData = InventoryItemData;
}

void UInventorySubsystem::GetHotBarItems(TArray<UInventoryItemData*>& OutHotBarItemData)
{
	for (int i = 0; i < HotBarSlotNumber; i++)
	{
		OutHotBarItemData.Add(InventoryItemData[i]);
	}
}

bool UInventorySubsystem::AddItemToInventory(UInventoryItemData* ItemDataToAdd)
{
	for (UInventoryItemData* Item : InventoryItemData)
	{
		if(Item == nullptr)
		{
			Item = ItemDataToAdd;
			return true;
		}
	}
	
	return false;
}

bool UInventorySubsystem::RemoveItemFromInventory(UInventoryItemData* ItemDataToRemove)
{
	for (int i = 0; i < InventorySlotNumber; ++i)
	{
		if (InventoryItemData[i] == ItemDataToRemove)
		{
			InventoryItemData[i] = nullptr;
			return true;
		}
	}
	
	return false;
}
