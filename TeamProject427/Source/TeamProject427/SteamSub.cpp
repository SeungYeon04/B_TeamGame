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

// ���ӽ��۽�ȣ�� 
void ASteamSub::BeginPlay()
{
	Super::BeginPlay();
	
    // ���� ����ý��� Ȯ��
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

