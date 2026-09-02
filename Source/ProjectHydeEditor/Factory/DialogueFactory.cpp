// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueFactory.h"

#include "Factories.h"
#include "GameplayTagsManager.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "DevSettings/DialogueImporterSettings.h"
#include "Internationalization/StringTableCore.h"
#include "ProjectHyde/Core/CoreLibrary.h"
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
		UE_LOG(LogEditorFactories, Error, TEXT("UDialogueFactory::FactoryCreateFile: Failed to load file %s"), *Filename);
	}

	UE_LOG(LogEditorFactories, Display, TEXT("Yarn Import: Started: %s"), *Filename);
	
	//Text organized in an array for parsing
	TArray<FString> Lines;
	FileContent.ParseIntoArrayLines(Lines);
	
	//variables for parsing step
	TArray<FDialogueTemp> DialogueTemps = ParseFile(Lines);
	
	//Saving objects
	
	UBaseDialogue* FirstDialogue = nullptr;
	
	DialogueImporterSettings = GetDefault<UDialogueImporterSettings>();
	
	if (DialogueImporterSettings)
	{
		if (!DialogueImporterSettings->DialogueImportPath.Path.IsEmpty())
		{
			FString YarnFileName = FPaths::GetBaseFilename(Filename);
			FString FixedFolder = DialogueImporterSettings->DialogueImportPath.Path + YarnFileName;
			FirstDialogue = SaveObjects(DialogueTemps, FixedFolder);
		}
		else
		{
			UE_LOG(LogEditorFactories, Error, TEXT("UDialogueFactory::FactoryCreateFile: DialogueImportPath is empty"));
		}
	}
	else
	{
		UE_LOG(LogEditorFactories, Error, TEXT("UDialogueFactory::FactoryCreateFile: Failed to load settings from UDialogueSubsystemSettings"));
	}
	
	return FirstDialogue;
	
}

