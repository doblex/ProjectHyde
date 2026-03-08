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
	
	UCoreLibrary::SyncMap(InteractableDialogue);
	RunnerType = ERunnerType::Interactable;
}
#if WITH_EDITOR
void UInteractableDialogueComponent::PostEditChangeProperty(FPropertyChangedEvent& Event)
{
	Super::PostEditChangeProperty(Event);
	UCoreLibrary::SyncMap(InteractableDialogue);
}
#endif

void UInteractableDialogueComponent::PostLoad()
{
	Super::PostLoad();
	UCoreLibrary::SyncMap(InteractableDialogue);
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

UBaseLineNode* UInteractableDialogueComponent::StartDialogue(EInteractablePointState InteractionState)
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueEnded);
	DialogueSub->OnDialogueMakeSound.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueMakeSound);
	return DialogueSub->StartDialogue(InteractableDialogue[InteractionState]);
}

