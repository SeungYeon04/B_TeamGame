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

    if (InitializeSteamAPI())
    {
        UE_LOG(LogTemp, Log, TEXT("Steam API ����."));

        // ���� �ʱ�ȭ
        InitializeSocket();
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

// ���� �ʱ�ȭ
void ASteamSocketsTest::InitializeSocket()
{
    // SteamNetworkingSockets �������̽� ��������
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("Steam Networking Sockets �ʱ�ȭ ����."));
        return;
    }

    // ���� �ּ� ����
    SteamNetworkingIPAddr LocalAddress;
    LocalAddress.Clear();
    LocalAddress.SetIPv4(0x7F000001, 12345); // 127.0.0.1:12345

    // ���� ���� ����
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

// ������ ����
void ASteamSocketsTest::ConnectToServer()
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("Steam Networking Sockets �ʱ�ȭ ����."));
        return;
    }

    // ���� �ּ� ����
    SteamNetworkingIPAddr ServerAddress;
    ServerAddress.Clear();
    ServerAddress.SetIPv4(0x7F000001, 12345); // 127.0.0.1:12345

    // ������ ����
    Connection = SteamNetworking->ConnectByIPAddress(ServerAddress, 0, nullptr);
    if (Connection != k_HSteamNetConnection_Invalid)
    {
        UE_LOG(LogTemp, Log, TEXT("���� ���� ����."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("���� ���� ����."));
    }
}

// P2P �޽��� ����
void ASteamSocketsTest::SendP2PMessage(const char* Message)
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking || Connection == k_HSteamNetConnection_Invalid)
    {
        UE_LOG(LogTemp, Error, TEXT("�޽��� ���� ����: ������� ����."));
        return;
    }

    SteamNetworking->SendMessageToConnection(Connection, Message, strlen(Message) + 1, k_nSteamNetworkingSend_Reliable, nullptr);
    UE_LOG(LogTemp, Log, TEXT("P2P �޽��� ����: %s"), *FString(Message));
}

void ASteamSocketsTest::SendP2PMessage(const FString& Message)
{
    SendP2PMessage(TCHAR_TO_UTF8(*Message));
}

// P2P �޽��� ���� (Tick �Լ����� �ֱ������� ȣ��)
void ASteamSocketsTest::ReceiveP2PMessage()
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("�޽��� ���� ����: SteamNetworkingSockets ����."));
        return;
    }

    ISteamNetworkingMessage* Messages[10] = { nullptr }; // �ִ� 10���� �޽����� ����
    int NumMessages = SteamNetworking->ReceiveMessagesOnConnection(Connection, Messages, 10);

    if (NumMessages > 0)
    {
        for (int i = 0; i < NumMessages; ++i)
        {
            FString ReceivedMessage(UTF8_TO_TCHAR((char*)Messages[i]->m_pData));
            UE_LOG(LogTemp, Log, TEXT("P2P �޽��� ����: %s"), *ReceivedMessage);

            // �޽��� ����
            Messages[i]->Release();
        }
    }
    else if (NumMessages < 0)
    {
        UE_LOG(LogTemp, Error, TEXT("�޽��� ���� ����."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("���ŵ� �޽����� �����ϴ�."));
    }
}

// �� ������ ȣ��
void ASteamSocketsTest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // �޽��� ����
    ReceiveP2PMessage();
}
