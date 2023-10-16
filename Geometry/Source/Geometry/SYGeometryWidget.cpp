// Fill out your copyright notice in the Description page of Project Settings.


#include "SYGeometryWidget.h"

#include "Blueprint/SlateBlueprintLibrary.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/PanelWidget.h"

void USYGeometryWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(CP->Slot))
	{
		FVector2D MousePosition;
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (PlayerController)
		{
			PlayerController->GetMousePosition(MousePosition.X, MousePosition.Y);
		}
		
		FVector2D AbsolutePos;
		USlateBlueprintLibrary::ScreenToWidgetAbsolute(this, MousePosition, AbsolutePos);
		FVector2D LocalPos = CP->GetParent()->GetCachedGeometry().AbsoluteToLocal(AbsolutePos);

		CanvasSlot->SetPosition(LocalPos);
	}
}
