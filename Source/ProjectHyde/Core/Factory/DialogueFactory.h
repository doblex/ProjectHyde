// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "DialogueFactory.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UDialogueFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	UDialogueFactory();
	
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
};
