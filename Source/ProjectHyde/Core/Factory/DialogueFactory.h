// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ProjectHyde/Dialogues/BaseClasses/Value.h"
#include "DialogueFactory.generated.h"

/**
 * 
 */

class UBaseDialogue;
class UBaseLineNode;

struct FLineTemp
{
	//Line Params
	FName Name;
	FName Protagonist;
	FString Text;
	TArray<FName> NextLines;
	
	//Command Params
	bool bIsCommand;
	FName CommandName;
	TArray<FString> Args;
};

struct FDialogueTemp
{
	FName Name;
	TMap<FName, FLineTemp> Lines;
};

UCLASS()
class PROJECTHYDE_API UDialogueFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	UDialogueFactory();
	
	virtual UObject* FactoryCreateFile(
		UClass* InClass,
		UObject* InParent,
		FName InName,
		EObjectFlags Flags,
		const FString& Filename,
		const TCHAR* Parms,
		FFeedbackContext* Warn,
		bool& bOutOperationCanceled
		) override;
	
private:
	
	TArray<FDialogueTemp> ParseFile(TArray<FString> Lines);
	
	UValue* CreateValue(FString ArgString);
	
	void LinkDialogue(FDialogueTemp DialogueTemp, TMap<FName, UBaseLineNode*> CreatedNodes);
	
	UBaseDialogue* SaveObjects(TArray<FDialogueTemp> DialogueTemps, FString FixedFolder);
};
