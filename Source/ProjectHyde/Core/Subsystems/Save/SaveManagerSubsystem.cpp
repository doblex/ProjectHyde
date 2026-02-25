// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManagerSubsystem.h"

DEFINE_LOG_CATEGORY(SaveSubsystem);

void USaveManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	OnSaveCompleted.BindUObject(this, &USaveManagerSubsystem::HandleGameSaveCompleted);
	OnLoadCompleted.BindUObject(this, &USaveManagerSubsystem::HandleGameLoadCompleted);
}

void USaveManagerSubsystem::Deinitialize()
{
	OnSaveCompleted.Unbind();
	OnLoadCompleted.Unbind();
}

void USaveManagerSubsystem::SaveGame(const FString& SaveSlotName, const int32 UserIndex)
{
	SaveGameInstance = Cast<UHydeSaveGame>(UGameplayStatics::CreateSaveGameObject(UHydeSaveGame::StaticClass()));
	if (IsValid(SaveGameInstance))
	{
		UE_LOGFMT(SaveSubsystem, Display, "Requested Save...");

		// Find al actors to save
		TArray<AActor*> SaveableActors;
		UGameplayStatics::GetAllActorsWithInterface(
			GetWorld()->GetFirstPlayerController(),
			USaveable::StaticClass(),
			SaveableActors
		);

		for (AActor* Actor : SaveableActors)
		{
			Cast<ISaveable>(Actor)->Save(SaveGameInstance);
		}

		// Get Non-actor classes to save
		UCPP_EventFlagSubsystem* EventFlagManagerRef = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UCPP_EventFlagSubsystem>();

		SaveGameInstance->PlayerName = TEXT("Player");
		SaveGameInstance->SaveSlotName = SaveSlotName;
		SaveGameInstance->UserIndex = UserIndex;
		SaveGameInstance->EventFlagMap = EventFlagManagerRef->EventFlagMap;

		UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, SaveSlotName, UserIndex, OnSaveCompleted);
	}
}

void USaveManagerSubsystem::LoadGame(const FString& SaveSlotName, const int32 UserIndex)
{
	// TODO load save file
}

void USaveManagerSubsystem::HandleGameSaveCompleted(const FString& SaveSlotName, const int32 UserIndex, bool SaveSucceeded)
{
	if (SaveSucceeded)
	{
		UE_LOGFMT(SaveSubsystem, Display, "Saved game to slot {0}", SaveSlotName);
	}
	else 
	{
		UE_LOGFMT(SaveSubsystem, Warning, "Could not save game!");
	}
}

void USaveManagerSubsystem::HandleGameLoadCompleted(const FString& SaveSlotName, const int32 UserIndex, USaveGame* LoadedSaveFile)
{
	if (IsValid(LoadedSaveFile))
	{
		UE_LOGFMT(SaveSubsystem, Display, "Loaded game from slot {0}", SaveSlotName);
	}
	else
	{
		UE_LOGFMT(SaveSubsystem, Warning, "Could not load game!");
	}
}
