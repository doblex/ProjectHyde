// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_PlayerCharacter.h"
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
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get App Version"), Category = "Game Config")
	static FString GetAppVersion();
	
	template<typename TComponent>
	static bool GetComponentFromPlayer(UObject* WorldContext  , TComponent*& OutComponent)
	{
		OutComponent = nullptr;
		
		if (!WorldContext) return false;

		const UWorld* World = WorldContext->GetWorld();
		
		if (!World) return false;
		
		APlayerController* PC = World->GetFirstPlayerController();
		
		if (!PC) return false;
		
		ACharacter* Character = PC->GetCharacter();
		
		if (!Character) return false;
		
		UActorComponent* Component = Character->GetComponentByClass<TComponent>();
		
		if (!Component) return false;
		
		OutComponent = Cast<TComponent>(Component);;
		return true;
	}
	
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
	
	template<typename T>
static FString EnumToString(T Value)
	{
		return StaticEnum<T>()->GetNameStringByValue((int64)Value);
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
