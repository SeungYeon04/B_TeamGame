#include "SteamSocketsTest.h"
#include "isteamnetworkingsockets.h"
#include "steam_api.h"

/**설명: ISteamNetworkingSockets 는  Steam 네트워크를 통해 P2P 연결을 제공 
연결 관리, 실시간 멀티플레이어 데이터 전송 */ 

ASteamSocketsTest::ASteamSocketsTest()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASteamSocketsTest::BeginPlay()
{
	Super::BeginPlay();

	if (InitializeSteamAPI())
	{
		UE_LOG(LogTemp, Log, TEXT("Steam API 성공."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Steam API 실패."));
	}
}

// Steam API 초기화 함수
bool ASteamSocketsTest::InitializeSteamAPI()
{
	if (SteamAPI_Init())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called every frame
void ASteamSocketsTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

