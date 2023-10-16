// Copyright Epic Games, Inc. All Rights Reserved.

#include "GeometryGameMode.h"
#include "GeometryCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGeometryGameMode::AGeometryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
