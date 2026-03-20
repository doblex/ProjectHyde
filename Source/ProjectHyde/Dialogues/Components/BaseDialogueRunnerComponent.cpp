// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDialogueRunnerComponent.h"

#include "Components/AudioComponent.h"
#include "ProjectHyde/Core/CoreLibrary.h"


// Sets default values for this component's properties
UBaseDialogueRunnerComponent::UBaseDialogueRunnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
	UCoreLibrary::SyncMap(EmotionAudio);
}

void UBaseDialogueRunnerComponent::PostLoad()
{
	Super::PostLoad();
	UCoreLibrary::SyncMap(EmotionAudio);
}

#if WITH_EDITOR
void UBaseDialogueRunnerComponent::PostEditChangeProperty(FPropertyChangedEvent& Event)
{
	Super::PostEditChangeProperty(Event);
	UCoreLibrary::SyncMap(EmotionAudio);
}
#endif

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

void UBaseDialogueRunnerComponent::OnDialogueMakeSound(ELineEmotion Emotion)
{
	UE_LOG(LogTemp, Warning, TEXT("log Sound!!"));
	
	if (AudioComponent)
	{
		if (USoundBase* AudioClip = EmotionAudio.FindRef(Emotion))
		{
			AudioComponent->Sound = AudioClip ;
			AudioComponent->Play();
		}
	}
}

void UBaseDialogueRunnerComponent::OnDialogueEnded(UBaseDialogue* BaseDialogue)
{
	DialogueSub->OnDialogueMakeSound.Unbind();
	OnDialogueFinished.ExecuteIfBound();
}
