// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHyde/Dialogues/BaseClasses/BaseLineNode.h"
#include "UObject/Object.h"
#include "CharacterDataRow.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FEmotionSound
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELineEmotion EmotionType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* SoundAsset;
};




USTRUCT(BlueprintType)
struct PROJECTHYDE_API FCharacterDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Character;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsLeftSide;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor CharacterColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(TitleProperty="EmotionType"))
	TArray<FEmotionSound> EmotionSounds;
	
	bool GetEmotion(ELineEmotion EmotionToSearch, USoundBase*& OutResult);
	
protected:
#ifdef IF_WITH_EDITOR
	virtual void OnDataTableChanged(const UDataTable* InDataTable, const FName InRowName) override;
#endif
	
private:
	void SyncArray();
};
