// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueEmotionSubsystem.h"

#include "ProjectHyde/Core/DevSettings/DialogueSubsystemSettings.h"
#include "ProjectHyde/Data/Sound/CharacterEmotionSoundDataRow.h"

void UDialogueEmotionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	const UDialogueSubsystemSettings* Settings = GetDefault<UDialogueSubsystemSettings>();
	
	if (Settings)
	{
		CharacterEmotionSoundTable = Settings->DialogueEmotionTable.Get();
	}
}

void UDialogueEmotionSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UDialogueEmotionSubsystem::GetEmotionSound(FName CharacterName, ELineEmotion EmotionToGet, USoundBase*& OutSoundAsset)
{
	OutSoundAsset = nullptr;
	if (!CharacterEmotionSoundTable) return false;
	
	TArray<FCharacterEmotionSoundDataRow*> CharacterEmotions;
	const FString ContextString(TEXT("Context"));
	
	CharacterEmotionSoundTable->GetAllRows(ContextString,CharacterEmotions);
	
	if (CharacterEmotions.IsEmpty()) return false;

	for (FCharacterEmotionSoundDataRow* Row : CharacterEmotions)
	{
		if (Row->Character == CharacterName && Row->EmotionType == EmotionToGet)
		{
			OutSoundAsset = Row->SoundAsset;
			
			return OutSoundAsset != nullptr;
		}
	}
	
	return false;
}
