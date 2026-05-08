// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../Data/NotebookItemData.h"
#include "../../Save/HydeSaveGame.h"

#include "CPP_NotebookComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBookmarkReload);

// Enum that represent The query type for the Case Puzzle
UENUM(BlueprintType)
enum class EBookMarkPuzzleCategorySelection : uint8
{
	People = 0,
	Objects = 1,
	All = 2
};

// Enum that represent The button type for the Case Puzzle
UENUM(BlueprintType)
enum class EBookMarkPuzzleCategory : uint8
{
	Culprit = 0,
	Weapon = 1,
	Motive = 2
};

// Enum that represent the presence oa a bookmark
UENUM(BlueprintType)
enum class EBookmarkPresence : uint8
{
	None,
	New,
	AlreadyPresent
};

USTRUCT(BlueprintType)
struct FLineLog
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Category = "Notebook")
	FName LineProtagonist;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Category = "Notebook")
	FText Line;

	friend FArchive& operator<<(FArchive& Ar, FLineLog& MyStruct)
	{
		Ar << MyStruct.LineProtagonist;
		Ar << MyStruct.Line;
		return Ar;
	}
};


USTRUCT(BlueprintType)
struct FDialogueEntry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Category = "Notebook")
	FName DialogueTitle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Category = "Notebook")
	FText Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Category = "Notebook")
	TArray<FLineLog> Lines;

	// custom serialization that I just found out about now oops
	friend FArchive& operator<<(FArchive& Ar, FDialogueEntry& MyStruct)
	{
		Ar << MyStruct.DialogueTitle;
		Ar << MyStruct.Description;
		Ar << MyStruct.Lines;
		return Ar;
	}
};

// Struct that represents an entry in the bookmark menu
USTRUCT(BlueprintType)
struct FBookmarkEntry
{
	GENERATED_BODY()
	
	// The static data (Icon, Title, etc.)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* StaticData = nullptr;

	// The dynamic data (Player's custom notes)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	FText PlayerNotes;

	// The dialogue the player has seen from this Person if the bookmark is of Person Type.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	TArray<FDialogueEntry> DialogueEntries;

	// Helper for Save/Load
	UPROPERTY(BlueprintReadOnly)
	FSoftObjectPath AssetPath;
};

// Struct that represents a solution to a notebook puzzle
USTRUCT(BlueprintType)
struct FNotebookPuzzleItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	bool bSolved = false;

	// The correct solutions to the puzzle
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* CorrectCulprit = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* CorrectWeapon = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* CorrectMotive = nullptr;

	// The user inputted solutions
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* UserCulprit = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* UserWeapon = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* UserMotive = nullptr;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTHYDE_API UCPP_NotebookComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_NotebookComponent();

	// Delegate for reloading Bookmarks
	UPROPERTY(BlueprintAssignable, Category = "Notebook")
	FOnBookmarkReload OnBookmarksReloaded;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	TArray<FBookmarkEntry> UnlockedBookmarks;

	// Entries of Notebook puzzles
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	TArray<FNotebookPuzzleItem> PuzzleEntries;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int BookmarkNumber = 0;

	int PuzzleNumber = 0;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	EBookmarkPresence AddBookmark(UNotebookItemData* NewData);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	UNotebookItemData* FindNotebookItemFor(FString PersonName);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void AddDialogueEntryToBookmark(UNotebookItemData* ForData, FDialogueEntry DialogueEntryToAdd);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void UpdatePlayerNote(UNotebookItemData* ForData, FText NewNote);

	// Ritorna un array che contiene tutti i bookmark di Persone scoperti dal giocatore
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	TArray<FBookmarkEntry> GetPeopleBookmarksFromPlayer();

	// Ritorna un array che contiene tutti i bookmark di NON Persone scoperti dal giocatore
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	TArray<FBookmarkEntry> GetOtherBookmarksFromPlayer();

	// Setta il bookmark scelto dall'utente come Colpevole per il puzzle all'indice i dell'array PuzzleEntries
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void SetUserCulpritForIndex(int index, FBookmarkEntry NewUserCulprit);

	// Setta il bookmark scelto dall'utente come Arma per il puzzle all'indice i dell'array PuzzleEntries
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void SetUserWeaponForIndex(int index, FBookmarkEntry NewUserWeapon);

	// Setta il bookmark scelto dall'utente come Motivo per il puzzle all'indice i dell'array PuzzleEntries
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void SetUserMotiveForIndex(int index, FBookmarkEntry NewUserMotive);

	// Controlla se la soluzione dell'utente salvata al momento corrisponde con quella corretta
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	bool CheckNotebookSolution(int index);

	// Save helper for when player is saved
	void SaveNotebookComponentData(FActorSaveData* SaveGameData);

	// Load helper for when player is loaded
	void LoadNotebookComponentData(FActorSaveData* SaveGameData);
};
