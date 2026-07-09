// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySubsystem.h"

#include "ProjectHyde/Core/DevSettings/PlayerSettings.h"
#include "ProjectHyde/Data/Inventory/InventoryCombinationDataRow.h"

void UInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	const UPlayerSettings* Settings = GetDefault<UPlayerSettings>();
	
	if (Settings == nullptr) return;

	InventorySlotNumber = Settings->InventorySlotNumber;
	HotBarSlotNumber = Settings->HotBarSlotNumber;
	ItemCombinationTable = Settings->ItemCombinationTable.LoadSynchronous();
	
	InventoryItemData.SetNum(InventorySlotNumber);
	
	for (TSoftObjectPtr<UInventoryItemData> Item : Settings->DefaultItems)
	{
		UInventoryItemData* itemToAdd = Item.LoadSynchronous();
		AddItemToInventory(itemToAdd);
	}
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
	for (UInventoryItemData*& Item : InventoryItemData)
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

bool UInventorySubsystem::SwapItems(int FromIndex, int ToIndex)
{
	InventoryItemData.Swap(FromIndex, ToIndex);
	return true;
}

bool UInventorySubsystem::TryCombineItems(int FirstItemIndex, int SecondItemIndex, UInventoryItemData*& OutItemCombined)
{
	OutItemCombined = nullptr;
	
	if (!IsValid(ItemCombinationTable))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.0f,
				FColor::Red,
				"ItemCombinationTable is not valid"
				);
		}
		
		return false;
	}
	
	UInventoryItemData* Firstitem = InventoryItemData[FirstItemIndex];
	UInventoryItemData* Seconditem = InventoryItemData[SecondItemIndex];
	
	TSet<UInventoryItemData*> Items;
	Items.Add(Firstitem);
	Items.Add(Seconditem);
	
	const FString ContextString(TEXT("Context"));
	TArray<FInventoryCombinationDataRow*> ItemCombinationDataRows; 
	
	ItemCombinationTable->GetAllRows<FInventoryCombinationDataRow>(ContextString, ItemCombinationDataRows);

	for (FInventoryCombinationDataRow* Row : ItemCombinationDataRows)
	{
		if (Row->Equal(Items))
		{
			InventoryItemData[FirstItemIndex] = nullptr;
			InventoryItemData[SecondItemIndex] = Row->Result.LoadSynchronous();
			OutItemCombined = Row->Result.LoadSynchronous();
			return true;
		}
	}
	
	return false;
}

void UInventorySubsystem::ResetInventory()
{
	for (int i = 0; i < InventorySlotNumber; ++i)
	{
		InventoryItemData[i] = nullptr;
	}

	const UPlayerSettings* Settings = GetDefault<UPlayerSettings>();

	if (Settings == nullptr) return;

	InventorySlotNumber = Settings->InventorySlotNumber;
	HotBarSlotNumber = Settings->HotBarSlotNumber;
	ItemCombinationTable = Settings->ItemCombinationTable.LoadSynchronous();

	InventoryItemData.SetNum(InventorySlotNumber);

	for (TSoftObjectPtr<UInventoryItemData> Item : Settings->DefaultItems)
	{
		UInventoryItemData* itemToAdd = Item.LoadSynchronous();
		AddItemToInventory(itemToAdd);
	}
}
