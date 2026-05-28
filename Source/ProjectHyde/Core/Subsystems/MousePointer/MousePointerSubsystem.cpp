// Fill out your copyright notice in the Description page of Project Settings.


#include "MousePointerSubsystem.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "ProjectHyde/Core/DevSettings/MousePointerSettings.h"

void UMousePointerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Load settings
	const UMousePointerSettings* Settings = GetDefault<UMousePointerSettings>();
	if (Settings)
	{
		TArray<TSoftObjectPtr<UTexture2D>> SoftPtrs{
			Settings->NeutralMousePointer,
			Settings->MovementMousePointer,
			Settings->ObservationMousePointer,
			Settings->InteractMousePointer,
			Settings->ObjectMousePointer,
			Settings->ZoomMousePointer
		};

		TArray<FSoftObjectPath> PathsToLoad;
		for (const TSoftObjectPtr<UTexture2D>& Ptr : SoftPtrs)
		{
			PathsToLoad.Add(Ptr.ToSoftObjectPath());
		}

		FStreamableManager& ManagedLoader = UAssetManager::GetStreamableManager();
		// Sta roba è complicatissima odio le lambda in cpp
		ManagedLoader.RequestAsyncLoad(
			PathsToLoad,
			FStreamableDelegate::CreateWeakLambda(this, [SoftPtrs, this]() mutable
			{
				if (SoftPtrs.Num() >= 6)
				{
					this->NeutralMousePointer = SoftPtrs[0].Get();
					this->MovementMousePointer = SoftPtrs[1].Get();
					this->ObservationMousePointer = SoftPtrs[2].Get();
					this->InteractMousePointer = SoftPtrs[3].Get();
					this->ObjectMousePointer = SoftPtrs[4].Get();
					this->ZoomMousePointer = SoftPtrs[5].Get();
					UE_LOG(LogTemp, Display, TEXT("Loaded mouse icons!"));
				}
			})
		);
	};
}



void UMousePointerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UMousePointerSubsystem::SetPointerState(EMousePointerState NewState)
{
	MouseState = NewState;
	OnMouseIconChanged.Broadcast(MouseState);
}


UTexture2D* UMousePointerSubsystem::GetTextureForState(EMousePointerState State) const
{
	switch (State)
	{
		case EMousePointerState::Neutral: return NeutralMousePointer;
		case EMousePointerState::Movement: return MovementMousePointer;
		case EMousePointerState::Observation: return ObservationMousePointer;
		case EMousePointerState::Interact: return InteractMousePointer;
		case EMousePointerState::Object: return ObjectMousePointer;
		case EMousePointerState::Zoom: return ZoomMousePointer;
		default: return NeutralMousePointer;
	}
}
