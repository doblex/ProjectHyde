// Fill out your copyright notice in the Description page of Project Settings.


#include "ObservationDialogueComponent.h"


// Sets default values for this component's properties
UObservationDialogueComponent::UObservationDialogueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	RunnerType = ERunnerType::Observation;
}


// Called when the game starts
void UObservationDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UObservationDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                  FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UObservationDialogueComponent::StartDialogue(UBaseLineNode*& OutDialogue)
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueEnded);
	DialogueSub->OnDialogueMakeSound.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueMakeSound);
	OutDialogue = DialogueSub->StartDialogue(GetOwner(),Dialogue);
	return OutDialogue != nullptr;
}

