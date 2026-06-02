// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetReturnStackSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "ProjectHyde/Core/DevSettings/WidgetSettings.h"
#include "ProjectHyde/Interface/Widget/WidgetBackAction.h"

void UWidgetReturnStackSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	const UWidgetSettings* Settings = GetDefault<UWidgetSettings>();
	
	if (Settings)
	{
		bDebugLogs = Settings->bDebugLogs;
	}
}

void UWidgetReturnStackSubsystem::AddToStack(UUserWidget* WidgetToAdd)
{
	OpenedWidgets.Add(WidgetToAdd);
	
	if (WidgetToAdd->Implements<UWidgetBackAction>())
	{
		WidgetStack.Push(WidgetToAdd);
		OpenedWidgets.Add(WidgetToAdd);
		
		if (bDebugLogs && GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Green,
				"Element Added"
				);
		}
	}
}

void UWidgetReturnStackSubsystem::RemoveFromStack(UUserWidget* WidgetToRemove)
{
	OpenedWidgets.Remove(WidgetToRemove);
	WidgetStack.Remove(WidgetToRemove);
	
	if (bDebugLogs && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Green,
			"Element Removed"
			);
	}
	
	if (WidgetStack.IsEmpty())
	{
		OnEmptyStack.ExecuteIfBound();
	}
}

void UWidgetReturnStackSubsystem::CloseLastElement()
{
	if (WidgetStack.IsEmpty()) return;
	
	UUserWidget* Widget = WidgetStack.Top();
	
	if (IWidgetBackAction::Execute_CloseWidget(Widget))
	{
		WidgetStack.Pop();
		OpenedWidgets.Remove(Widget);
		
		if (IsUIOpen())
		{
			OnEmptyStack.ExecuteIfBound();
		}
		
		if (bDebugLogs && GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Green,
				"Element Popped" 
				);
		}
	}
}

FString UWidgetReturnStackSubsystem::GetInfo()
{
	FString text;
	text.Append("Next Widget:" + (WidgetStack.IsEmpty() ? "" : WidgetStack.Top()->GetName()) + "\n");
	text.Append("Stack Number:" + FString::FromInt(WidgetStack.Num()));
	return text;
}

bool UWidgetReturnStackSubsystem::IsUIOpen()
{
	return OpenedWidgets.IsEmpty();
}