void UDialogueFactory::LinkDialogue(FDialogueTemp DialogueTemp, TMap<FName, UBaseLineNode*> CreatedNodes)
{
	UE_LOG(LogEditorFactories, Display, TEXT("Yarn Import: Start Linking %s: %i lines"), *DialogueTemp.InternalName.ToString(), DialogueTemp.Lines.Num());
		
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

void UDialogueFactory::AddToStringTable(FStringTableRef StringTableRef, TArray<FLineTemp> LinesToRegister)
{
	for (auto LineTemp : LinesToRegister)
	{
		FTextKey Key = FTextKey(*LineTemp.StringTableID.ToString());
		StringTableRef->SetSourceString(Key, LineTemp.Text);
	}

}

UValue* UDialogueFactory::CreateValue(UObject* Outer,FString ArgString)
{
	UValue* Value = nullptr;
	
	if(ArgString.Equals("true") || ArgString.Equals("false"))
	{
		Value = UValue::MakeBoolean(Outer,ArgString.ToBool());
	}
	else if (ArgString.IsNumeric())
	{
		Value = UValue::MakeNumber(Outer,FCString::Atod(*ArgString));
	}
	else
	{
		Value = UValue::MakeString(Outer,ArgString);
	}
	
	return Value;
}



TArray<FDialogueTemp> UDialogueFactory::ParseFile(TArray<FString> Lines)
{
	UE_LOG(LogEditorFactories, Display, TEXT("Yarn Import: Parsing Started"));
	
	TArray<FDialogueTemp> DialogueTemps;
	
	FDialogueTemp CurrentDialogue = FDialogueTemp();
	
	FLineTemp PreviousLine;
	FLineTemp CurrentLine;
	
	bool bReadingBody = false;
	bool bDialogueReading = false;
	int BodyLinesNumber = 0;
	int PureLineIndex = 0;
	int DialoguesFound = 0;
	
	for (const FString& Line : Lines)
	{
		UE_LOG(LogEditorFactories, VeryVerbose, TEXT("Yarn Import: %s"), *Line);
		
		
		//Titolo dialogo
		if(Line.StartsWith(TEXT("title:"))) 
		{
			CurrentDialogue.InternalName = FName(*Line.RightChop(6).TrimStart());
			bDialogueReading = true;
			DialoguesFound++;
		}
		if(Line.StartsWith(TEXT("name:"))) 
		{
			CurrentDialogue.Name = FName(*Line.RightChop(5).TrimStart());
		}
		if(Line.StartsWith(TEXT("tag:"))) 
		{
			TArray<FString> Tags;
			Line.RightChop(4).ParseIntoArray(Tags, TEXT(","),true);

			for (FString Tag : Tags)
			{
				CurrentDialogue.Tags.Add(FName(*Tag.TrimStartAndEnd()));
			}
		}
		
		//inizio testo
		else if(Line.StartsWith(TEXT("---"))) 
		{
			bReadingBody = true;
			BodyLinesNumber = 0;
			PureLineIndex = 0;
		}
		//fine testo
		else if(Line.StartsWith(TEXT("==="))) 
		{
			UE_LOG(LogEditorFactories, Display, TEXT("Yarn Import: Closing body with %i Lines"), BodyLinesNumber);
			bReadingBody = false;
			bDialogueReading = false;
			DialogueTemps.Add(CurrentDialogue);
			CurrentDialogue = FDialogueTemp();
			PreviousLine = FLineTemp();
		}
		// Linee di testo
		else if (bReadingBody && bDialogueReading) 
		{
			// comment
			if (Line.StartsWith(TEXT("//"))) 
			{
				continue;
			}
			
			BodyLinesNumber++;
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
				Inner.ParseIntoArray(CommandTemp, TEXT(" "));
				
				//mi salvo il tutto nella struct
				NewLine.CommandName = FName(*CommandTemp[0]);

				for (int i = 1; i < CommandTemp.Num(); ++i)
				{
					NewLine.Args.Add(*CommandTemp[i]);
				}
				
				CurrentDialogue.Lines.Add(NewLine.Name, NewLine);
				
				if (CurrentDialogue.Lines.Contains(PreviousLine.Name))
				{
					CurrentDialogue.Lines[PreviousLine.Name].NextLines.Add(FName(NewLine.Name));
				}
				PreviousLine = NewLine;
			}
			// Line pure
			else 
			{
				NewLine.Name = FName(*FString::Printf(TEXT("Line_%d"), CurrentDialogue.Lines.Num()));
				NewLine.StringTableID = 
					FName(*FString::Printf(
						TEXT("%s_%d"),
						*CurrentDialogue.InternalName.ToString(),
						PureLineIndex
						));
				
				FString Speaker, Text;
				int32 ColonIndex, HashIndex;

				bool bHasColon = Line.FindChar(TEXT(':'), ColonIndex);
				bool bHasHash  = Line.FindChar(TEXT('#'), HashIndex);

				// Valid speaker token only if:
				// - There is a colon
				// - AND either no '#' exists OR ':' appears before '#'
				if (bHasColon && (!bHasHash || ColonIndex < HashIndex))
				{
					Speaker = Line.Left(ColonIndex);
					Text = Line.Mid(ColonIndex + 1);
				}
				else
				{
					Speaker = TEXT("");
					Text = Line;
				}
				
				NewLine.Protagonist = FName(*Speaker.TrimStartAndEnd());
				
				
				// Emotions
				int TagIndex = Text.Find("#tone:");
				
				if (TagIndex != -1)
				{
					FString Emotion = Text.RightChop(TagIndex + 6);
					NewLine.Emotion = UCoreLibrary::GetEnumFromString<ELineEmotion>(Emotion, ELineEmotion::Neutral);
					NewLine.Text = Text.LeftChop(Text.Len() - TagIndex).TrimStartAndEnd();
				}
				else
				{
					NewLine.Emotion = ELineEmotion::Neutral;
					NewLine.Text = Text.TrimStartAndEnd();
				}

				NewLine.bIsCommand = false;
				
				CurrentDialogue.Lines.Add(NewLine.Name, NewLine);
				
				if (CurrentDialogue.Lines.Contains(PreviousLine.Name))
				{
					CurrentDialogue.Lines[PreviousLine.Name].NextLines.Add(FName(NewLine.Name));
				}
				
				PreviousLine = NewLine;
				
				PureLineIndex++;
			}
		}
		
	}
	
	UE_LOG(LogEditorFactories, Display, TEXT("Yarn Import: Parsing Ended: found %i dialogues"), DialoguesFound);
	return DialogueTemps;
}

