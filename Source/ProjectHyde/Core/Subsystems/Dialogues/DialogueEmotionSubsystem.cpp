// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueEmotionSubsystem.h"

#include "ProjectHyde/Core/DevSettings/DialogueSubsystemSettings.h"
#include "ProjectHyde/Data/Sound/CharacterDataRow.h"

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
	
	TArray<FCharacterDataRow*> CharactersData;
	const FString ContextString(TEXT("Context"));
	
	CharacterEmotionSoundTable->GetAllRows(ContextString,CharactersData);
	
	if (CharactersData.IsEmpty()) return false;

	for (FCharacterDataRow* Row : CharactersData)
	{
		if (Row->Character == CharacterName)
		{
			return Row->GetEmotion(EmotionToGet, OutSoundAsset);
		}
	}
	
	return false;
}
