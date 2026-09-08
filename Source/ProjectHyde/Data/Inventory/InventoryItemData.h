#pragma once

#include "InventoryItemData.generated.h"

class UNotebookItemData;

UCLASS(BlueprintType)
class PROJECTHYDE_API UInventoryItemData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
private:
	virtual void PostInitProperties() override;
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText Name = FText();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText Description = FText();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	bool bHasText = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item",meta = (EditCondition = "bHasText", EditConditionHides))
	TMap<FString,UTexture2D*> Text;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UTexture2D* Icon = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UStaticMesh* StaticMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UNotebookItemData* NotebookDataAsset = nullptr;
	
	UFUNCTION(BlueprintCallable, Category = "Item")
	UTexture2D* GetTextForCurrentCulture();
};
