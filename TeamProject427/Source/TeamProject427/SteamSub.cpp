// Fill out your copyright notice in the Description page of Project Settings.

#include "SteamSub.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"


// Sets default values
ASteamSub::ASteamSub()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// 게임시작시호출 
void ASteamSub::BeginPlay()
{
	Super::BeginPlay();
	
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if (OnlineSubsystem)
	{
		OnlineSubsystem->GetSessionInterface();

		if (GEngine)
		{
			GetWorld()->SpawnActor<ASteamSub>();
			GEngine->bEnableOnScreenDebugMessages = true;
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Blue,
				FString::Printf(TEXT("Found Subsystem %s"), *OnlineSubsystem->GetSubsystemName().ToString())
			);
		}
		else if (GEngine)
		{
			GEngine->bEnableOnScreenDebugMessages = true;
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Red,
				TEXT("Session Interface is not valid!")
			);
		}
	}
	else if (GEngine)
	{
		GEngine->bEnableOnScreenDebugMessages = true;
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Red,
			TEXT("No Online Subsystem found!")
		);
	}
	else if (!GEngine)
	{
		UE_LOG(LogTemp, Error, TEXT("GEngine is NULL!"));
		return;
	}
}

// Called every frame
void ASteamSub::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

