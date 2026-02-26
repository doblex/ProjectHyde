// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectHyde/Core/Subsystems/Dialogues/DialogueExecutorSubsystem.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseDialogue.h"
#include "DialogueRunnerComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTHYDE_API UDialogueRunnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDialogueRunnerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UDialogueExecutorSubsystem* DialogueSub;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UBaseDialogue*> DialoguesPool;
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	TArray<UBaseDialogue*> PresentDialogues();
	
	UFUNCTION(BlueprintCallable)
	UBaseLineNode* StartDialogue(UBaseDialogue* Dialogue);
	
	UFUNCTION()
	void OnDialogueEnded(UBaseDialogue* BaseDialogue);

	void SetNextDialogue(FName DialogueName);
};
