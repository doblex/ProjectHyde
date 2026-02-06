// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"
#include "NativeGameplayTags.h"
#include "../Subsystems/CPP_EventFlagSubsystem.h"
#include "CPP_EventFlagsDebugger.generated.h"

UCLASS()
class PROJECTHYDE_API ACPP_EventFlagsDebugger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_EventFlagsDebugger();

	// Set how often the debugger updates its map copy to reflect the subsystem's event flag map
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Event Flags")
	float RefreshTimer = 1.f;

	// A read only copy of the events registered in the Event Flag Subsystem
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Flags")
	TMap<FGameplayTag, bool> EventFlagMapMirror;

private:
	UCPP_EventFlagSubsystem* EventFlagSubsystemRef;

	FTimerHandle EventFlagDebuggerTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PollSubsystem();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
