#pragma once

#include "InventoryItemData.generated.h"

class UNotebookItemData;

UCLASS(BlueprintType)
class PROJECTHYDE_API UInventoryItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName Name = FName();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText Description = FText();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	bool bHasText = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	FText Text = FText::GetEmpty();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UTexture2D* Icon = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UStaticMesh* StaticMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UNotebookItemData* NotebookDataAsset = nullptr;
};
