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

UBaseLineNode* UDialogueExecutorSubsystem::StartDialogue(UObject* Executor,UBaseDialogue* Dialogue)
{
	if (!Dialogue) return nullptr;
	
	CurrentDialogue = Dialogue;
	CurrentDialogueOwner = Executor;
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

void UDialogueExecutorSubsystem::MakeSound(FName CharacterName, ELineEmotion Emotion)
{
	OnDialogueMakeSound.ExecuteIfBound(CharacterName,Emotion);
}

void UDialogueExecutorSubsystem::ExecuteCommand(FDialogueCommandLine Command)
{
	FDialogueCommandReturn Result;
	
	if (ExecuteCommand(CurrentDialogueOwner,Command, Result))
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

bool UDialogueExecutorSubsystem::ExecuteCommand(UObject* CurrentExecutor, FDialogueCommandLine Command, FDialogueCommandReturn& CommandReturnParams)
{
    UFunction* Function = CurrentExecutor->FindFunction(Command.CommandName);

    if (!Function)
    {
        UE_LOG(LogTemp, Error, TEXT("Cannot find command %s"), *Command.CommandName.ToString());
        return false;
    }

    FStructOnScope FuncParams(Function);

    int32 ArgIndex = 0;

    for (TFieldIterator<FProperty> It(Function); It && ArgIndex < Command.Args.Num(); ++It)
    {
        FProperty* Property = *It;

        // Skip return value
        if (Property->HasAnyPropertyFlags(CPF_ReturnParm))
        {
            continue;
        }

        // Skip non-input params
        if (!Property->HasAnyPropertyFlags(CPF_Parm))
        {
            continue;
        }

        UValue* Arg = Command.Args[ArgIndex];

        if (FBoolProperty* BoolProp = CastField<FBoolProperty>(Property))
        {
            BoolProp->SetPropertyValue_InContainer(
                FuncParams.GetStructMemory(),
                Arg->GetBooleanValue()
            );
        }
        else if (FFloatProperty* FloatProp = CastField<FFloatProperty>(Property))
        {
            FloatProp->SetPropertyValue_InContainer(
                FuncParams.GetStructMemory(),
                Arg->GetNumberValue()
            );
        }
        else if (FStrProperty* StrProp = CastField<FStrProperty>(Property))
        {
            StrProp->SetPropertyValue_InContainer(
                FuncParams.GetStructMemory(),
                Arg->GetStringValue()
            );
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Unsupported parameter type in %s"), *Command.CommandName.ToString());
            return false;
        }

        ++ArgIndex;
    }

    //Exec Function
	CurrentExecutor->ProcessEvent(Function, FuncParams.GetStructMemory());
    
    //Check for OutParams and Return Values
    for (TFieldIterator<FProperty> It(Function); It; ++It)
    {
        FProperty* Property = *It;
        
        if (Property->HasAnyPropertyFlags(CPF_ReturnParm))
        {
            if (FBoolProperty* BoolReturn = CastField<FBoolProperty>(Property))
            {
                bool ReturnValue = BoolReturn->GetPropertyValue_InContainer(FuncParams.GetStructMemory());
                CommandReturnParams.SetReturnValue(ReturnValue);
            }
        }
        
        if (Property->HasAnyPropertyFlags(CPF_OutParm))
        {
            if (FBoolProperty* BoolReturn = CastField<FBoolProperty>(Property))
            {
                bool OutValue = BoolReturn->GetPropertyValue_InContainer(FuncParams.GetStructMemory());
                CommandReturnParams.SetOutValue(OutValue);
            }
        }
    }
    
    return true;
}
