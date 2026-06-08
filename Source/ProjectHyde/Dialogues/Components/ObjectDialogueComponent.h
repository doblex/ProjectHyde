// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseDialogueRunnerComponent.h"
#include "ObjectDialogueComponent.generated.h"

UENUM(BlueprintType)
enum class EObjectPointState : uint8
{
	Seen,
	AlreadySeen,
	Collected,
	
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTHYDE_API UObjectDialogueComponent : public UBaseDialogueRunnerComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UObjectDialogueComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dialogue")
	TMap<EObjectPointState, UBaseDialogue*> ObjectState;
	
	UFUNCTION(BlueprintCallable, Category="Dialogues")
	bool StartDialogue(EObjectPointState State, UBaseLineNode*& OutDialogue);
};
