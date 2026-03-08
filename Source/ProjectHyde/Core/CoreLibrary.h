// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UCoreLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	template<typename TEnum>
static TEnum GetEnumFromString(const FString& String, TEnum DefaultValue)
	{
		static_assert(TIsEnum<TEnum>::Value, "TEnum must be an enum type");

		UEnum* EnumPtr = StaticEnum<TEnum>();
		if (!EnumPtr)
		{
			return DefaultValue;
		}

		int64 Value = EnumPtr->GetValueByNameString(String);

		return (Value != INDEX_NONE)
			? static_cast<TEnum>(Value)
			: DefaultValue;
	}
	
	template<typename TEnum, typename TObject>
	static void SyncMap(TMap<TEnum, TObject> &Map)
	{
		UEnum* EnumPtr = StaticEnum<TEnum>();
		if (!EnumPtr) return;

		TSet<TEnum> ValidKeys;

		// Add missing keys
		for (int32 i = 0; i < EnumPtr->NumEnums() - 1; ++i) // skip MAX
		{
			TEnum Value =
				static_cast<TEnum>(EnumPtr->GetValueByIndex(i));

			ValidKeys.Add(Value);

			if (!Map.Contains(Value))
			{
				Map.Add(Value, nullptr);
			}
		}

		// Remove stale keys (if enum value was deleted)
		for (auto It = Map.CreateIterator(); It; ++It)
		{
			if (!ValidKeys.Contains(It.Key()))
			{
				It.RemoveCurrent();
			}
		}
	}
};
