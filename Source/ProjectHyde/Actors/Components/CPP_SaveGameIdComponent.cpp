// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_SaveGameIdComponent.h"

// Sets default values for this component's properties
UCPP_SaveGameIdComponent::UCPP_SaveGameIdComponent()
{
	// Component only fires once, no need to tick
	PrimaryComponentTick.bCanEverTick = false;
}

void UCPP_SaveGameIdComponent::OnRegister()
{
    Super::OnRegister();

    // If we don't have a valid ID yet (newly placed/spawned), create one
    if (!Guid.IsValid())
    {
        Guid = FGuid::NewGuid();
    }
}

#if WITH_EDITOR
void UCPP_SaveGameIdComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    // If the actor was duplicated, the GUID is copied. We must force a new one.
    // This check is specific to the "Guid" property or actor duplication
    if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UCPP_SaveGameIdComponent, Guid))
    {
        // Safety check to prevent accidental manual changes if you expose it
    }
}
#endif
