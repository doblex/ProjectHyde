
#include "BaseLineNode.h"

#include "ProjectHyde/Dialogues/DialogueStructs.h"

UBaseLineNode::UBaseLineNode()
:  Command()
{
}

UBaseLineNode::UBaseLineNode(const FName& Name, const FText& Line, UBaseLineNode* NextLine)
: LineProtagonistName(Name), Line(Line)
{
	Type = EDialogueLineType::Line;
	
	if (NextLine)
	{
		NextLines.Add(NextLine);
	}
}

UBaseLineNode::UBaseLineNode(const FName& Name, const FText& Line, FDialogueCommandLine Command,
	UBaseLineNode* NextLine)
		: LineProtagonistName(Name), Line(Line), Command(Command)
{
	Type = EDialogueLineType::Command;
	
	if (NextLine)
	{
		NextLines.Add(NextLine);
	}
}

UBaseLineNode::UBaseLineNode(const FName& Name, const FText& Line, const TArray<UBaseLineNode*> NextLines)
: LineProtagonistName(Name), Line(Line), NextLines(NextLines)
{
	Type = EDialogueLineType::Selector;
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
