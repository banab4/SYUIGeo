// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SYUIPartySlot.generated.h"

class UCanvasPanel;
UCLASS()
class GEOMETRY_API USYUIPartySlot : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(BindWidget))
	UCanvasPanel* CP_Holder;
};
