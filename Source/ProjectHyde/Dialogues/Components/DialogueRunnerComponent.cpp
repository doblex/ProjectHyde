// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueRunnerComponent.h"

#include "Components/AudioComponent.h"


// Sets default values for this component's properties
UDialogueRunnerComponent::UDialogueRunnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
	SyncEmotionMap();
}

void UDialogueRunnerComponent::PostLoad()
{
	Super::PostLoad();
	SyncEmotionMap();
}

#if WITH_EDITOR
void UDialogueRunnerComponent::PostEditChangeProperty(FPropertyChangedEvent& Event)
{
	Super::PostEditChangeProperty(Event);
	SyncEmotionMap();
}
#endif

// Called when the game starts
void UDialogueRunnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	DialogueSub = GetWorld()->GetGameInstance()->GetSubsystem<UDialogueExecutorSubsystem>();
	AudioComponent = Cast<UAudioComponent>(GetOwner()->GetComponentByClass(UAudioComponent::StaticClass()));
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

UBaseLineNode* UDialogueRunnerComponent::StartWelcomeDialogue()
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UDialogueRunnerComponent::OnWelcomeDialogueEnded);
	DialogueSub->OnDialogueMakeSound.BindDynamic(this, &UDialogueRunnerComponent::OnDialogueMakeSound);
	return DialogueSub->StartDialogue(WelcomeDialogue);
}

void UDialogueRunnerComponent::OnWelcomeDialogueEnded(UBaseDialogue* BaseDialogue)
{
	OnAfterWelcome.ExecuteIfBound();
	DialogueSub->OnDialogueMakeSound.Unbind();
}

UBaseLineNode* UDialogueRunnerComponent::StartDialogue(UBaseDialogue* Dialogue)
{
	DialogueSub->OnDialogueEnded.BindDynamic(this, &UDialogueRunnerComponent::OnDialogueEnded);
	DialogueSub->OnDialogueMakeSound.BindDynamic(this, &UDialogueRunnerComponent::OnDialogueMakeSound);
	return DialogueSub->StartDialogue(Dialogue);
}

void UDialogueRunnerComponent::OnDialogueMakeSound(ELineEmotion Emotion)
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

void UDialogueRunnerComponent::OnDialogueEnded(UBaseDialogue* BaseDialogue)
{
	//TODO: ADD dialogue to notebook
	DialoguesPool.Remove(BaseDialogue);
	DialogueSub->OnDialogueMakeSound.Unbind();
}

void UDialogueRunnerComponent::SyncEmotionMap()
{
	UEnum* EnumPtr = StaticEnum<ELineEmotion>();
	if (!EnumPtr) return;

	TSet<ELineEmotion> ValidKeys;

	// Add missing keys
	for (int32 i = 0; i < EnumPtr->NumEnums() - 1; ++i) // skip MAX
	{
		ELineEmotion Value =
			static_cast<ELineEmotion>(EnumPtr->GetValueByIndex(i));

		ValidKeys.Add(Value);

		if (!EmotionAudio.Contains(Value))
		{
			EmotionAudio.Add(Value, nullptr);
		}
	}

	// Remove stale keys (if enum value was deleted)
	for (auto It = EmotionAudio.CreateIterator(); It; ++It)
	{
		if (!ValidKeys.Contains(It.Key()))
		{
			It.RemoveCurrent();
		}
	}
}
