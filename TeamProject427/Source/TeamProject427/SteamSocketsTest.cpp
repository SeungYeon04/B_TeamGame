#include "SteamSocketsTest.h"
#include "isteamnetworkingsockets.h"
#include "steam_api.h"
#include <string>

/**
 * ����: ISteamNetworkingSockets�� Steam ��Ʈ��ũ�� ���� P2P ������ ����
 * ���� ����, �ǽð� ��Ƽ�÷��̾� ������ ����
 */

ASteamSocketsTest::ASteamSocketsTest()
{
    PrimaryActorTick.bCanEverTick = true;
    ListenSocket = k_HSteamListenSocket_Invalid;
    Connection = k_HSteamNetConnection_Invalid;
}

void ASteamSocketsTest::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Log, TEXT("StartP2P �Լ��� ȣ��Ǿ����ϴ�."));

    UWorld* World = GetWorld();
    if (World)
    {
        AActor* Actor = World->SpawnActor<ASteamSocketsTest>();
        if (Actor)
        {
            UE_LOG(LogTemp, Log, TEXT("ASteamSocketsTest has been spawned!"));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to spawn ASteamSocketsTest."));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("World is NULL! Cannot spawn ASteamSocketsTest."));
    }


    if (InitializeSteamAPI())
    {
        UE_LOG(LogTemp, Log, TEXT("Steam API �ʱ�ȭ ����."));

        // ���� �ʱ�ȭ
        InitializeSocket();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Steam API �ʱ�ȭ ����."));
    }

   
}

// Steam API �ʱ�ȭ
bool ASteamSocketsTest::InitializeSteamAPI()
{
    return SteamAPI_Init();
}

// ���� �ʱ�ȭ
void ASteamSocketsTest::InitializeSocket()
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("Steam Networking Sockets �ʱ�ȭ ����."));
        return;
    }

    SteamNetworkingIPAddr LocalAddress;
    LocalAddress.Clear();
    LocalAddress.SetIPv4(0x7F000001, 12345); // 127.0.0.1:12345

    ListenSocket = SteamNetworking->CreateListenSocketIP(LocalAddress, 0, nullptr);
    if (ListenSocket != k_HSteamListenSocket_Invalid)
    {
        UE_LOG(LogTemp, Log, TEXT("12345 ��Ʈ���� ���� ��� ��."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("���� ���� ���� ����."));
    }
}

// P2P �޽��� ����
void ASteamSocketsTest::SendP2PMessage(const FString& Message)
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking || Connection == k_HSteamNetConnection_Invalid)
    {
        UE_LOG(LogTemp, Error, TEXT("�޽��� ���� ����: ������� ����."));
        return;
    }

    SteamNetworking->SendMessageToConnection(Connection, TCHAR_TO_UTF8(*Message), Message.Len() + 1, k_nSteamNetworkingSend_Reliable, nullptr);
    UE_LOG(LogTemp, Log, TEXT("P2P �޽��� ����: %s"), *Message);
}

// P2P �޽��� ����
void ASteamSocketsTest::ReceiveP2PMessage()
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("�޽��� ���� ����: SteamNetworkingSockets ����."));
        return;
    }

    ISteamNetworkingMessage* Messages[10] = { nullptr };
    int NumMessages = SteamNetworking->ReceiveMessagesOnConnection(Connection, Messages, 10);

    for (int i = 0; i < NumMessages; ++i)
    {
        FString ReceivedMessage(UTF8_TO_TCHAR((char*)Messages[i]->m_pData));
        UE_LOG(LogTemp, Log, TEXT("P2P �޽��� ����: %s"), *ReceivedMessage);
        Messages[i]->Release();
    }
}

void ASteamSocketsTest::StartP2P()
{
    UE_LOG(LogTemp, Log, TEXT("StartP2P �Լ��� ȣ��Ǿ����ϴ�."));
    // �߰����� P2P �ʱ�ȭ �ڵ尡 �ʿ��ϸ� ���⿡ �ۼ��մϴ�.
}


// �� ������ ȣ��
void ASteamSocketsTest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ReceiveP2PMessage();
}
