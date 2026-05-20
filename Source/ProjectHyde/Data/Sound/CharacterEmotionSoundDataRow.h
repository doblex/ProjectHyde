// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseLineNode.h"
#include "UObject/Object.h"
#include "CharacterEmotionSoundDataRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PROJECTHYDE_API FCharacterEmotionSoundDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Character;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELineEmotion EmotionType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* SoundAsset;
};
