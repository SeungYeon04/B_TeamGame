#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "isteamnetworkingsockets.h"
#include "steam_api.h"
#include "SteamSocketsTest.generated.h"

UCLASS()
class TEAMPROJECT427_API ASteamSocketsTest : public AActor
{
	GENERATED_BODY()

public:
	ASteamSocketsTest();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// Steam API 초기화 함수
	bool InitializeSteamAPI();
};