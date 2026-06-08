// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterDataRow.h"

bool FCharacterDataRow::GetEmotion(ELineEmotion EmotionToSearch, USoundBase*& OutResult)
{
	OutResult = nullptr;

	for (auto EmotionSound : EmotionSounds)
	{
		if (EmotionSound.EmotionType == EmotionToSearch)
		{
			if (EmotionSound.SoundAsset != nullptr)
			{
				OutResult = EmotionSound.SoundAsset;
				return true;
			}
		}
	}
	
	return false;
}

#ifdef IF_WITH_EDITOR
void FCharacterDataRow::OnDataTableChanged(const UDataTable* InDataTable, const FName InRowName)
{
	FTableRowBase::OnDataTableChanged(InDataTable, InRowName);
	
	SyncArray();
}
#endif

void FCharacterDataRow::SyncArray()
{
	UEnum* EnumPtr = StaticEnum<ELineEmotion>();
	if (!EnumPtr) return;

	TSet<ELineEmotion> ValidKeys;

	// Add missing keys
	for (int32 i = 0; i < EnumPtr->NumEnums() - 1; ++i) // skip MAX
	{
		ELineEmotion Value =
			static_cast<ELineEmotion>(EnumPtr->GetValueByIndex(i));

		ValidKeys.Add(Value);

		bool bIsPresent = false;
		for (auto ValidKey : EmotionSounds)
		{
			if (ValidKey.EmotionType == Value)
			{
				bIsPresent = true;
				break;
			}
		}
		
		if (!bIsPresent)
		{
			FEmotionSound newEmotion(Value, nullptr);
			EmotionSounds.Add(newEmotion);
		}
	}

	// Remove stale keys (if enum value was deleted)
	for (int i = 0; i < EmotionSounds.Num(); ++i)
	{
		if (!ValidKeys.Contains(EmotionSounds[i].EmotionType))
		{
			EmotionSounds.RemoveAt(i);
			i--;
		}
	}
}

