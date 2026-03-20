// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectDialogueComponent.h"

#include "ProjectHyde/Core/CoreLibrary.h"


// Sets default values for this component's properties
UObjectDialogueComponent::UObjectDialogueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
	UCoreLibrary::SyncMap(ObjectState);
	RunnerType = ERunnerType::Object;
}

#if WITH_EDITOR
void UObjectDialogueComponent::PostEditChangeProperty(FPropertyChangedEvent& Event)
{
	Super::PostEditChangeProperty(Event);
	UCoreLibrary::SyncMap(ObjectState);
}
#endif

void UObjectDialogueComponent::PostLoad()
{
	Super::PostLoad();
	UCoreLibrary::SyncMap(ObjectState);
}

// Called when the game starts
void UObjectDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UObjectDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UObjectDialogueComponent::StartDialogue(EObjectPointState State, UBaseLineNode*& OutDialogue)
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueEnded);
	DialogueSub->OnDialogueMakeSound.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueMakeSound);
	OutDialogue = DialogueSub->StartDialogue(GetOwner(), ObjectState[State]);
	return OutDialogue != nullptr;
}

