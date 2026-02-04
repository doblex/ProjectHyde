// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseDialogue.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseLineNode.h"
#include "ProjectHyde/Dialogues/BaseClasses/CommandExecutorLibrary.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DialogueExecutorSubsystem.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE(FOnDialogueEnded);

UCLASS()
class PROJECTHYDE_API UDialogueExecutorSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	int MaxDialoguesNumber = 0;
	
	UCommandExecutorLibrary* CommandLibrary;
	UBaseDialogue* CurrentDialogue;
	UBaseLineNode* CurrentLineNode;
	
protected:
	void ShowDialogue(UBaseLineNode* NextLine);
	void ExecuteCommand(FDialogueCommandLine Command);
	
public:
	FOnDialogueEnded OnDialogueEnded;
	
	void StartDialogue(UBaseDialogue* Dialogue);
	
	UFUNCTION(BlueprintCallable)
	void ContinueDialogue(int choice = 0);
	
	int GetMaxDialoguesNumber();
};
