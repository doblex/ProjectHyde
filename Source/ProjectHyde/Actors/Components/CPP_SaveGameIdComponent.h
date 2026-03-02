// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_SaveGameIdComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTHYDE_API UCPP_SaveGameIdComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_SaveGameIdComponent();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Save System")
	FGuid Guid;

	// Called when the actor is spawned or level is opened
	virtual void OnRegister() override;

#if WITH_EDITOR
	// Ensures duplicated actors get new GUIDs in the editor
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

};
