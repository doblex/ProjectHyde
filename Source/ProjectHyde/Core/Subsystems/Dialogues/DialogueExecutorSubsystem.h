// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseDialogue.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseLineNode.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DialogueExecutorSubsystem.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDialogueEnded, UBaseDialogue*, BaseDialogue);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDialogueMakeSound, ELineEmotion, Emotion);

UCLASS()
class PROJECTHYDE_API UDialogueExecutorSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	int MaxDialoguesNumber = 0;
	
	UBaseDialogue* CurrentDialogue;
	UBaseLineNode* CurrentLineNode;
	
	UObject* CurrentDialogueOwner;
	
protected:
	UBaseLineNode* ShowDialogue(UBaseLineNode* NextLine);
	void ExecuteCommand(FDialogueCommandLine Command);
	
	bool ExecuteCommand(UObject* CurrentExecutor, FDialogueCommandLine Command, FDialogueCommandReturn& ReturnValue);
	
public:
	FOnDialogueEnded OnDialogueEnded;
	FOnDialogueMakeSound OnDialogueMakeSound;
	
	UFUNCTION(BlueprintCallable)
	UBaseLineNode* StartDialogue(UObject* Executor,UBaseDialogue* Dialogue);
	
	UFUNCTION(BlueprintCallable)
	UBaseLineNode* ContinueDialogue(int choice = 0);
	
	UFUNCTION(BlueprintCallable)
	void MakeSound(ELineEmotion Emotion = ELineEmotion::Neutral);
	
	int GetMaxDialoguesNumber();
	
	
	
};
