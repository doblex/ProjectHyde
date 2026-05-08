#pragma once
#include "ProjectHyde/Actors/Components/CPP_NotebookComponent.h"
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

UENUM(BlueprintType)
enum class ELineEmotion : uint8
{
	Neutral,
	Question,
	Nervous,
	Happy,
	Distressed,
	Sad,
	Haughty,
	Sigh,
	Serious,
	Angry,
	Thinking,
	Laugh,
	Scared,
	Tired,
	Conflicted,
	Sarcastic,
	Hopeful,
	MAX UMETA(Hidden)
};

UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class PROJECTHYDE_API UBaseLineNode : public UObject
{
	GENERATED_BODY()

public:
	UBaseLineNode();
	
	// UBaseLineNode(const FName& Name, const FText& Line, UBaseLineNode* NextLine = nullptr);
	//
	// UBaseLineNode(const FName& Name, const FText& Line, const  TArray<UBaseLineNode*> NextLines);
	//
	// UBaseLineNode(const FName& Name, const FText& Line, FDialogueCommandLine Command  ,UBaseLineNode* NextLine = nullptr);
	
	UPROPERTY(EditAnywhere ,BlueprintReadOnly ,Category = "Dialogue")
	FName LineProtagonistName;
	
	UPROPERTY(EditAnywhere, Category = "Dialogue")
	EDialogueLineType Type = EDialogueLineType::Line;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Dialogue")
	ELineEmotion LineEmotion = ELineEmotion::Neutral;
	
	UPROPERTY(EditAnywhere ,BlueprintReadOnly, Category = "Dialogue")
	FText Line;
	
	UPROPERTY(EditAnywhere, Category = "Dialogue")
	FDialogueCommandLine Command;
	
	UPROPERTY(EditAnywhere, Category = "Dialogue")
	TArray<UBaseLineNode*> NextLines;
	
	FDialogueCommandLine GetCommand() const
	{
		return Command;
	}
	
	FText GetLineText() const;
	
	UBaseLineNode* GetNextLine(int index = 0);
	
	FLineLog GetLineLog() const;
	
	bool IsLine();
	bool IsCommand();
	bool IsSelector();
	
	bool HasNextLine();
};
