// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E:\epic games\UE_5.6\Engine\Plugins\Runtime\CommonUI\Source\CommonUI\Public\CommonUserWidget.h"
#include "ProjectHyde/Interface/Hintable.h"
#include "HintableCommonUserWidget.generated.h"
/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UHintableCommonUserWidget : public UCommonUserWidget, public IHintable
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintCallable)
	FOnHintActivation OnHintActivation;
	
	virtual FOnHintActivation& GetOnHintActivationDelegate() override;
};
