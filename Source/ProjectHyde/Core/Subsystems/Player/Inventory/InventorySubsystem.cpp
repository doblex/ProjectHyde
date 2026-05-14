// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySubsystem.h"

#include "ProjectHyde/Core/DevSettings/PlayerSettings.h"
#include "ProjectHyde/Data/Inventory/InventoryCombinationDataRow.h"

void UInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	const UPlayerSettings* Settings = GetDefault<UPlayerSettings>();
	
	if (Settings)
	{
		InventorySlotNumber = Settings->InventorySlotNumber;
		HotBarSlotNumber = Settings->HotBarSlotNumber;
		ItemCombinationTable = Settings->ItemCombinationTable.Get();
	}
	
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
	
	const FString ContextString(TEXT("Context"));
	TArray<FInventoryCombinationDataRow*> ItemCombinationDataRows; 
	
	ItemCombinationTable->GetAllRows<FInventoryCombinationDataRow>(ContextString, ItemCombinationDataRows);

	for (FInventoryCombinationDataRow* Row : ItemCombinationDataRows)
	{
		if (Row->Equal(Firstitem, Seconditem))
		{
			InventoryItemData[FirstItemIndex] = nullptr;
			InventoryItemData[SecondItemIndex] = Row->Result.Get();
			OutItemCombined = Row->Result.Get();
			return true;
		}
	}
	
	return false;
}
