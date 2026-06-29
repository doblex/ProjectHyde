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

bool UCPP_NotebookComponent::IsAlreadyNoted(UNotebookItemData* Data)
{
	// Check by predicate with lambda expression to see if bookmark is already saved
	return UnlockedBookmarks.ContainsByPredicate(
		[Data](const FBookmarkEntry& Entry) {
			return Entry.StaticData == Data;
		}
	);
}

// Add the given DataAsset as a Bookmark for the player
EBookmarkPresence UCPP_NotebookComponent::AddBookmark(UNotebookItemData* NewData)
{
	if (!NewData) return EBookmarkPresence::None;

	// Check if we already have an entry for this asset (lambda expression)
	bool bAlreadyExists = IsAlreadyNoted(NewData);

	if (!bAlreadyExists)
	{
		// Caso bookmark nuovo
		FBookmarkEntry NewEntry;
		NewEntry.StaticData = NewData;
		NewEntry.AssetPath = FSoftObjectPath(NewData);
		NewEntry.PlayerNotes = FText::FromString(""); // start empty
		if (TemporaryDialogueStore.Contains(NewData))
		{
			NewEntry.DialogueEntries = TemporaryDialogueStore[NewData].TempDialogueEntries; // load temporary saved dialogue
			TemporaryDialogueStore.Remove(NewData);
		}
		UnlockedBookmarks.Add(NewEntry);
		BookmarkNumber = UnlockedBookmarks.Num();
		OnBookmarksReloaded.Broadcast();
		UE_LOGFMT(LogTemp, Display, "Added new Bookmark to Notebook!");
	}
	else
	{
		// caso bookmark esistente
		UE_LOGFMT(LogTemp, Display, "Bookmark already present in Notebook!");
	}
	
	return bAlreadyExists ? EBookmarkPresence::AlreadyPresent : EBookmarkPresence::New;
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
	// Check if bookmark is unlocked
	for (FBookmarkEntry& Entry : UnlockedBookmarks)
	{
		if (Entry.StaticData == ForData)
		{
			Entry.DialogueEntries.Add(DialogueEntryToAdd);
			return;
		}
	}
	// Case bookmark not unlocked, add to TempDialogueStore
	if (TemporaryDialogueStore.Contains(ForData))
		TemporaryDialogueStore[ForData].TempDialogueEntries.Add(DialogueEntryToAdd);
	else
	{
		FTempDialogues TempDialogues;
		TempDialogues.TempDialogueEntries.Add(DialogueEntryToAdd);
		TemporaryDialogueStore.Add(ForData, TempDialogues);
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

// Returns all the bookmarks in the player's possession of type "Not Person"
TArray<FBookmarkEntry> UCPP_NotebookComponent::GetOtherBookmarksFromPlayer()
{
	TArray<FBookmarkEntry> Output;
	for (FBookmarkEntry Bookmark : UnlockedBookmarks)
	{
		if (Bookmark.StaticData->NotebookItemType != ENotebookItemType::Person) Output.Add(Bookmark);
	}
	return Output;
}

// Returns all the bookmarks in the player's possession
TArray<FBookmarkEntry> UCPP_NotebookComponent::GetAllBookmarksFromPlayer()
{
	TArray<FBookmarkEntry> Output;

	for (FBookmarkEntry Bookmark : UnlockedBookmarks)	Output.Add(Bookmark);

	return Output;
}

TArray<FNotebookPuzzleItem> UCPP_NotebookComponent::GetAllSolvedPuzzles()
{
	TArray<FNotebookPuzzleItem> Result;
	
	for (FNotebookPuzzleItem PuzzleEntry : PuzzleEntries)
	{
		if (PuzzleEntry.bSolved)
		{
			Result.Add(PuzzleEntry);
		}
	}
	
	return Result;
}

TArray<FHintLine> UCPP_NotebookComponent::GetAllHintFound()
{
	TArray<FHintLine> Hints;
	
	for (FBookmarkEntry Bookmark : UnlockedBookmarks)
	{
		if (Bookmark.StaticData->bHasHint)
		{
			bool bIsSolved = false;
			for (FNotebookPuzzleItem& PuzzleEntry : PuzzleEntries)
			{
				if (PuzzleEntry.Contains(Bookmark.StaticData))
				{
					bIsSolved = PuzzleEntry.bSolved;
				}
			}
			
			Hints.Add(FHintLine(Bookmark.StaticData->HintText, bIsSolved));
		}
	}

	return Hints;
}

// Sets the User submitted culprit for puzzle at the given index
void UCPP_NotebookComponent::SetUserCulprit(FBookmarkEntry NewUserCulprit)
{
	this->UserCulprit = NewUserCulprit.StaticData;
}

UNotebookItemData* UCPP_NotebookComponent::GetUserCulprit()
{
	return this->UserCulprit;
}

// Sets the User submitted weapon for puzzle at the given index
void UCPP_NotebookComponent::SetUserWeapon(FBookmarkEntry NewUserWeapon)
{
	this->UserWeapon = NewUserWeapon.StaticData;
}

UNotebookItemData* UCPP_NotebookComponent::GetUserWeapon()
{
	return this->UserWeapon;
}

// Sets the User submitted motive for puzzle at the given index
void UCPP_NotebookComponent::SetUserMotive(FBookmarkEntry NewUserMotive)
{
	this->UserMotive = NewUserMotive.StaticData;
}

UNotebookItemData* UCPP_NotebookComponent::GetUserMotive()
{
	return this->UserMotive;
}

// Returns true if the currently submitted User solution matches the correct solution of a puzzle
bool UCPP_NotebookComponent::CheckNotebookSolution(FString& SolvedPuzzleName)
{
	// Create a set of the three puzzle entries to compare them with no ordering
	TSet<FSoftObjectPath> UserSet = { FSoftObjectPath(this->UserCulprit), FSoftObjectPath(this->UserWeapon), FSoftObjectPath(this->UserMotive) };

	for (FNotebookPuzzleItem& PuzzleEntry : PuzzleEntries)
	{
		TSet<FSoftObjectPath> CorrectSet = { FSoftObjectPath(PuzzleEntry.CorrectCulprit), FSoftObjectPath(PuzzleEntry.CorrectWeapon), FSoftObjectPath(PuzzleEntry.CorrectMotive) };

		// Compare sets to determine correctness
		if (CorrectSet.Num() == UserSet.Num() && CorrectSet.Includes(UserSet) && PuzzleEntry.bSolved == false)
		{
			PuzzleEntry.bSolved = true;
			OnPuzzleSolved.Broadcast(PuzzleEntry.PuzzleName, PuzzleEntry.HintSystemTag);
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
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
		Writer << PuzzleEntry.PuzzleName;
		Writer << PuzzleEntry.bSolved;

		Writer << PuzzleEntry.CorrectCulprit;
		Writer << PuzzleEntry.CorrectWeapon;
		Writer << PuzzleEntry.CorrectMotive;
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
		Reader << LoadedEntry.PuzzleName;
		Reader << LoadedEntry.bSolved;
				  
		Reader << LoadedEntry.CorrectCulprit;
		Reader << LoadedEntry.CorrectWeapon;
		Reader << LoadedEntry.CorrectMotive;
	}
}

