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
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDialogueEnded, UBaseDialogue*, BaseDialogue);

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
	UBaseLineNode* ShowDialogue(UBaseLineNode* NextLine);
	void ExecuteCommand(FDialogueCommandLine Command);
	
public:
	FOnDialogueEnded OnDialogueEnded;
	
	UFUNCTION(BlueprintCallable)
	UBaseLineNode* StartDialogue(UBaseDialogue* Dialogue);
	
	UFUNCTION(BlueprintCallable)
	UBaseLineNode* ContinueDialogue(int choice = 0);
	
	int GetMaxDialoguesNumber();
};
