// Copyright Epic Games, Inc. All Rights Reserved.

#include "teamgameGameMode.h"
#include "teamgamePlayerController.h"
#include "teamgameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AteamgameGameMode::AteamgameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AteamgamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}