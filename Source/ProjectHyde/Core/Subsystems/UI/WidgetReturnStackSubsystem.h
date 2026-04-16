// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "WidgetReturnStackSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHYDE_API UWidgetReturnStackSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
	TArray<UUserWidget*> WidgetStack;
	bool bDebugLogs = false;
	
	protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
public:
	UFUNCTION(BlueprintCallable, Meta=(DefaultToSelf="WidgetToAdd"))
	void AddToStack(UUserWidget* WidgetToAdd);
	
	UFUNCTION(BlueprintCallable, Meta=(DefaultToSelf="WidgetToRemove"))
	void RemoveFromStack(UUserWidget* WidgetToRemove);
	
	UFUNCTION(BlueprintCallable)
	void CloseLastElement();
	
	UFUNCTION(BlueprintCallable)
	FString GetInfo();
};
