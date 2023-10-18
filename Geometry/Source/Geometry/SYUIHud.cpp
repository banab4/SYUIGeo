// Fill out your copyright notice in the Description page of Project Settings.


#include "SYUIHud.h"

#include "SYUIPartySlot.h"
#include "SYUIPopup.h"
#include "Components/CanvasPanel.h"
#include "Components/Overlay.h"

void USYUIHud::Attach(ESYPopupType PopupType)
{
	if (PopupType == ESYPopupType::Mouse)
	{
		Layer->AddChild(Popup);
	}
	if (PopupType == ESYPopupType::PartySlot)
	{
		WC_PartySlot->CP_Holder->AddChild(Popup);
	}

	Popup->OnAttached(PopupType);
}

void USYUIHud::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	Popup = CreateWidget<USYUIPopup>(this, PopupClass);
}
