// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_NotebookComponent.h"

// Sets default values for this component's properties
UCPP_NotebookComponent::UCPP_NotebookComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCPP_NotebookComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCPP_NotebookComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCPP_NotebookComponent::AddBookmark(UNotebookItemData* NewData)
{
	if (!NewData) return;

	// Check if we already have an entry for this asset (lambda expression)
	bool bAlreadyExists = UnlockedBookmarks.ContainsByPredicate([NewData](const FBookmarkEntry& Entry) {
		return Entry.StaticData == NewData;
	});

	if (!bAlreadyExists)
	{
		// Caso bookmark nuovo
		FBookmarkEntry NewEntry;
		NewEntry.StaticData = NewData;
		NewEntry.AssetPath = FSoftObjectPath(NewData);
		NewEntry.PlayerNotes = TEXT(""); // start empty
		UnlockedBookmarks.Add(NewEntry);
		BookmarkNumber = UnlockedBookmarks.Num();
	}
	else
	{
		// caso bookmark esistente
	}
}

void UCPP_NotebookComponent::UpdatePlayerNote(UNotebookItemData* ForData, FString NewNote)
{
	// Update player notes, call this when the player is done writing (Save note from UI)
	for (FBookmarkEntry& Entry : UnlockedBookmarks)
	{
		if (Entry.StaticData == ForData)
		{
			Entry.PlayerNotes = NewNote;
			break;
		}
	}
}

void UCPP_NotebookComponent::SaveNotebookComponentData(FActorSaveData* SaveGameData)
{
	// Serialize Component specific variables
	FMemoryWriter Writer(SaveGameData->CustomActorData);
	Writer << BookmarkNumber;
	for (FBookmarkEntry Bookmark : UnlockedBookmarks) {
		Writer << Bookmark.AssetPath;
		Writer << Bookmark.PlayerNotes;
	}
}

void UCPP_NotebookComponent::LoadNotebookComponentData(FActorSaveData* SaveGameData)
{
	// Deserialize Component specific variables
	FMemoryWriter Reader(SaveGameData->CustomActorData);
	Reader << BookmarkNumber;
	for (int i = 0; i < BookmarkNumber; i++) {
		FBookmarkEntry LoadedEntry;
		Reader << LoadedEntry.AssetPath;
		Reader << LoadedEntry.PlayerNotes;
		LoadedEntry.StaticData = Cast<UNotebookItemData>(LoadedEntry.AssetPath.TryLoad());
		UnlockedBookmarks.Add(LoadedEntry);
	}
}

