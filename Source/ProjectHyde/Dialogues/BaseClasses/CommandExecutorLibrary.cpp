// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandExecutorLibrary.h"

#include "ProjectHyde/Dialogues/DialogueStructs.h"

/// 
/// @param Command The command structure to execute the command 
/// @param CommandReturnParams The Return Structure for managing the returned values (Return and Out params)
/// @return Return false if not executed
bool UCommandExecutorLibrary::ExecuteCommand(FDialogueCommandLine Command, FDialogueCommandReturn& CommandReturnParams)
{
    UFunction* Function = FindFunction(Command.CommandName);

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
    ProcessEvent(Function, FuncParams.GetStructMemory());
    
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


