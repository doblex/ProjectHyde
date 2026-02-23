// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueFactory.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseDialogue.h"

UDialogueFactory::UDialogueFactory()
{
	Formats.Add(TEXT("yarn;Dialogue YARN file"));
	bCreateNew = false;
	bEditorImport = true;
	SupportedClass = UBaseDialogue::StaticClass();
}

UObject* UDialogueFactory::FactoryCreateFile(
	UClass* InClass,
	UObject* InParent,
	FName InName,
	EObjectFlags Flags,
	const FString& Filename,
	const TCHAR* Parms,
	FFeedbackContext* Warn,
	bool& bOutOperationCanceled)
{
	//Reading file content
	FString FileContent;
	if (!FFileHelper::LoadFileToString(FileContent, *Filename))
	{
		UE_LOG(LogTemp, Error, TEXT("UDialogueFactory::FactoryCreateFile: Failed to load file %s"), *Filename);
	}

	//Text organized in an array for parsing
	TArray<FString> Lines;
	FileContent.ParseIntoArrayLines(Lines);

	//variables for parsing step
	TArray<FDialogueTemp> DialogueTemps = ParseFile(Lines);
	
	//Saving objects

	
	FString YarnFileName = FPaths::GetBaseFilename(Filename);
	FString FixedFolder = TEXT("/Game/Dialogues/") + YarnFileName;
	//TODO:dovrebbe diventare variabile
	
	for (auto DialogueTemp : DialogueTemps)
	{
		//saving Path
		FString AssetName = DialogueTemp.Name.ToString();
		FString PackageName = FixedFolder + TEXT("/") + AssetName;
		
		UPackage* Package = CreatePackage(*PackageName);
		Package->FullyLoad();
		
		UBaseDialogue* Dialogue = NewObject<UBaseDialogue>(
			Package,
			UBaseDialogue::StaticClass(),
			FName(*AssetName),
			RF_Public | RF_Standalone
			);
		
		FAssetRegistryModule::AssetCreated(Dialogue);
		Dialogue->MarkPackageDirty();
		Package->MarkPackageDirty();
		
		
		TMap<FName, UBaseLineNode*> CreatedNodes;
		
		for (const auto& Pair : DialogueTemp.Lines)
		{
			const FLineTemp& LineTemp = Pair.Value;
			
			UBaseLineNode* Node = NewObject<UBaseLineNode>(
				Dialogue,
				UBaseLineNode::StaticClass(),
				NAME_Name,
				RF_Public | RF_Transactional
			);
			
			if (LineTemp.bIsCommand)
			{
				
				//function args
				TArray<UValue*> CommandArgs;
				for (auto CommandArg : LineTemp.Args)
				{
					CommandArgs.Add(CreateValue(CommandArg));
				}

				Node->Type = EDialogueLineType::Command;
				
				if (CommandArgs.Num() > 0)
				{
					Node->Command = FDialogueCommandLine(LineTemp.CommandName, CommandArgs);
				}
				else
				{
					Node->Command = FDialogueCommandLine(LineTemp.CommandName);
				}
			}
			else
			{
				Node->Type = EDialogueLineType::Line;
				Node->LineProtagonistName = LineTemp.Protagonist;
				Node->Line = FText::FromString(LineTemp.Text);
			}
			
			CreatedNodes.Add(Pair.Key, Node);
		}
		
		for (const auto& Pair : DialogueTemp.Lines)
		{
			const FName NodeName = Pair.Key;
			const FLineTemp& LineTemp = Pair.Value;

			UBaseLineNode* CurrentNode = CreatedNodes[NodeName];
			
			for (const FName& NextName : LineTemp.NextLines)
			{
				if (UBaseLineNode* NextNode = CreatedNodes.FindRef(NextName))
				{
					CurrentNode->NextLines.Add(NextNode);
				}
			}
		}
	}
	
	
	
	
	
	
	
	return nullptr;
}

TArray<FDialogueTemp> UDialogueFactory::ParseFile(TArray<FString> Lines)
{
	TArray<FDialogueTemp> DialogueTemps;
	
	FDialogueTemp CurrentDialogue = FDialogueTemp();
	
	FLineTemp PreviousLine;
	FLineTemp CurrentLine;
	
	bool bReadingBody = false;
	bool bDialogueReading = false;
	
	for (const FString& Line : Lines)
	{
		//Titolo dialogo
		if(Line.StartsWith(TEXT("title:"))) 
		{
			CurrentDialogue.Name = FName(*Line.RightChop(6).TrimStart());
			bDialogueReading = true;
		}
		//inizio testo
		else if(Line.StartsWith(TEXT("---"))) 
		{
			bReadingBody = true;
		}
		//fine testo
		else if(Line.StartsWith(TEXT("==="))) 
		{
			bReadingBody = false;
			bDialogueReading = false;
			DialogueTemps.Add(CurrentDialogue);
			CurrentDialogue = FDialogueTemp();
		}
		// Linee di testo
		else if (bReadingBody && bDialogueReading) 
		{
			// comment
			if (Line.StartsWith(TEXT("//"))) 
			{
				continue;
			}
			
			FLineTemp NewLine;
			
			// scelta
			if (Line.StartsWith(TEXT("->"))) 
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
			//Comando
			else if (Line.StartsWith(TEXT("<<"))) 
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
					NewLine.Args.Add(*CommandTemp[i]);
				}
				
				CurrentDialogue.Lines.Add(NewLine.Name, NewLine);
				PreviousLine = NewLine;
			}
			// Line pure
			else 
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
	
	return DialogueTemps;
}

UValue* UDialogueFactory::CreateValue(FString ArgString)
{
	UValue* Value = nullptr;
	
	if(ArgString.Equals("true") || ArgString.Equals("false"))
	{
		 UValue::MakeBoolean(Value,ArgString.ToBool());
	}
	else if (ArgString.IsNumeric())
	{
		UValue::MakeNumber(Value,FCString::Atod(*ArgString));
	}
	else
	{
		UValue::MakeString(Value,ArgString);
	}
	
	return Value;
}


