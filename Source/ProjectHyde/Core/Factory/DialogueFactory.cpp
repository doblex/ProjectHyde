// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueFactory.h"

#include "ProjectHyde/Dialogues/BaseClasses/BaseDialogue.h"

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
	TArray<FName> Args;
};

struct FDialogueTemp
{
	FName Name;
	TMap<FName, FLineTemp> Lines;
};


UDialogueFactory::UDialogueFactory()
{
	Formats.Add(TEXT("yarn;Dialogue YARN file"));
	bCreateNew = false;
	bEditorImport = true;
	SupportedClass = UBaseDialogue::StaticClass();
}

UObject* UDialogueFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	
	FString FileContent;
	FFileHelper::LoadFileToString(FileContent, *Filename);

	TArray<FString> Lines;
	FileContent.ParseIntoArrayLines(Lines);

	TArray<FDialogueTemp> DialogueTemps;
	
	FDialogueTemp CurrentDialogue = FDialogueTemp();
	
	FLineTemp PreviousLine;
	FLineTemp CurrentLine;
	
	bool bReadingBody = false;
	bool bDialogueReading = false;
	
	for (const FString& Line : Lines)
	{
		if(Line.StartsWith(TEXT("title:"))) //Titolo dialogo
		{
			CurrentDialogue.Name = FName(*Line.RightChop(6).TrimStart());
			bDialogueReading = true;
		}
		else if(Line.StartsWith(TEXT("---"))) //inizio testo
		{
			bReadingBody = true;
		}
		else if(Line.StartsWith(TEXT("==="))) //fine testo
		{
			bReadingBody = false;
			bDialogueReading = false;
			DialogueTemps.Add(CurrentDialogue);
			CurrentDialogue = FDialogueTemp();
		}
		else if (bReadingBody && bDialogueReading) // Linee di testo
		{
			if (Line.StartsWith(TEXT("//"))) // comment
			{
				continue;
			}
			
			FLineTemp NewLine;
			
			
			if (Line.StartsWith(TEXT("->"))) // scelta
			{
				NewLine.Text = Line.RightChop(2);
				NewLine.bIsCommand = false;
				
				if (CurrentDialogue.Lines.Contains(PreviousLine.Name))
				{
					NewLine.Name = FName(*FString::Printf(
						TEXT("Line_%d_%d"),
						CurrentDialogue.Lines.Num(),
						PreviousLine.NextLines.Num()));
					
					CurrentDialogue.Lines[PreviousLine.Name].NextLines.Add(FName(NewLine.Name));
				}
			}
			else if (Line.StartsWith(TEXT("<<"))) //Comando
			{
				NewLine.Name = FName(*FString::Printf(TEXT("Line_%d_Command"), CurrentDialogue.Lines.Num()));
				NewLine.bIsCommand = true;
				
				//tolgo le parentesi angolari
				FString Inner = Line.Mid(2, Line.Len() - 4);
				
				//divido per il carattere spazio nome e argomenti della funzione
				TArray<FString> CommandTemp;
				Line.ParseIntoArray(CommandTemp, TEXT(" "));
				
				//mi salvo il tutto nella struct
				NewLine.CommandName = FName(*CommandTemp[0]);

				for (int i = 1; i < CommandTemp.Num(); ++i)
				{
					NewLine.Args.Add(FName(*CommandTemp[i]));
				}
				
				CurrentDialogue.Lines.Add(NewLine.Name, NewLine);
				PreviousLine = NewLine;
			}
			else // Line pure
			{
				NewLine.Name = FName(*FString::Printf(TEXT("Line_%d"), CurrentDialogue.Lines.Num()));
				
				FString Speaker, Text;
				if (Line.Split(TEXT(":"), &Speaker, &Text))
				{
					NewLine.Protagonist = FName(*Speaker.TrimStartAndEnd());
					NewLine.Text = Text.TrimStartAndEnd();
				}
				else
				{
					NewLine.Text = Text.TrimStartAndEnd();
				}
				
				NewLine.bIsCommand = false;
				
				CurrentDialogue.Lines.Add(NewLine.Name, NewLine);
				PreviousLine = NewLine;
			}
		}
		
	}
	
	
	
	return nullptr;
}
