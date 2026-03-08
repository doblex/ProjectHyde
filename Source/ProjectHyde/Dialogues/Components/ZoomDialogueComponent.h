// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseDialogueRunnerComponent.h"
#include "ZoomDialogueComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTHYDE_API UZoomDialogueComponent : public UBaseDialogueRunnerComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UZoomDialogueComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category="Dialogues")
	UBaseLineNode*  StartDialogue();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dialogues")
	UBaseDialogue* Dialogue;
};
