// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EventFlagSubsystem.h"

DEFINE_LOG_CATEGORY(EventFlagSubSystem);
UE_DEFINE_GAMEPLAY_TAG_COMMENT(EventFlags, "EventFlags", "Gameplay Tag namespace for game events");

void UCPP_EventFlagSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	// TODO Load GameplayTag of namespace EventFlag

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
	UE_LOGFMT(EventFlagSubSystem, Warning, "Could not set Event Flag: {0}, Reason: Wrong namespace.", Flag.ToString());
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
			UE_LOGFMT(EventFlagSubSystem, Warning, "Could not find Event Flag: {0}, Reason: Event Flag not found.", Flag.ToString());
			return false;
		}
	}


	// Defaults to false and prints a Warning
	UE_LOGFMT(EventFlagSubSystem, Warning, "Could not get Event Flag: {0}, Reason: Wrong namespace.", Flag.ToString());
	return false;
}

TMap<FGameplayTag, bool> UCPP_EventFlagSubsystem::GetEventFlagMap()
{
	return EventFlagMap;
}
