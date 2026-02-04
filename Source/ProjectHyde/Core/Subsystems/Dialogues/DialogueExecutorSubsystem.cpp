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

void UDialogueExecutorSubsystem::ShowDialogue(UBaseLineNode* NextLine)
{
	CurrentLineNode = NextLine;
	
	if (CurrentLineNode->IsCommand())
	{
		ExecuteCommand(CurrentLineNode->GetCommand());
	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Cyan,
				CurrentLineNode->GetLineText().ToString()
				);
		}	
	}
	
	//TODO: GET HUD AND SHOW DIALOGUE UI
	
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
		
		OnDialogueEnded.ExecuteIfBound();
		OnDialogueEnded.Clear();
		//TODO: maybe lancio un evento all actor che ha fatto partire il dialogo?
		return;
	}
	
	ShowDialogue(CurrentLineNode->GetNextLine(choice));
}

int UDialogueExecutorSubsystem::GetMaxDialoguesNumber()
{
	return MaxDialoguesNumber;
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
