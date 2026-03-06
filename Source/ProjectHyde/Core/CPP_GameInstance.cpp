// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_GameInstance.h"

#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Kismet/GameplayStatics.h"


void UCPP_GameInstance::LoadLevel(TSoftObjectPtr<UWorld> WorldToLoad)
{
	if (WorldToLoad.IsNull()) return;
	
	ShowLoadingScreen();
	
	WorldLoadingPackageName = WorldToLoad.GetLongPackageName();
	
	LoadPackageAsync(WorldLoadingPackageName,
		FLoadPackageAsyncDelegate::CreateUObject(this, &UCPP_GameInstance::OnPackageLoaded),
		0,
		PKG_ContainsMap
		);
	
	
	GetWorld()->GetTimerManager().SetTimer(
		LoadingTimerHandle,
		this,
		&UCPP_GameInstance::CheckLoadingProgress,
		0.1f,
		true
	);
	
}

void UCPP_GameInstance::UpdateLoadingScreen(float Percent)
{
	if (LoadingScreenInstance.IsValid() && ProgressBar)
	{
		ProgressBar->SetPercent(Percent);
	}
}

void UCPP_GameInstance::CheckLoadingProgress()
{
	float Percentage = GetAsyncLoadPercentage(*WorldLoadingPackageName);
	
	if (Percentage >= 0.0f)
	{
		UpdateLoadingScreen(Percentage/100.0f);
	}
}



void UCPP_GameInstance::OnPackageLoaded(const FName& Name, UPackage* Package, EAsyncLoadingResult::Type Arg)
{
	GetWorld()->GetTimerManager().ClearTimer(LoadingTimerHandle);

	if (Arg == EAsyncLoadingResult::Succeeded)
	{
		
		FTimerHandle DelayHandle;
		GetWorld()->GetTimerManager().SetTimer(DelayHandle, [this]()
		{
			UpdateLoadingScreen(1.f);
			UGameplayStatics::OpenLevel(GetWorld(), FName(*WorldLoadingPackageName));
		}, 1.5f, false);
	}
	else
	{
		HideLoadingScreen();
		UE_LOG(LogLoad, Error, TEXT("UCPP_GameInstance: Failed to load the level"))
	}
}

void UCPP_GameInstance::ShowLoadingScreen(bool bForce)
{
	if (LoadingScreenClass && (!LoadingScreenInstance.IsValid() || bForce))
	{
		LoadingScreenInstance = CreateWidget<UUserWidget>(this, LoadingScreenClass);
		if (LoadingScreenInstance.IsValid())
		{
			LoadingScreenInstance->AddToViewport(999);
			ProgressBar = Cast<UProgressBar>(LoadingScreenInstance->GetWidgetFromName(FName("LoadingBar")));
		}
	}
}

void UCPP_GameInstance::HideLoadingScreen()
{
	if (LoadingScreenInstance.IsValid())
	{
		LoadingScreenInstance->RemoveFromParent();
		LoadingScreenInstance = nullptr;
	}
}

void UCPP_GameInstance::LoadMainMenu()
{
	LoadLevel(MainMenu);
}

void UCPP_GameInstance::LoadLevel()
{
	LoadLevel(Level);
}
