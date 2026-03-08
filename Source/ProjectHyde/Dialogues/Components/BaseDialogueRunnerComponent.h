// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProjectHyde/Core/Subsystems/Dialogues/DialogueExecutorSubsystem.h"
#include "ProjectHyde/Core/Subsystems/EventFlags/CPP_EventFlagSubsystem.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseDialogue.h"
#include "BaseDialogueRunnerComponent.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnAfterWelcomeDialogue);

UENUM(BlueprintType)
enum class ERunnerType : uint8
{
	Person,
	Interactable,
	Object,
	Observation,
	Zoom
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTHYDE_API UBaseDialogueRunnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBaseDialogueRunnerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& Event) override;
#endif
	
	virtual void PostLoad() override;
	
	UDialogueExecutorSubsystem* DialogueSub;
	UCPP_EventFlagSubsystem* EventFlagSub;
	UAudioComponent* AudioComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Emotion")
	TMap<ELineEmotion, USoundBase*> EmotionAudio;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ERunnerType RunnerType;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	
	
	
	UFUNCTION()
	void OnDialogueMakeSound(ELineEmotion Emotion);
	
	UFUNCTION()
	virtual void OnDialogueEnded(UBaseDialogue* BaseDialogue);
};
