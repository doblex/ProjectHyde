// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProjectHyde/Core/Subsystems/Dialogues/DialogueExecutorSubsystem.h"
#include "ProjectHyde/Core/Subsystems/EventFlags/CPP_EventFlagSubsystem.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseDialogue.h"
#include "DialogueRunnerComponent.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnAfterWelcomeDialogue);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTHYDE_API UDialogueRunnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDialogueRunnerComponent();

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UBaseDialogue*> DialoguesPool;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FOnAfterWelcomeDialogue OnAfterWelcome;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBaseDialogue* WelcomeDialogue;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	TArray<UBaseDialogue*> PresentDialogues();

	
	
	UFUNCTION(BlueprintCallable)
	UBaseLineNode* StartWelcomeDialogue();
	
	UFUNCTION()
	void OnWelcomeDialogueEnded(UBaseDialogue* BaseDialogue);
	
	UFUNCTION(BlueprintCallable)
	UBaseLineNode* StartDialogue(UBaseDialogue* Dialogue);
	
	UFUNCTION()
	void OnDialogueMakeSound(ELineEmotion Emotion);
	
	UFUNCTION()
	void OnDialogueEnded(UBaseDialogue* BaseDialogue);
	
	void SetNextDialogue(FName DialogueName);
	
	void SyncEmotionMap();
};
