// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseDialogueRunnerComponent.h"
#include "PersonDialogueComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTHYDE_API UPersonDialogueComponent : public UBaseDialogueRunnerComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPersonDialogueComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UBaseDialogue*> DialoguesPool;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FOnAfterWelcomeDialogue OnAfterWelcome;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBaseDialogue* WelcomeDialogue;

	UFUNCTION(BlueprintCallable)
	UBaseLineNode* StartDialogue(UBaseDialogue* Dialogue);
	
	UFUNCTION(BlueprintCallable, Category="Dialogues")
	TArray<UBaseDialogue*> PresentDialogues();
	
	UFUNCTION(BlueprintCallable, Category="Dialogues")
	UBaseLineNode* StartWelcomeDialogue();
	
	UFUNCTION()
	void OnWelcomeDialogueEnded(UBaseDialogue* BaseDialogue);
	
	virtual void OnDialogueEnded(UBaseDialogue* BaseDialogue) override;
	
};


