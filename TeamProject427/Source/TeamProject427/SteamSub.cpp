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
	
    // 스팀 서브시스템 확인
    IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
    if (OnlineSubsystem)
    {
        FString SubsystemName = OnlineSubsystem->GetSubsystemName().ToString();

        if (OnlineSubsystem)
        {
            OnlineSubsystem->GetSessionInterface();
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("No Online Subsystem found!"));
        }
    }
}

// Called every frame
void ASteamSub::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