UBaseDialogue* UDialogueFactory::SaveObjects(TArray<FDialogueTemp> DialogueTemps, FString FixedFolder)
{
	UE_LOG(LogEditorFactories, Display, TEXT("Yarn Import: Start Saving objects"));
	
	// carico la stringTable dallo WeakRef
	UStringTable* StringTableAsset = DialogueImporterSettings->DialogueStringTable.LoadSynchronous();
	
	bool bHasStringTablePath = IsValid(StringTableAsset);
	
	bool bFirst = true;
	UBaseDialogue* FirstDialogue = nullptr;
	TArray<FLineTemp> LinesToRegister;
	for (auto DialogueTemp : DialogueTemps)
	{
		//saving Path
		FString AssetName = DialogueTemp.InternalName.ToString();
		FString PackageName = FixedFolder + TEXT("/") + AssetName;
		
		//Creo o trovo il package del dialogo
		UPackage* Package = CreatePackage(*PackageName);
		Package->FullyLoad();
		
		UBaseDialogue* Dialogue = FindObject<UBaseDialogue>(Package, *AssetName);
		
		// se non esiste creo l'asset da zero
		if (Dialogue == nullptr)
		{
			Dialogue = NewObject<UBaseDialogue>(
			Package,
			UBaseDialogue::StaticClass(),
			FName(*AssetName),
			RF_Public | RF_Standalone
			);
		}
		else
		{
			// se esiste resetto temporaneamente i suoi valori
			Dialogue->Modify();
			Dialogue->Description = "";
			Dialogue->DialogueName = "";
			Dialogue->Requirements.Reset();
			Dialogue->RootLine = nullptr;
			
			ForEachObjectWithOuter(Dialogue, [](UObject* Obj)
			{
				Obj->MarkAsGarbage();
			});
		}
		
		// notifico la creazione al sistema e setto i package sporchi così posso salvarli manualmente
		FAssetRegistryModule::AssetCreated(Dialogue);
		Dialogue->MarkPackageDirty();
		Package->MarkPackageDirty();
		
		// siccome tecnicamente l'importazione ritorna solo un oggetto creato
		// c'è la necessità di fare questo
		if (bFirst)
		{
			bFirst = false;
			FirstDialogue = Dialogue;
		}
		
		Dialogue->DialogueName = DialogueTemp.Name;

		// riporto i tag validi
		for (FName TagStr : DialogueTemp.Tags)
		{
			FGameplayTag Tag = UGameplayTagsManager::Get().RequestGameplayTag(TagStr, /*ErrorIfNotFound=*/false);
			if (Tag.IsValid())
			{
				Dialogue->Requirements.AddTag(Tag);
			}
		}
		
		TMap<FName, UBaseLineNode*> CreatedNodes;
		
		bool bFirstLine = true;
		
		// ciclo ogni linea per ogni dialogo
		for (const auto& Pair : DialogueTemp.Lines)
		{
			const FLineTemp& LineTemp = Pair.Value;
			
			// creo uno UObject che sarà figlio del dialogo corrente
			UBaseLineNode* Node = NewObject<UBaseLineNode>(
				Dialogue,
				UBaseLineNode::StaticClass(),
				Pair.Key,
				RF_Public | RF_Transactional
			);
			
			// se è il primo lo assegno come root al dialogo
			if (bFirstLine)
			{
				Dialogue->RootLine = Node;
				bFirstLine = false;
			}
			
			// se è di tipo comando allora verrà processato come tale
			if (LineTemp.bIsCommand)
			{
				
				//function args
				TArray<UValue*> CommandArgs;
				for (auto CommandArg : LineTemp.Args)
				{
					CommandArgs.Add(CreateValue(Node, CommandArg));
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
				
				// se la stringTable è valida allora procedo a bindare le Line all'id precalcolato
				if (bHasStringTablePath)
				{
					FTextKey Key = FTextKey(*LineTemp.StringTableID.ToString());
					
					Node->Line = FText::FromStringTable(
						StringTableAsset->GetStringTableId(),
						Key);
				}
				else
				{
					// altrimenti inserisco il testo
					Node->Line = FText::FromString(LineTemp.Text);
				}
				
				Node->LineEmotion = LineTemp.Emotion;
				
				LinesToRegister.Add(LineTemp);
			}
			CreatedNodes.Add(Pair.Key, Node);
		}
		// per ogniuno procedo poi a linkare le line tramite nome
		LinkDialogue(DialogueTemp, CreatedNodes);
	}
	
	// add or update new lines on the stringTable
	if (bHasStringTablePath && LinesToRegister.Num() > 0)
	{
		// modifico per permettere il roolback
		StringTableAsset->Modify();
		
		FStringTableRef StringTable = StringTableAsset->GetMutableStringTable();
		
		// aggiungo o aggiorno le linee di dialogo nella tabella
		AddToStringTable(StringTable ,LinesToRegister);
		
		// marchio sporco per permettere il salvataggio
		StringTableAsset->MarkPackageDirty();
	}
	
	int ImportNumber = DialogueTemps.Num();
	
	UE_LOG(LogEditorFactories, Display, TEXT("Yarn Import: End: %i imported"), ImportNumber);
	return FirstDialogue;
}




