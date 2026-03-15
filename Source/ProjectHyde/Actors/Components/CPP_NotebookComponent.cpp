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
	
	PuzzleNumber = PuzzleEntries.Num();
}


// Called every frame
void UCPP_NotebookComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Add the given DataAsset as a Bookmark for the player
void UCPP_NotebookComponent::AddBookmark(UNotebookItemData* NewData)
{
	if (!NewData) return;

	// Check if we already have an entry for this asset (lambda expression)
	bool bAlreadyExists = UnlockedBookmarks.ContainsByPredicate([NewData](const FBookmarkEntry& Entry) {
		return Entry.StaticData == NewData;
	});

	if (!bAlreadyExists)
	{
		// Caso bookmark nuovo (TODO Aggiungi UI)
		FBookmarkEntry NewEntry;
		NewEntry.StaticData = NewData;
		NewEntry.AssetPath = FSoftObjectPath(NewData);
		NewEntry.PlayerNotes = FText::FromString(""); // start empty
		UnlockedBookmarks.Add(NewEntry);
		BookmarkNumber = UnlockedBookmarks.Num();
		UE_LOGFMT(LogTemp, Display, "Added new Bookmark to Notebook!");
	}
	else
	{
		// caso bookmark esistente (TODO Aggiungi UI)
		UE_LOGFMT(LogTemp, Display, "Bookmark already present in Notebook!");
	}
}

// Trova la UNotebookItemData della persona interessata (Match del campo "Title" del DataAsset) 
// Da chiamare per aggiungerci dialoghi con AddDialogueToBookmark
UNotebookItemData* UCPP_NotebookComponent::FindNotebookItemFor(FString PersonName)
{
	for (FBookmarkEntry& Entry : UnlockedBookmarks)
	{
		if (Entry.StaticData->Title == PersonName)
		{
			return Entry.StaticData;
		}
	}

	return nullptr;
}

// Update dialogues for People bookmarks, call this when the player is done writing (Save note from UI)
void UCPP_NotebookComponent::AddDialogueEntryToBookmark(UNotebookItemData* ForData, FDialogueEntry DialogueEntryToAdd)
{
	for (FBookmarkEntry& Entry : UnlockedBookmarks)
	{
		if (Entry.StaticData == ForData)
		{
			Entry.DialogueEntries.Add(DialogueEntryToAdd);
			return;
		}
	}
}

// Update player notes, call this when the player is done writing (Save note from UI)
void UCPP_NotebookComponent::UpdatePlayerNote(UNotebookItemData* ForData, FText NewNote)
{
	for (FBookmarkEntry& Entry : UnlockedBookmarks)
	{
		if (Entry.StaticData == ForData)
		{
			Entry.PlayerNotes = NewNote;
			return;
		}
	}
}

// Returns all the bookmarks in the player's possesion of type "Person"
TArray<FBookmarkEntry> UCPP_NotebookComponent::GetPeopleBookmarksFromPlayer()
{
	TArray<FBookmarkEntry> Output;
	for (FBookmarkEntry Bookmark : UnlockedBookmarks)
	{
		if (Bookmark.StaticData->NotebookItemType == ENotebookItemType::Person) Output.Add(Bookmark);
	}
	return Output;
}

// Returns all the bookmarks i nthe player's possession fo type "Not Person"
TArray<FBookmarkEntry> UCPP_NotebookComponent::GetOtherBookmarksFromPlayer()
{
	TArray<FBookmarkEntry> Output;
	for (FBookmarkEntry Bookmark : UnlockedBookmarks)
	{
		if (Bookmark.StaticData->NotebookItemType != ENotebookItemType::Person) Output.Add(Bookmark);
	}
	return Output;
}

// Sets the User submitted culprit for puzzle at the given index
void UCPP_NotebookComponent::SetUserCulpritForIndex(int index, FBookmarkEntry NewUserCulprit)
{
	if (PuzzleEntries[index].bSolved) return;
	PuzzleEntries[index].UserCulprit = NewUserCulprit.StaticData;
}

// Sets the User submitted weapon for puzzle at the given index
void UCPP_NotebookComponent::SetUserWeaponForIndex(int index, FBookmarkEntry NewUserWeapon)
{
	if (PuzzleEntries[index].bSolved) return;
	PuzzleEntries[index].UserWeapon = NewUserWeapon.StaticData;
}

// Sets the User submitted culprit for puzzle at the given index
void UCPP_NotebookComponent::SetUserMotiveForIndex(int index, FBookmarkEntry NewUserMotive)
{
	if (PuzzleEntries[index].bSolved) return;
	PuzzleEntries[index].UserMotive = NewUserMotive.StaticData;
}

// Returns true if the currently submitted User solution matches the correct solution of puzzle at the given index
bool UCPP_NotebookComponent::CheckNotebookSolution(int index)
{
	FNotebookPuzzleItem& Entry = PuzzleEntries[index];
	if (
		// Compare asset paths to determine correctness
		FSoftObjectPath(Entry.CorrectCulprit) == FSoftObjectPath(Entry.UserCulprit)&&
		FSoftObjectPath(Entry.CorrectWeapon) == FSoftObjectPath(Entry.UserWeapon) &&
		FSoftObjectPath(Entry.CorrectMotive) == FSoftObjectPath(Entry.UserMotive)
	){
		Entry.bSolved = true;
		return true;
	}
	else
	{
		return false;
	}
}

void UCPP_NotebookComponent::SaveNotebookComponentData(FActorSaveData* SaveGameData)
{
	// Serialize Component specific variables
	FMemoryWriter Writer(SaveGameData->CustomActorData);
	Writer << BookmarkNumber;
	for (FBookmarkEntry Bookmark : UnlockedBookmarks) {
		Writer << Bookmark.AssetPath;
		Writer << Bookmark.DialogueEntries;
		Writer << Bookmark.PlayerNotes;
	}
	Writer << PuzzleNumber;
	for (FNotebookPuzzleItem PuzzleEntry : PuzzleEntries) {
		Writer << PuzzleEntry.bSolved;

		Writer << PuzzleEntry.CorrectCulprit;
		Writer << PuzzleEntry.CorrectWeapon;
		Writer << PuzzleEntry.CorrectMotive;

		Writer << PuzzleEntry.UserCulprit;
		Writer << PuzzleEntry.UserWeapon;
		Writer << PuzzleEntry.UserMotive;
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
		Reader << LoadedEntry.DialogueEntries;
		Reader << LoadedEntry.PlayerNotes;
		LoadedEntry.StaticData = Cast<UNotebookItemData>(LoadedEntry.AssetPath.TryLoad());
		UnlockedBookmarks.Add(LoadedEntry);
	}
	Reader << PuzzleNumber;
	for (int i = 0; i < PuzzleNumber; i++) {
		FNotebookPuzzleItem LoadedEntry;
		Reader << LoadedEntry.bSolved;
				  
		Reader << LoadedEntry.CorrectCulprit;
		Reader << LoadedEntry.CorrectWeapon;
		Reader << LoadedEntry.CorrectMotive;
				  
		Reader << LoadedEntry.UserCulprit;
		Reader << LoadedEntry.UserWeapon;
		Reader << LoadedEntry.UserMotive;
	}
}

