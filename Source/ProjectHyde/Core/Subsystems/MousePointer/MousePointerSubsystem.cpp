// Fill out your copyright notice in the Description page of Project Settings.


#include "MousePointerSubsystem.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "ProjectHyde/Core/DevSettings/MousePointerSettings.h"


void UMousePointerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	// Load settings
	const UMousePointerSettings* Settings = GetDefault<UMousePointerSettings>();
	//if (Settings)
	//{
	//	FStreamableManager& ManagedLoader = UAssetManager::GetStreamableManager();
	//	ManagedLoader.RequestAsyncLoad(
	//		Settings->NeutralMousePointer.ToSoftObjectPath(),
	//		FStreamableDelegate::CreateUObject(this, &UMousePointerSubsystem::OnMouseTexturesLoaded, Settings->NeutralMousePointer)
	//	);
	//};
}

void UMousePointerSubsystem::Deinitialize()
{
	
}
