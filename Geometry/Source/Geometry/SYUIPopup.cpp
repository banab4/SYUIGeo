// Fill out your copyright notice in the Description page of Project Settings.


#include "SYUIPopup.h"

#include "Blueprint/SlateBlueprintLibrary.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

void USYUIPopup::OnAttached(ESYPopupType PopupMode)
{
	bPendingUpdate = true;
	CurrentPopupMode = PopupMode;
}

void USYUIPopup::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (bPendingUpdate)
	{
		bPendingUpdate = false;
		
		if (CurrentPopupMode == ESYPopupType::Mouse)
		{
			if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(CP->Slot))
			{
				CanvasSlot->SetLayout(MouseModeAnchorData);

				FVector2D MousePosition;
				if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
				{
					PlayerController->GetMousePosition(MousePosition.X, MousePosition.Y);
				}
		
				FVector2D AbsolutePos;
				USlateBlueprintLibrary::ScreenToWidgetAbsolute(this, MousePosition, AbsolutePos);
				FVector2D LocalPos = MyGeometry.AbsoluteToLocal(AbsolutePos);
				CanvasSlot->SetPosition(LocalPos);
			}
		}
		else if (CurrentPopupMode == ESYPopupType::PartySlot)
		{
			if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(CP->Slot))
			{
				CanvasSlot->SetLayout(PartySlotModeAnchorData);
				CanvasSlot->SetPosition(FVector2D::Zero());
			}
		}
	}
	
}
