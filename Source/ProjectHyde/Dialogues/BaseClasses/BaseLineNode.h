#pragma once
#include "ProjectHyde/Dialogues/DialogueStructs.h"

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
class PROJECTHYDE_API UBaseLineNode : public UDataAsset
{
	GENERATED_BODY()

public:
	UBaseLineNode();
	
	UBaseLineNode(const FName& Name, const FText& Line, UBaseLineNode* NextLine = nullptr);

	UBaseLineNode(const FName& Name, const FText& Line, const  TArray<UBaseLineNode*> NextLines);
	
	UBaseLineNode(const FName& Name, const FText& Line, FDialogueCommandLine Command  ,UBaseLineNode* NextLine = nullptr);

protected:
	
	UPROPERTY(EditAnywhere, Category = "Dialogue")
	FName LineProtagonistName;
	
	UPROPERTY(EditAnywhere, Category = "Dialogue")
	EDialogueLineType Type;
	
	UPROPERTY(EditAnywhere, Category = "Dialogue")
	FText Line;
	
	UPROPERTY(EditAnywhere, Category = "Dialogue")
	FDialogueCommandLine Command;

public:
	FDialogueCommandLine GetCommand() const
	{
		return Command;
	}

protected:
	UPROPERTY(EditAnywhere, Category = "Dialogue")
	TArray<UBaseLineNode*> NextLines;
	
public:
	
	FText GetLineText() const;
	
	UBaseLineNode* GetNextLine(int index = 0);
	
	bool IsLine();
	bool IsCommand();
	bool IsSelector();
	
	bool HasNextLine();
};
