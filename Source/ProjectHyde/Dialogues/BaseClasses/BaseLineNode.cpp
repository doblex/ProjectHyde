
#include "BaseLineNode.h"

#include "ProjectHyde/Dialogues/DialogueStructs.h"

UBaseLineNode::UBaseLineNode()
:  Command()
{
}

UBaseLineNode::UBaseLineNode(const FName& Name, const FText& Line, UBaseLineNode* NextLine)
: Name(Name), Line(Line)
{
	Type = EDialogueLineType::Line;
	
	if (NextLine)
	{
		NextLines.Add(NextLine);
	}
}

UBaseLineNode::UBaseLineNode(const FName& Name, const FText& Line, FDialogueCommandLine Command,
	UBaseLineNode* NextLine)
		: Name(Name), Line(Line), Command(&Command)
{
	Type = EDialogueLineType::Command;
	
	if (NextLine)
	{
		NextLines.Add(NextLine);
	}
}

UBaseLineNode::UBaseLineNode(const FName& Name, const FText& Line, const TArray<UBaseLineNode*> NextLines)
: Name(Name), Line(Line), NextLines(NextLines)
{
	Type = EDialogueLineType::Selector;
}

UBaseLineNode* UBaseLineNode::GetNextLine(int index)
{
	if (NextLines.IsEmpty()) return nullptr;
	
	return NextLines[index];
}
