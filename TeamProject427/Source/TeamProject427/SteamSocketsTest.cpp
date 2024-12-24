#include "SteamSocketsTest.h"
#include "isteamnetworkingsockets.h"
#include "steam_api.h"

/**����: ISteamNetworkingSockets ��  Steam ��Ʈ��ũ�� ���� P2P ������ ���� 
���� ����, �ǽð� ��Ƽ�÷��̾� ������ ���� */ 

ASteamSocketsTest::ASteamSocketsTest()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASteamSocketsTest::BeginPlay()
{
	Super::BeginPlay();

	if (InitializeSteamAPI())
	{
		UE_LOG(LogTemp, Log, TEXT("Steam API ����."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Steam API ����."));
	}
}

// Steam API �ʱ�ȭ �Լ�
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

