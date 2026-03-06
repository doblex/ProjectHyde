// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../Data/NotebookItemData.h"
#include "../../Save/HydeSaveGame.h"

#include "CPP_NotebookComponent.generated.h"

USTRUCT(BlueprintType)
struct FBookmarkEntry
{
	GENERATED_BODY()

	// The static data (Icon, Title, etc.)
	UPROPERTY(BlueprintReadOnly)
	UNotebookItemData* StaticData = nullptr;

	// The dynamic data (Player's custom notes)
	UPROPERTY(BlueprintReadWrite)
	FString PlayerNotes;

	// Helper for Save/Load
	UPROPERTY()
	FSoftObjectPath AssetPath;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTHYDE_API UCPP_NotebookComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_NotebookComponent();

	UPROPERTY(BlueprintReadOnly, Category = "Notebook")
	TArray<FBookmarkEntry> UnlockedBookmarks;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int BookmarkNumber = 0;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void AddBookmark(UNotebookItemData* NewData);

	UFUNCTION(BlueprintCallable, Category = "Notebook")
	void UpdatePlayerNote(UNotebookItemData* ForData, FString NewNote);

	// Save helper for when player is saved
	void SaveNotebookComponentData(FActorSaveData* SaveGameData);

	// Load helper for when player is loaded
	void LoadNotebookComponentData(FActorSaveData* SaveGameData);
};
