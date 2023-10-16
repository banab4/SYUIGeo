// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SYGeometryWidget.generated.h"

/**
 * 
 */
 class UCanvasPanel;
UCLASS()
class GEOMETRY_API USYGeometryWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	UPROPERTY(meta=(BindWidget))
	UCanvasPanel* CP;
};
