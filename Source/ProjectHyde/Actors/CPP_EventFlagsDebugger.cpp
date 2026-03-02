// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_EventFlagsDebugger.h"

// Sets default values
ACPP_EventFlagsDebugger::ACPP_EventFlagsDebugger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_EventFlagsDebugger::BeginPlay()
{
	EventFlagSubsystemRef = GetGameInstance()->GetSubsystem<UCPP_EventFlagSubsystem>();
	PollSubsystem();
	Super::BeginPlay();

}

void ACPP_EventFlagsDebugger::PollSubsystem()
{
	if (!IsValid(EventFlagSubsystemRef))
	{
		UE_LOGFMT(EventFlagSubsystem, Warning, "Event Flag Subsystem not found!");
		return;
	}
	GetWorld()->GetTimerManager().ClearTimer(EventFlagDebuggerTimerHandle);

	EventFlagMapMirror = EventFlagSubsystemRef->EventFlagMap;
	UE_LOGFMT(EventFlagSubsystem, VeryVerbose, "Event Flag Debugger Updated!");

	GetWorld()->GetTimerManager().SetTimer(
		EventFlagDebuggerTimerHandle,
		this,
		&ACPP_EventFlagsDebugger::PollSubsystem,
		RefreshTimer,
		false
	);
}

// Called every frame
void ACPP_EventFlagsDebugger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

