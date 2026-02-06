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
	
	DialogueSub = GetWorld()->GetGameInstance()->GetSubsystem<UDialogueExecutorSubsystem>();
}


// Called every frame
void UDialogueRunnerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<UBaseDialogue*> UDialogueRunnerComponent::PresentDialogues()
{
	int MaxAmount = DialogueSub->GetMaxDialoguesNumber();
	
	if (MaxAmount >= 0)
	{
		return DialoguesPool;
	}
	
	MaxAmount = FMath::Min(MaxAmount, DialoguesPool.Num());
	TArray<UBaseDialogue*> DialoguesToReturn;
	
	for (int i = 0; i < MaxAmount; i++)
	{
		DialoguesToReturn.Add(DialoguesPool[i]);
	}
	
	return DialoguesToReturn;
}

UBaseLineNode* UDialogueRunnerComponent::StartDialogue(UBaseDialogue* Dialogue)
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UDialogueRunnerComponent::OnDialogueEnded);
	return DialogueSub->StartDialogue(Dialogue);
}

void UDialogueRunnerComponent::OnDialogueEnded(UBaseDialogue* BaseDialogue)
{
	//TODO: ADD dialogue to notebook
	DialoguesPool.Remove(BaseDialogue);
}

