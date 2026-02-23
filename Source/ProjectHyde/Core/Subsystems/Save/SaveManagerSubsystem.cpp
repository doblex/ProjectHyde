// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManagerSubsystem.h"

void USaveManagerSubsystem::SaveGame(const FString SaveSlotName, const int32 UserIndex)
{
	SaveGameInstance = Cast<UHydeSaveGame>(UGameplayStatics::CreateSaveGameObject(UHydeSaveGame::StaticClass()));
	if (IsValid(SaveGameInstance))
	{
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

		UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, SaveSlotName, UserIndex); // TODO add delegate
	}
}

void USaveManagerSubsystem::LoadGame(const FString SaveSlotName, const int32 UserIndex)
{
	
}
