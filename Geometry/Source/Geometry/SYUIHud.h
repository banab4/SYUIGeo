// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SYUIPopup.h"
#include "SYUIHud.generated.h"

class USYUIPartySlot;
class UOverlay;
class USYUIPopup;

UCLASS()
class GEOMETRY_API USYUIHud : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Attach(ESYPopupType PopupType);
	
protected:
	virtual void NativeOnInitialized() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<USYUIPopup> PopupClass;

	UPROPERTY()
	USYUIPopup* Popup;

	UPROPERTY(meta=(BindWidget))
	UOverlay* Layer;

	UPROPERTY(meta=(BindWidget))
	USYUIPartySlot* WC_PartySlot;
};
