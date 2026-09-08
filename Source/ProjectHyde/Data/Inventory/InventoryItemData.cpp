
#include "InventoryItemData.h"

#include "Internationalization/Culture.h"

void UInventoryItemData::PostInitProperties()
{
	Super::PostInitProperties();
	
	TArray<FString> currentCultures =	
		FTextLocalizationManager::Get().GetLocalizedCultureNames(ELocalizationLoadFlags::Game);
	
	for (auto CurrentCulture : currentCultures)
	{
		if (!Text.Contains(CurrentCulture))
		{
			Text.Add(CurrentCulture, nullptr);
		}
	}
}

UTexture2D* UInventoryItemData::GetTextForCurrentCulture()
{
	FString currentCulture = FInternationalization::Get().GetCurrentLanguage()->GetName();
	return Text[currentCulture];
}
