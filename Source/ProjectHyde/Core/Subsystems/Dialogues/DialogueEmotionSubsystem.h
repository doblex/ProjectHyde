// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseLineNode.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DialogueEmotionSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UDialogueEmotionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected:
	UDataTable* CharacterEmotionSoundTable;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void Deinitialize() override;
	
public:
	UFUNCTION(BlueprintCallable, Category = "Game|Subsystem|DialogueEmotion")
	bool GetEmotionSound(FName CharacterName, ELineEmotion EmotionToGet, USoundBase*& OutSoundAsset);
};
