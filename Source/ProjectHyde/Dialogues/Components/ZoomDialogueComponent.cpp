// Fill out your copyright notice in the Description page of Project Settings.


#include "ZoomDialogueComponent.h"


// Sets default values for this component's properties
UZoomDialogueComponent::UZoomDialogueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	RunnerType = ERunnerType::Zoom;
}


// Called when the game starts
void UZoomDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UZoomDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                  FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UZoomDialogueComponent::StartDialogue(UBaseLineNode*& OutDialogue)
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueEnded);
	DialogueSub->OnDialogueMakeSound.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueMakeSound);
	OutDialogue = DialogueSub->StartDialogue(GetOwner(),Dialogue);
	return OutDialogue != nullptr;
}

