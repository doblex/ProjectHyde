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

		// Find all actors to save
		TArray<AActor*> SaveableActors;
		UGameplayStatics::GetAllActorsWithInterface(
			GetWorld()->GetFirstPlayerController(),
			USaveable::StaticClass(),
			SaveableActors
		);

		for (AActor* Actor : SaveableActors)
		{
			ISaveable::Execute_Save(Actor, SaveGameInstance);
		}

		// Get Non-actor classes to save
		UCPP_EventFlagSubsystem* EventFlagManagerRef = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UCPP_EventFlagSubsystem>();
		if (EventFlagManagerRef->GetClass()->ImplementsInterface(USaveable::StaticClass())) ISaveable::Execute_Save(EventFlagManagerRef, SaveGameInstance);
		else UE_LOGFMT(SaveSubsystem, Error, "FATAL: EventFlagSubsystem does NOT implement ISaveable!");

		// Boilerplate save file header values
		SaveGameInstance->PlayerName = TEXT("Player");
		SaveGameInstance->SaveSlotName = SaveSlotName;
		SaveGameInstance->UserIndex = UserIndex;

		UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, SaveSlotName, UserIndex, OnSaveCompleted);
	}
}

void USaveManagerSubsystem::LoadGame(const FString& SaveSlotName, const int32 UserIndex)
{
	UE_LOGFMT(SaveSubsystem, Display, "Requested Load...");
	UGameplayStatics::AsyncLoadGameFromSlot(SaveSlotName, 0, OnLoadCompleted);
}

// Delegate that fires when async save is complete
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

// Delegate that fires when async load is complete
void USaveManagerSubsystem::HandleGameLoadCompleted(const FString& SaveSlotName, const int32 UserIndex, USaveGame* LoadedSaveFile)
{
	if (IsValid(LoadedSaveFile))
	{
		// Cast save file and load individual objects
		SaveGameInstance = Cast<UHydeSaveGame>(LoadedSaveFile);

		// Get Non-actor classes to load
		UCPP_EventFlagSubsystem* EventFlagManagerRef = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UCPP_EventFlagSubsystem>();
		if (EventFlagManagerRef->GetClass()->ImplementsInterface(USaveable::StaticClass()))  ISaveable::Execute_Load(EventFlagManagerRef, SaveGameInstance);
		else UE_LOGFMT(SaveSubsystem, Error, "FATAL: EventFlagSubsystem does NOT implement ISaveable!");

		// Find all actors to load
		TArray<AActor*> ActorsToLoad;
		UGameplayStatics::GetAllActorsWithInterface(
			GetWorld()->GetFirstPlayerController(),
			USaveable::StaticClass(),
			ActorsToLoad
		);

		for (AActor* Actor : ActorsToLoad)
		{
			ISaveable::Execute_Load(Actor, SaveGameInstance);
		}

		UE_LOGFMT(SaveSubsystem, Display, "Loaded game from slot {0}", SaveSlotName);
	}
	else
	{
		UE_LOGFMT(SaveSubsystem, Warning, "Could not load game!");
	}
}
