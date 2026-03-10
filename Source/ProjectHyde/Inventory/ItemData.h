#pragma once

#include "ItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()
	
	FItemData()
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName Name = FName();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UTexture2D* Icon = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UStaticMesh* StaticMesh = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	bool bCanCombine = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName CombineWith = NAME_None;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ResultItem = NAME_None;
};
