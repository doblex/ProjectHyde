// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandExecutorLibrary.h"

#include "ProjectHyde/Dialogues/DialogueStructs.h"

bool UCommandExecutorLibrary::ExecuteCommand(FDialogueCommandLine Command)
{
	UFunction* Function = FindFunction(Command.CommandName);
	
	if (!Function)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot Find Command %s"), *Command.CommandName.ToString())
		return false;
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
				return false;
			}
			BoolParam->SetPropertyValue_InContainer(FuncParams.GetStructMemory(), Arg->GetBooleanValue());
			break;
		case UValue::EValueType::NUMBER:
			FloatParam = CastField<FFloatProperty>(Function->FindPropertyByOffset(i));
			if (!FloatParam)
			{
				UE_LOG(LogTemp, Warning, TEXT("Cannot Find Command %s , Skipping Command"), *Command.CommandName.ToString())
				return false;
			}
			FloatParam->SetPropertyValue_InContainer(FuncParams.GetStructMemory(), Arg->GetNumberValue());
			break;
		case UValue::EValueType::STRING:
			StringParam = CastField<FStrProperty>(Function->FindPropertyByOffset(i));
			if (!StringParam)
			{
				UE_LOG(LogTemp, Warning, TEXT("Cannot Find Command %s , Skipping Command"), *Command.CommandName.ToString())
				return false;
			}
			StringParam->SetPropertyValue_InContainer(FuncParams.GetStructMemory(), FString(Arg->GetStringValue().c_str()));
			break;
		}
	}
	
	ProcessEvent(Function, FuncParams.GetStructMemory());
	return true;
}
