// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCombinationDataRow.h"

#include "Misc/DataValidation.h"

bool FInventoryCombinationDataRow::Equal(UInventoryItemData* Itm1, UInventoryItemData* Itm2)
{
	bool bResult =
		(Item1 == Itm1 && Item2 == Itm2) ||
			(Item1 == Itm1 && Item2 == Itm1);
	
	return bResult;
}

// #if WITH_EDITOR
// EDataValidationResult FInventoryCombinationDataRow::IsDataValid(FDataValidationContext& Context) const
// {
// 	EDataValidationResult ValResult = FTableRowBase::IsDataValid(Context);
// 		
// 	if (Item1.IsNull() || Item2.IsNull() || Result.IsNull())
// 	{
// 		const FText Error = FText::FromString("Items or result cannot be null");
// 		Context.AddError(Error);
// 		ValResult = EDataValidationResult::Invalid;
// 	}
// 	
// 	if (Item1.Get() == Item2.Get() || Item2.Get() == Result.Get() || Item1.Get() == Result.Get())
// 	{
// 		const FText Error = FText::FromString("Items or result cannot be the same on a row");
// 		Context.AddError(Error);
// 		ValResult = EDataValidationResult::Invalid;
// 	}
// 	
// 	return ValResult;
// }
// #endif

