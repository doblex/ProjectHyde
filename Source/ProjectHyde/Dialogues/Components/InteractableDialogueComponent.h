// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseDialogueRunnerComponent.h"
#include "InteractableDialogueComponent.generated.h"

UENUM(BlueprintType)
enum class EInteractablePointState : uint8
{
	Interacted,
	NotSolved,
	Solved,
	AlreadySolved
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTHYDE_API UInteractableDialogueComponent : public UBaseDialogueRunnerComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInteractableDialogueComponent();
	virtual void PostEditChangeProperty(FPropertyChangedEvent& Event) override;
	virtual void PostLoad() override;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emotion")
	TMap<EInteractablePointState, UBaseDialogue*> InteractableDialogue;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category="Dialogues")
	bool StartDialogue(EInteractablePointState InteractionState, UBaseLineNode*& OutDialogue);
	
};
