// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseHoverSubsystem.h"
#include "Components/Viewport.h"

bool UMouseHoverSubsystem::IsMouseInsideWidget(UUserWidget* Widget)
{
	FVector2D Local = GetMousePositionInWidget(Widget);
	FVector2D Size = Widget->GetCachedGeometry().GetLocalSize();

	return Local.X >= 0 && Local.Y >= 0 &&
		   Local.X <= Size.X && Local.Y <= Size.Y;
}

FVector2D UMouseHoverSubsystem::GetMousePositionInWidget(UUserWidget* Widget)
{
	if (!Widget) return FVector2D::ZeroVector;

	FGeometry Geometry = Widget->GetCachedGeometry();

	FVector2D CursorPos = FSlateApplication::Get().GetCursorPos();

	return Geometry.AbsoluteToLocal(CursorPos);
}