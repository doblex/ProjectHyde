// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueRunnerComponent.h"


// Sets default values for this component's properties
UDialogueRunnerComponent::UDialogueRunnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDialogueRunnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDialogueRunnerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDialogueRunnerComponent::StartDialogue()
{
	UDialogueExecutorSubsystem* DialogueSub = GetWorld()->GetGameInstance()->GetSubsystem<UDialogueExecutorSubsystem>();
		
	DialogueSub->StartDialogue(CurrentDialogue);
}

void UDialogueRunnerComponent::SetNextDialogue(FName DialogueName)
{
	for (auto Element : DialoguesPool)
	{
		if (Element->DialogueName == DialogueName)
		{
			CurrentDialogue = Element;
		}
	}
}

