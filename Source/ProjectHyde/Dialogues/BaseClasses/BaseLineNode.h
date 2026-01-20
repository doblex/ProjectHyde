#pragma once

#include "BaseLineNode.generated.h"

struct FDialogueCommandLine;

UENUM()
enum class EDialogueLineType : uint8
{
	Line,
	Command,
	Selector
};

UCLASS()
class PROJECTHYDE_API UBaseLineNode : public UObject
{
	GENERATED_BODY()

public:
	UBaseLineNode();
	
	UBaseLineNode(const FName& Name, const FText& Line, UBaseLineNode* NextLine = nullptr);

	UBaseLineNode(const FName& Name, const FText& Line, const  TArray<UBaseLineNode*> NextLines);
	
	UBaseLineNode(const FName& Name, const FText& Line, FDialogueCommandLine Command  ,UBaseLineNode* NextLine = nullptr);

protected:
	FName Name;
	EDialogueLineType Type;
	
	FText Line;
	FDialogueCommandLine* Command;
	TArray<UBaseLineNode*> NextLines;
	
	
public:
	UBaseLineNode* GetNextLine(int index = 0);
};
