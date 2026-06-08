// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDialogueRunnerComponent.h"

#include "Components/AudioComponent.h"
#include "ProjectHyde/Core/CoreLibrary.h"
#include "ProjectHyde/Core/Subsystems/Dialogues/DialogueEmotionSubsystem.h"


// Sets default values for this component's properties
UBaseDialogueRunnerComponent::UBaseDialogueRunnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UBaseDialogueRunnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	DialogueSub = GetWorld()->GetGameInstance()->GetSubsystem<UDialogueExecutorSubsystem>();
	EventFlagSub = GetWorld()->GetGameInstance()->GetSubsystem<UCPP_EventFlagSubsystem>();
	AudioComponent = Cast<UAudioComponent>(GetOwner()->GetComponentByClass(UAudioComponent::StaticClass()));
}


// Called every frame
void UBaseDialogueRunnerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBaseDialogueRunnerComponent::OnDialogueMakeSound(FName CharacterName, ELineEmotion Emotion)
{
	UE_LOG(LogTemp, Warning, TEXT("log Sound!!"));
	
	if (AudioComponent)
	{
		UDialogueEmotionSubsystem* DialogueEmotionSubsystem 
		= GetWorld()->GetGameInstance()->GetSubsystem<UDialogueEmotionSubsystem>();
		
		if (DialogueEmotionSubsystem)
		{
			USoundBase* AudioClip = nullptr;
			
			if (DialogueEmotionSubsystem->GetEmotionSound(CharacterName, Emotion, AudioClip))
			{
				AudioComponent->Sound = AudioClip;
				AudioComponent->Play();
			}
		}
	}
}

void UBaseDialogueRunnerComponent::OnDialogueEnded(UBaseDialogue* BaseDialogue)
{
	DialogueSub->OnDialogueMakeSound.Unbind();
	OnDialogueFinished.ExecuteIfBound();
}
