// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueExecutorSubsystem.h"
#include "ProjectHyde/Core/DevSettings/DialogueSubsystemSettings.h"
#include "ProjectHyde/Dialogues/BaseClasses/Value.h"
#include "ProjectHyde/Dialogues/DialogueStructs.h"


void UDialogueExecutorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	const UDialogueSubsystemSettings* Settings = GetDefault<UDialogueSubsystemSettings>();
	if (Settings)
	{
		CommandLibrary = Settings->CommandExecutorLibrary.GetDefaultObject();
		
		if (!CommandLibrary)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to load command executor library"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Library not setted"))
	}
}

void UDialogueExecutorSubsystem::ShowDialogue(UBaseLineNode* NextLine)
{
	CurrentLineNode = NextLine;
	
	if (CurrentLineNode->IsCommand())
	{
		ExecuteCommand(CurrentLineNode->GetCommand());
		UE_LOG(LogTemp, Warning, TEXT("Command Executed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentLineNode->GetLineText().ToString());
		//TODO: GET HUD AND SHOW DIALOGUE UI
	}
	
	
	
	ContinueDialogue();
}

void UDialogueExecutorSubsystem::StartDialogue(UBaseDialogue* Dialogue)
{
	CurrentDialogue = Dialogue;
	ShowDialogue(CurrentDialogue->RootLine);
}

void UDialogueExecutorSubsystem::ContinueDialogue(int choice)
{
	if(!CurrentLineNode->HasNextLine())
	{
		UE_LOG(LogTemp, Warning, TEXT("Dialogue Ended"));
		//TODO: maybe lancio un evento all actor che ha fatto partire il dialogo?
		return;
	}
	
	ShowDialogue(CurrentLineNode->GetNextLine(choice));
}

void UDialogueExecutorSubsystem::ExecuteCommand(FDialogueCommandLine Command)
{
	if (!CommandLibrary) return;
	
	if (CommandLibrary->ExecuteCommand(Command))
	{
		UE_LOG(LogTemp, Warning, TEXT("Command Executed"));
	}
}
