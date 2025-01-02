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

    void ConnectToServer(); // ���� ���� �Լ�
    void SendP2PMessage(const char* Message); // P2P �޽��� ����
    void SendP2PMessage(const FString& Message);
    void ReceiveP2PMessage(); // P2P �޽��� ����

private:
    bool InitializeSteamAPI(); // Steam API �ʱ�ȭ
    void InitializeSocket(); // ���� �ʱ�ȭ

    HSteamNetConnection Connection;       // P2P ����
    HSteamListenSocket ListenSocket;      // P2P ���� ����
    TArray<HSteamNetConnection> Peers;    // ����� �Ǿ��

    FString NodeIdentifier;               // ��� �ĺ���

public:

    // ��Ī ���� �Լ� (��ư���� ȣ��)
    UFUNCTION(BlueprintCallable, Category = "Networking")
    void StartP2P(); // ��Ī ����

};