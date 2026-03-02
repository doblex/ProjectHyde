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
};
