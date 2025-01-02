#include "SteamSocketsTest.h"
#include "isteamnetworkingsockets.h"
#include "steam_api.h"
#include <string>

/**
 * 설명: ISteamNetworkingSockets는 Steam 네트워크를 통해 P2P 연결을 제공
 * 연결 관리, 실시간 멀티플레이어 데이터 전송
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

    UE_LOG(LogTemp, Log, TEXT("StartP2P 함수가 호출되었습니다."));

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
        UE_LOG(LogTemp, Log, TEXT("Steam API 초기화 성공."));

        // 소켓 초기화
        InitializeSocket();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Steam API 초기화 실패."));
    }

   
}

// Steam API 초기화
bool ASteamSocketsTest::InitializeSteamAPI()
{
    return SteamAPI_Init();
}

// 소켓 초기화
void ASteamSocketsTest::InitializeSocket()
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("Steam Networking Sockets 초기화 실패."));
        return;
    }

    SteamNetworkingIPAddr LocalAddress;
    LocalAddress.Clear();
    LocalAddress.SetIPv4(0x7F000001, 12345); // 127.0.0.1:12345

    ListenSocket = SteamNetworking->CreateListenSocketIP(LocalAddress, 0, nullptr);
    if (ListenSocket != k_HSteamListenSocket_Invalid)
    {
        UE_LOG(LogTemp, Log, TEXT("12345 포트에서 연결 대기 중."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("서버 소켓 생성 실패."));
    }
}

// P2P 메시지 전송
void ASteamSocketsTest::SendP2PMessage(const FString& Message)
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking || Connection == k_HSteamNetConnection_Invalid)
    {
        UE_LOG(LogTemp, Error, TEXT("메시지 전송 실패: 연결되지 않음."));
        return;
    }

    SteamNetworking->SendMessageToConnection(Connection, TCHAR_TO_UTF8(*Message), Message.Len() + 1, k_nSteamNetworkingSend_Reliable, nullptr);
    UE_LOG(LogTemp, Log, TEXT("P2P 메시지 전송: %s"), *Message);
}

// P2P 메시지 수신
void ASteamSocketsTest::ReceiveP2PMessage()
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("메시지 수신 실패: SteamNetworkingSockets 없음."));
        return;
    }

    ISteamNetworkingMessage* Messages[10] = { nullptr };
    int NumMessages = SteamNetworking->ReceiveMessagesOnConnection(Connection, Messages, 10);

    for (int i = 0; i < NumMessages; ++i)
    {
        FString ReceivedMessage(UTF8_TO_TCHAR((char*)Messages[i]->m_pData));
        UE_LOG(LogTemp, Log, TEXT("P2P 메시지 수신: %s"), *ReceivedMessage);
        Messages[i]->Release();
    }
}

void ASteamSocketsTest::StartP2P()
{
    UE_LOG(LogTemp, Log, TEXT("StartP2P 함수가 호출되었습니다."));
    // 추가적인 P2P 초기화 코드가 필요하면 여기에 작성합니다.
}


// 매 프레임 호출
void ASteamSocketsTest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ReceiveP2PMessage();
}
