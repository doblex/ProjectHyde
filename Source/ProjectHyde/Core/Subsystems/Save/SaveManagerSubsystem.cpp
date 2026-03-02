// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManagerSubsystem.h"

DEFINE_LOG_CATEGORY(SaveSubsystem);

void USaveManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	OnWriteCompleted.BindUObject(this, &USaveManagerSubsystem::HandleGameWriteCompleted);
	OnReadCompleted.BindUObject(this, &USaveManagerSubsystem::HandleGameReadCompleted);
}

void USaveManagerSubsystem::Deinitialize()
{
	OnWriteCompleted.Unbind();
	OnReadCompleted.Unbind();
}

void USaveManagerSubsystem::SaveGame(const FString& SaveSlotName, const int32 UserIndex)
{
	// Call delegate for save start
	OnSaveInitiated.Broadcast();

	SaveGameInstance = Cast<UHydeSaveGame>(UGameplayStatics::CreateSaveGameObject(UHydeSaveGame::StaticClass()));
	if (IsValid(SaveGameInstance))
	{
		UE_LOGFMT(SaveSubsystem, Display, "Requested Save...");

		// Find all actors to save
		TArray<AActor*> SaveableActors;
		UGameplayStatics::GetAllActorsWithInterface(
			GetWorld(),
			USaveable::StaticClass(),
			SaveableActors
		);

		for (AActor* Actor : SaveableActors)
		{

			ISaveable::Execute_Save(Actor, SaveGameInstance);
		}

		// Get Non-actor classes to save
		UCPP_EventFlagSubsystem* EventFlagManager = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UCPP_EventFlagSubsystem>();
		EventFlagManager->Save(SaveGameInstance);

		// Boilerplate save file header values
		SaveGameInstance->PlayerName = TEXT("Player");
		SaveGameInstance->SaveSlotName = SaveSlotName;
		SaveGameInstance->UserIndex = UserIndex;

		UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, SaveSlotName, UserIndex, OnWriteCompleted);
	}
}

void USaveManagerSubsystem::LoadGame(const FString& SaveSlotName, const int32 UserIndex)
{
	// Call delegate for load start
	OnLoadInitiated.Broadcast();

	UE_LOGFMT(SaveSubsystem, Display, "Requested Load...");
	UGameplayStatics::AsyncLoadGameFromSlot(SaveSlotName, 0, OnReadCompleted);
}

// Delegate that fires when async save is complete
void USaveManagerSubsystem::HandleGameWriteCompleted(const FString& SaveSlotName, const int32 UserIndex, const bool SaveSucceeded)
{
	if (SaveSucceeded)
	{
		UE_LOGFMT(SaveSubsystem, Display, "Saved game to slot {0}", SaveSlotName);

		// Call delegate for save end 
		OnSaveCompleted.Broadcast();
	}
	else 
		UE_LOGFMT(SaveSubsystem, Warning, "Could not save game!");
}

// Delegate that fires when async load is complete
void USaveManagerSubsystem::HandleGameReadCompleted(const FString& SaveSlotName, const int32 UserIndex, USaveGame* LoadedSaveFile)
{
	if (IsValid(LoadedSaveFile))
	{
		// Cast save file and load individual objects
		SaveGameInstance = Cast<UHydeSaveGame>(LoadedSaveFile);

		// Get Non-actor classes to load
		UCPP_EventFlagSubsystem* EventFlagManager = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UCPP_EventFlagSubsystem>();
		EventFlagManager->Load(SaveGameInstance);

		// Find all actors currently in scene
		TMap<FGuid, AActor*> WorldActorMap;
		TArray<AActor*> AllWorldActors;
		UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USaveable::StaticClass(), AllWorldActors);

		// Enumerate all actors in the world and test the save file against them
		for (AActor* Actor : AllWorldActors)
		{
			if (UCPP_SaveGameIdComponent* IDComp = Actor->FindComponentByClass<UCPP_SaveGameIdComponent>())
			{
				WorldActorMap.Add(IDComp->Guid, Actor);
			}
		}

		for (const TTuple<FGuid, FActorSaveData> SavedActorData : SaveGameInstance->ActorSaveDatas)
		{
			FGuid Guid = SavedActorData.Get<0>();
			FActorSaveData Data = SavedActorData.Get<1>();

			if (WorldActorMap.Contains(Guid))
			{
				// MATCH FOUND: Existing actor in scene
				AActor* ExistingActor = WorldActorMap[Guid];
				ISaveable::Execute_Load(ExistingActor, SaveGameInstance, Guid);
				WorldActorMap.Remove(Guid);
			}
			else
			{
				// NO MATCH: This actor was deleted and needs to be respawned
				FActorSpawnParameters SpawnParams;
				SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

				AActor* NewActor = GetWorld()->SpawnActor<AActor>(Data.ActorClass, Data.Transform, SpawnParams);
				if (NewActor)
				{
					// Manually set the GUID on the new actor so it matches the save
					if (UCPP_SaveGameIdComponent* NewIDComp = NewActor->FindComponentByClass<UCPP_SaveGameIdComponent>())
					{
						NewIDComp->Guid = Guid;
					}
					ISaveable::Execute_Load(NewActor, SaveGameInstance, Guid);
				}
			}
		}

		// Cleanup any actors left in WorldActorMap that were NOT in the save file
		for (auto& Elem : WorldActorMap)
		{
			Elem.Value->Destroy();
		}

		UE_LOGFMT(SaveSubsystem, Display, "Loaded game from slot {0}", SaveSlotName);

		// Call delegate for load start
		OnLoadCompleted.Broadcast();
	}
	else
		UE_LOGFMT(SaveSubsystem, Warning, "Could not load game!");
}
