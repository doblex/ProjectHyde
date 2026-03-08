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
		
		MaxDialoguesNumber = Settings->MaxDialoguesNumber;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Library not setted"))
	}
}

UBaseLineNode* UDialogueExecutorSubsystem::ShowDialogue(UBaseLineNode* NextLine)
{
	CurrentLineNode = NextLine;
	
	while (CurrentLineNode->IsCommand())
	{
		ExecuteCommand(CurrentLineNode->GetCommand());
		
		if (!CurrentLineNode->HasNextLine())
		{
			OnDialogueEnded.ExecuteIfBound(CurrentDialogue);
			OnDialogueEnded.Clear();
			return nullptr;
		}
		
		CurrentLineNode = CurrentLineNode->GetNextLine();
	}
	
	return CurrentLineNode;
}

UBaseLineNode* UDialogueExecutorSubsystem::StartDialogue(UBaseDialogue* Dialogue)
{
	if (!Dialogue) return nullptr;
	
	CurrentDialogue = Dialogue;
	return ShowDialogue(CurrentDialogue->RootLine);
}

UBaseLineNode* UDialogueExecutorSubsystem::ContinueDialogue(int choice)
{
	if(!CurrentLineNode->HasNextLine())
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Green,
				TEXT("Dialogue Ended")
				);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Dialogue Ended"));
		}
		
		OnDialogueEnded.ExecuteIfBound(CurrentDialogue);
		OnDialogueEnded.Clear();
		return nullptr;
	}
	
	return ShowDialogue(CurrentLineNode->GetNextLine(choice));
}

int UDialogueExecutorSubsystem::GetMaxDialoguesNumber()
{
	return MaxDialoguesNumber;
}

void UDialogueExecutorSubsystem::MakeSound(ELineEmotion Emotion)
{
	OnDialogueMakeSound.ExecuteIfBound(Emotion);
}

void UDialogueExecutorSubsystem::ExecuteCommand(FDialogueCommandLine Command)
{
	if (!CommandLibrary) return;
	
	FDialogueCommandReturn Result;
	
	if (CommandLibrary->ExecuteCommand(Command, Result))
	{
		FString Message = FString(TEXT("Command Executed"));
			
		if (Result.HasReturn)
		{
			Message.Append(TEXT(" With Return of: "));
			Message.Append(Result.ReturnValue ? TEXT("true") : TEXT("false"));
		}
			
		if (Result.HasOutValue)
		{
			Message.Append(TEXT(" Out: "));
			Message.Append(Result.OutValue ? TEXT("true") : TEXT("false"));
		}
		
		
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Green,
				Message
				);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
		}
	}
}
