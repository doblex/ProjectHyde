
#include "BaseLineNode.h"

#include "ProjectHyde/Dialogues/DialogueStructs.h"

UBaseLineNode::UBaseLineNode()
:  Command()
{
}

// UBaseLineNode::UBaseLineNode(const FName& Name, const FText& Line, UBaseLineNode* NextLine)
// : LineProtagonistName(Name), Line(Line)
// {
// 	Type = EDialogueLineType::Line;
// 	
// 	if (NextLine)
// 	{
// 		NextLines.Add(NextLine);
// 	}
// }
//
// UBaseLineNode::UBaseLineNode(const FName& Name, const FText& Line, FDialogueCommandLine Command,
// 	UBaseLineNode* NextLine)
// 		: LineProtagonistName(Name), Line(Line), Command(Command)
// {
// 	Type = EDialogueLineType::Command;
// 	
// 	if (NextLine)
// 	{
// 		NextLines.Add(NextLine);
// 	}
// }
//
// UBaseLineNode::UBaseLineNode(const FName& Name, const FText& Line, const TArray<UBaseLineNode*> NextLines)
// : LineProtagonistName(Name), Line(Line), NextLines(NextLines)
// {
// 	Type = EDialogueLineType::Selector;
// }

FText UBaseLineNode::GetLineText() const
{  
	#define LOCTEXT_NAMESPACE "DialogueSystem"

	// The pattern is compiled once
	static const FTextFormat DialogueFormat = LOCTEXT("LineText", "{0} : {1}");

	// Convert FName to FText explicitly
	FText Result = FText::Format(
		DialogueFormat, 
		FText::FromName(LineProtagonistName), // Fix: FName -> FText
		Line                                  // Assuming 'Line' is already FText
	);

	#undef LOCTEXT_NAMESPACE

	return Result;
}

UBaseLineNode* UBaseLineNode::GetNextLine(int index)
{
	if (NextLines.IsEmpty()) return nullptr;
	
	return NextLines[index];
}

bool UBaseLineNode::IsLine()
{
	return Type == EDialogueLineType::Line;
}

bool UBaseLineNode::IsCommand()
{
	return Type == EDialogueLineType::Command;
}

bool UBaseLineNode::IsSelector()
{
	return Type == EDialogueLineType::Selector;
}

bool UBaseLineNode::HasNextLine()
{
	return !NextLines.IsEmpty();
}
