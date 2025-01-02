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

    void ConnectToServer(); // 서버 연결 함수
    void SendP2PMessage(const char* Message); // P2P 메시지 전송
    void SendP2PMessage(const FString& Message);
    void ReceiveP2PMessage(); // P2P 메시지 수신

private:
    bool InitializeSteamAPI(); // Steam API 초기화
    void InitializeSocket(); // 소켓 초기화

    HSteamNetConnection Connection;       // P2P 연결
    HSteamListenSocket ListenSocket;      // P2P 리슨 소켓
    TArray<HSteamNetConnection> Peers;    // 연결된 피어들

    FString NodeIdentifier;               // 노드 식별자

public:

    // 매칭 시작 함수 (버튼으로 호출)
    UFUNCTION(BlueprintCallable, Category = "Networking")
    void StartP2P(); // 매칭 시작

};