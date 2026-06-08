// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableDialogueComponent.h"

#include "ProjectHyde/Core/CoreLibrary.h"


// Sets default values for this component's properties
UInteractableDialogueComponent::UInteractableDialogueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	RunnerType = ERunnerType::Interactable;
}


// Called when the game starts
void UInteractableDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractableDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInteractableDialogueComponent::StartDialogue(EInteractablePointState InteractionState, UBaseLineNode*& OutDialogue)
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueEnded);
	DialogueSub->OnDialogueMakeSound.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueMakeSound);
	OutDialogue = DialogueSub->StartDialogue(GetOwner(), InteractableDialogue[InteractionState]);
	return OutDialogue != nullptr;
}

