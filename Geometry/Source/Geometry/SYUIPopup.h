// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "SYUIPopup.generated.h"

UENUM()
enum class ESYPopupType : uint8
{
	Mouse,
	PartySlot,
};

class UCanvasPanel;
UCLASS()
class GEOMETRY_API USYUIPopup : public UUserWidget
{
	GENERATED_BODY()

public:
	void OnAttached(ESYPopupType PopupMode);

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	UPROPERTY(meta=(BindWidget))
	UCanvasPanel* CP;

	UPROPERTY(EditDefaultsOnly)
	FAnchorData MouseModeAnchorData;

	UPROPERTY(EditDefaultsOnly)
	FAnchorData PartySlotModeAnchorData;

private:
	bool bPendingUpdate;
	ESYPopupType CurrentPopupMode;
};
