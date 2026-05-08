// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDialogue.h"

FDialogueEntry UBaseDialogue::GetDialogueEntry()
{
	FDialogueEntry Entry = FDialogueEntry();
	UBaseLineNode* NextNode = RootLine;

	while (NextNode != nullptr)
	{
		if (NextNode->IsCommand())
		{
			NextNode = NextNode->GetNextLine();
			continue;
		}
		
		FLineLog LineLog = NextNode->GetLineLog();
		Entry.Lines.Add(LineLog);
		
		NextNode = NextNode->GetNextLine();
	}
	
	Entry.DialogueTitle = DialogueName;
	
	return Entry;
}