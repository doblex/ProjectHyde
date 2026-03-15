#pragma once

#include "../Data/NotebookItemData.h" 
#include "InventoryItemData.generated.h"


UCLASS(BlueprintType)
class PROJECTHYDE_API UInventoryItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName Name = FName();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText Description = FText();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UTexture2D* Icon = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UStaticMesh* StaticMesh = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	bool bCanCombine = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UInventoryItemData* CombineWith = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UInventoryItemData* ResultItem = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UNotebookItemData* NotebookDataAsset = nullptr;
};
