// Fill out your copyright notice in the Description page of Project Settings.


#include "PersonDialogueComponent.h"


// Sets default values for this component's properties
UPersonDialogueComponent::UPersonDialogueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	RunnerType = ERunnerType::Person;

	// ...
}


// Called when the game starts
void UPersonDialogueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPersonDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UBaseLineNode* UPersonDialogueComponent::StartDialogue(UBaseDialogue* Dialogue)
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueEnded);
	DialogueSub->OnDialogueMakeSound.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueMakeSound);
	return DialogueSub->StartDialogue(Dialogue);
}

TArray<UBaseDialogue*> UPersonDialogueComponent::PresentDialogues()
{
	int MaxAmount = DialogueSub->GetMaxDialoguesNumber();
	
	if (MaxAmount <= 0)
	{
		return DialoguesPool;
	}
	
	TArray<UBaseDialogue*> DialoguesToReturn;
	
	for (int i = 0; i < DialoguesPool.Num() && DialoguesToReturn.Num() < MaxAmount + 1; i++)
	{
		if (DialoguesPool[i]->Requirements.IsValid())
		{
			bool bCanShow = true;
			for (const FGameplayTag Tag : DialoguesPool[i]->Requirements)
			{
				if (!EventFlagSub->GetEventFlag(Tag))
				{
					bCanShow = false;
				}
			}
			
			if (bCanShow)
			{
				DialoguesToReturn.Add(DialoguesPool[i]);
			}
		}
		else
		{
			DialoguesToReturn.Add(DialoguesPool[i]);
		}
		
	}
	
	return DialoguesToReturn;
}

UBaseLineNode* UPersonDialogueComponent::StartWelcomeDialogue()
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UPersonDialogueComponent::OnWelcomeDialogueEnded);
	DialogueSub->OnDialogueMakeSound.BindDynamic(this, &UBaseDialogueRunnerComponent::OnDialogueMakeSound);
	return DialogueSub->StartDialogue(WelcomeDialogue);
}

void UPersonDialogueComponent::OnWelcomeDialogueEnded(UBaseDialogue* BaseDialogue)
{
	OnAfterWelcome.ExecuteIfBound();
	DialogueSub->OnDialogueMakeSound.Unbind();
}

void UPersonDialogueComponent::OnDialogueEnded(UBaseDialogue* BaseDialogue)
{
	//TODO: ADD dialogue to notebook
	DialoguesPool.Remove(BaseDialogue);
	
	Super::OnDialogueEnded(BaseDialogue);
}

