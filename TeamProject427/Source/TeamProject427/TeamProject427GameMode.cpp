// Copyright Epic Games, Inc. All Rights Reserved.

#include "TeamProject427GameMode.h"
#include "TeamProject427PlayerController.h"
#include "TeamProject427Character.h"
#include "UObject/ConstructorHelpers.h"

ATeamProject427GameMode::ATeamProject427GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATeamProject427PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}