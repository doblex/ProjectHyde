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
		CommandLibrary = Settings->CommandBlueprintFunctionLibrary.Get();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Library not setted"))
	}
}

void UDialogueExecutorSubsystem::ShowDialogue(UBaseLineNode* NextLine)
{
	CurrentLineNode = NextLine;
	//TODO: GET HUD AND SHOW DIALOGUE UI
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
	
	UFunction* Function = CommandLibrary->FindFunction(Command.CommandName);
	
	if (!Function)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot Find Command %s"), *Command.CommandName.ToString())
		return ContinueDialogue();
	}
	
	FStructOnScope FuncParams(Function);
	FBoolProperty* BoolParam;
	FFloatProperty* FloatParam;
	FStrProperty* StringParam;

	for (int i = 0; i < Command.Args.Num(); ++i)
	{
		UValue* Arg = Command.Args[i];
		// Set input properties
		switch (Arg->GetType())
		{
		case UValue::EValueType::BOOLEAN:
			BoolParam = CastField<FBoolProperty>(Function->FindPropertyByOffset(i));
			if (!BoolParam)
			{
				UE_LOG(LogTemp, Warning, TEXT("Cannot Find Command %s , Skipping Command"), *Command.CommandName.ToString())
				return ContinueDialogue();
			}
			BoolParam->SetPropertyValue_InContainer(FuncParams.GetStructMemory(), Arg->GetBooleanValue());
			break;
		case UValue::EValueType::NUMBER:
			FloatParam = CastField<FFloatProperty>(Function->FindPropertyByOffset(i));
			if (!FloatParam)
			{
				UE_LOG(LogTemp, Warning, TEXT("Cannot Find Command %s , Skipping Command"), *Command.CommandName.ToString())
				return ContinueDialogue();
			}
			FloatParam->SetPropertyValue_InContainer(FuncParams.GetStructMemory(), Arg->GetNumberValue());
			break;
		case UValue::EValueType::STRING:
			StringParam = CastField<FStrProperty>(Function->FindPropertyByOffset(i));
			if (!StringParam)
			{
				UE_LOG(LogTemp, Warning, TEXT("Cannot Find Command %s , Skipping Command"), *Command.CommandName.ToString())
				return ContinueDialogue();
			}
			StringParam->SetPropertyValue_InContainer(FuncParams.GetStructMemory(), FString(Arg->GetStringValue().c_str()));
			break;
		}
	}
	
	ProcessEvent(Function, FuncParams.GetStructMemory());
}
