// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "../../Data/NotebookItemData.h"
#include "../../Save/HydeSaveGame.h"

#include "CPP_NotebookComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBookmarkReload);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPuzzleSolved, FString, PuzzleName, FGameplayTag, HintSysTag);

// Enum that represents the query type for the Case Puzzle
UENUM(BlueprintType)
enum class EBookMarkPuzzleCategorySelection : uint8
{
	People = 0,
	Objects = 1,
	All = 2
};

// Enum that represents the button type for the Case Puzzle
UENUM(BlueprintType)
enum class EBookMarkPuzzleCategory : uint8
{
	Culprit = 0,
	Weapon = 1,
	Motive = 2
};

// Enum that represents the presence of a bookmark
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

	// The dialogue the player has seen from this bookmark.
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
	FString PuzzleName;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	FGameplayTag HintSystemTag;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	bool bSolved = false;

	// The correct solutions to the puzzle
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* CorrectCulprit = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* CorrectWeapon = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* CorrectMotive = nullptr;
};

USTRUCT(BlueprintType)
struct FTempDialogues
{
	GENERATED_BODY()

	TArray<FDialogueEntry> TempDialogueEntries;
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

	// Delegate for solving Puzzles
	UPROPERTY(BlueprintAssignable, Category = "Notebook")
	FOnPuzzleSolved OnPuzzleSolved;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	TArray<FBookmarkEntry> UnlockedBookmarks;

	// Entries of Notebook puzzles
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	TArray<FNotebookPuzzleItem> PuzzleEntries;

private:
	UPROPERTY(VisibleAnywhere, Category = "Notebook")
	TMap<UNotebookItemData*, FTempDialogues> TemporaryDialogueStore;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int BookmarkNumber = 0;

	int PuzzleNumber = 0;

	// The user inputted solution
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* UserCulprit = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* UserWeapon = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Notebook")
	UNotebookItemData* UserMotive = nullptr;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	bool IsAlreadyNoted(UNotebookItemData* Data);
	
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	EBookmarkPresence AddBookmark(UNotebookItemData* NewData);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	UNotebookItemData* FindNotebookItemFor(FString BookmarkName);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void AddDialogueEntryToBookmark(UNotebookItemData* ForData, FDialogueEntry DialogueEntryToAdd);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void UpdatePlayerNote(UNotebookItemData* ForData, FText NewNote);

	// (DEPRECATO) Ritorna un array che contiene tutti i bookmark di Persone scoperti dal giocatore
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	TArray<FBookmarkEntry> GetPeopleBookmarksFromPlayer();

	// (DEPRECATO) Ritorna un array che contiene tutti i bookmark di NON Persone scoperti dal giocatore
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	TArray<FBookmarkEntry> GetOtherBookmarksFromPlayer();

	// Ritorna tutti i bookmark in possesso del giocatore
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	TArray<FBookmarkEntry> GetAllBookmarksFromPlayer();

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	TArray<FNotebookPuzzleItem> GetAllSolvedPuzzles();
	
	// Setta il bookmark scelto dall'utente come Colpevole
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void SetUserCulprit(FBookmarkEntry NewUserCulprit);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	UNotebookItemData* GetUserCulprit();

	// Setta il bookmark scelto dall'utente come Arma
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void SetUserWeapon(FBookmarkEntry NewUserWeapon);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	UNotebookItemData* GetUserWeapon();

	// Setta il bookmark scelto dall'utente come Motivo
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void SetUserMotive(FBookmarkEntry NewUserMotive);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	UNotebookItemData* GetUserMotive();

	// Controlla se la soluzione dell'utente salvata al momento corrisponde con una di quelle corrette
	UFUNCTION(BlueprintCallable, Category = "Notebook")
	bool CheckNotebookSolution(FString& SolvedPuzzleName);

	// Save helper for when player is saved
	void SaveNotebookComponentData(FActorSaveData* SaveGameData);

	// Load helper for when player is loaded
	void LoadNotebookComponentData(FActorSaveData* SaveGameData);
};
