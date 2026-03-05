// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ProgressBar.h"
#include "Engine/GameInstance.h"
#include "CPP_GameInstance.generated.h"

UCLASS()
class PROJECTHYDE_API UCPP_GameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	TWeakObjectPtr<UUserWidget> LoadingScreenInstance;
	FTimerHandle LoadingTimerHandle;
	FString WorldLoadingPackageName;
	
	UProgressBar* ProgressBar;
	
	void LoadLevel(TSoftObjectPtr<UWorld> WorldToLoad);
	
	void UpdateLoadingScreen(float Percent);
	void OnPackageLoaded(const FName& Name, UPackage* Package, EAsyncLoadingResult::Type Arg);
	
	void ShowLoadingScreen();
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> LoadingScreenClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levels")
	TSoftObjectPtr<UWorld> MainMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levels")
	TSoftObjectPtr<UWorld> Level;
	
	UFUNCTION()
	void CheckLoadingProgress();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void HideLoadingScreen();	

	UFUNCTION(BlueprintCallable, Category = "Levels")
	void LoadMainMenu();
	UFUNCTION(BlueprintCallable, Category = "Levels")
	void LoadLevel();

	
};
