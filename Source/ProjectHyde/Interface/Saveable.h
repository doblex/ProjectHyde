// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Serialization/Archive.h"
#include "Saveable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USaveable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTHYDE_API ISaveable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Save System")
	void Save(UHydeSaveGame* SaveGameInstance);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Save System")
	void Load(const UHydeSaveGame* SaveGameInstance, const FGuid GUID);

	// Serialize data to a binary object or deserialize data from a binary object (FArchive can do either if an FWriter or FReader is passed)
	void SerializeActorData(FArchive& Ar);
};
