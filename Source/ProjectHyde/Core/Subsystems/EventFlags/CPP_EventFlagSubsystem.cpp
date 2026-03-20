// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EventFlagSubsystem.h"

#include "IPropertyTable.h"

DEFINE_LOG_CATEGORY(EventFlagSubsystem);
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EventFlags, "EventFlags", "Gameplay Tag namespace for game events");

void UCPP_EventFlagSubsystem::OnEventFlagTableLoaded(TSoftObjectPtr<UDataTable> TablePtr)
{
	EventFlagsData = TablePtr.Get();

	if (EventFlagsData)
	{
		const FString ContextString(TEXT("Context"));
		TArray<FGameplayTagTableRow*> EventFlagRows;
		EventFlagsData->GetAllRows(ContextString, OUT EventFlagRows);

		for (FGameplayTagTableRow* Row : EventFlagRows)
		{
			UE_LOGFMT(EventFlagSubsystem, Display, "Loaded Event Flag: {0}", Row->Tag.ToString());
			EventFlagMap.Add(FGameplayTag::RequestGameplayTag(Row->Tag), false);
		}
		bTagsLoaded = true;
	}
	else
	{
		UE_LOGFMT(EventFlagSubsystem, Error, "EventFlagSubsystem: Table Load Failed");
	}

}

void UCPP_EventFlagSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	// Async Load GameplayTags from EventFlags DataTable
	const UEventFlagSubsystemSettings* Settings = GetDefault<UEventFlagSubsystemSettings>();
	if (Settings) 
	{
		FStreamableManager& ManagedLoader = UAssetManager::GetStreamableManager();
		ManagedLoader.RequestAsyncLoad(
			Settings->EventFlagsDataTable.ToSoftObjectPath(),
			FStreamableDelegate::CreateUObject(this, &UCPP_EventFlagSubsystem::OnEventFlagTableLoaded, Settings->EventFlagsDataTable)
		);
	};

	Super::Initialize(Collection);
}

void UCPP_EventFlagSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UCPP_EventFlagSubsystem::SetEventFlag(FGameplayTag Flag, bool bValue)
{
	// Check that GameplayTag is in the EventFLag namespace
	if (Flag.MatchesTag(EventFlags)) 
	{
		EventFlagMap.Add(Flag, bValue);
		return true;
	}

	// Prints a warning and returns false if not set
	UE_LOGFMT(EventFlagSubsystem, Warning, "Could not set Event Flag: {0}, Reason: Wrong namespace.", Flag.ToString());
	return false;
}

bool UCPP_EventFlagSubsystem::GetEventFlag(FGameplayTag Flag)
{
	if (Flag.MatchesTag(EventFlags))
	{
		bool* bFlagPtr = EventFlagMap.Find(Flag);
		if (bFlagPtr != nullptr) return *bFlagPtr;
		else
		{
			// Flag not found in map case
			UE_LOGFMT(EventFlagSubsystem, Warning, "Could not find Event Flag: {0}, Reason: Event Flag not found.", Flag.ToString());
			return false;
		}
	}


	// Defaults to false and prints a Warning
	UE_LOGFMT(EventFlagSubsystem, Warning, "Could not get Event Flag: {0}, Reason: Wrong namespace.", Flag.ToString());
	return false;
}

TMap<FGameplayTag, bool> UCPP_EventFlagSubsystem::GetEventFlagMap()
{
	return EventFlagMap;
}

bool UCPP_EventFlagSubsystem::GetTagFromString(FString TagString, FGameplayTag& OutTag)
{
	FName TagName = FName(*TagString);
	
	OutTag = FGameplayTag::RequestGameplayTag(TagName);
	
	return OutTag.IsValid();
}

bool UCPP_EventFlagSubsystem::AreTagsLoaded()
{
	return bTagsLoaded;
}

void UCPP_EventFlagSubsystem::ResetAllFlags()
{
	for (TPair<FGameplayTag, bool>& flag : EventFlagMap)
	{
		flag.Value = false;
	}
}

void UCPP_EventFlagSubsystem::Save(UHydeSaveGame* SaveGameInstance)
{
	UE_LOGFMT(EventFlagSubsystem, Display, "Event Flag Subsystem received Save request!");
	SaveGameInstance->EventFlagMap = this->EventFlagMap;
}

void UCPP_EventFlagSubsystem::Load(const UHydeSaveGame* SaveGameInstance)
{
	UE_LOGFMT(EventFlagSubsystem, Display, "Event Flag Subsystem received Load request!");
	this->EventFlagMap = SaveGameInstance->EventFlagMap;
}
