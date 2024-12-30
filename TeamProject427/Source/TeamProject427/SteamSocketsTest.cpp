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

    if (InitializeSteamAPI())
    {
        UE_LOG(LogTemp, Log, TEXT("Steam API 성공."));

        // 소켓 초기화
        InitializeSocket();
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

// 소켓 초기화
void ASteamSocketsTest::InitializeSocket()
{
    // SteamNetworkingSockets 인터페이스 가져오기
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("Steam Networking Sockets 초기화 실패."));
        return;
    }

    // 로컬 주소 설정
    SteamNetworkingIPAddr LocalAddress;
    LocalAddress.Clear();
    LocalAddress.SetIPv4(0x7F000001, 12345); // 127.0.0.1:12345

    // 리슨 소켓 생성
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

// 서버에 연결
void ASteamSocketsTest::ConnectToServer()
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("Steam Networking Sockets 초기화 실패."));
        return;
    }

    // 서버 주소 설정
    SteamNetworkingIPAddr ServerAddress;
    ServerAddress.Clear();
    ServerAddress.SetIPv4(0x7F000001, 12345); // 127.0.0.1:12345

    // 서버에 연결
    Connection = SteamNetworking->ConnectByIPAddress(ServerAddress, 0, nullptr);
    if (Connection != k_HSteamNetConnection_Invalid)
    {
        UE_LOG(LogTemp, Log, TEXT("서버 연결 성공."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("서버 연결 실패."));
    }
}

// P2P 메시지 전송
void ASteamSocketsTest::SendP2PMessage(const char* Message)
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking || Connection == k_HSteamNetConnection_Invalid)
    {
        UE_LOG(LogTemp, Error, TEXT("메시지 전송 실패: 연결되지 않음."));
        return;
    }

    SteamNetworking->SendMessageToConnection(Connection, Message, strlen(Message) + 1, k_nSteamNetworkingSend_Reliable, nullptr);
    UE_LOG(LogTemp, Log, TEXT("P2P 메시지 전송: %s"), *FString(Message));
}

void ASteamSocketsTest::SendP2PMessage(const FString& Message)
{
    SendP2PMessage(TCHAR_TO_UTF8(*Message));
}

// P2P 메시지 수신 (Tick 함수에서 주기적으로 호출)
void ASteamSocketsTest::ReceiveP2PMessage()
{
    ISteamNetworkingSockets* SteamNetworking = SteamNetworkingSockets();
    if (!SteamNetworking)
    {
        UE_LOG(LogTemp, Error, TEXT("메시지 수신 실패: SteamNetworkingSockets 없음."));
        return;
    }

    ISteamNetworkingMessage* Messages[10] = { nullptr }; // 최대 10개의 메시지를 수신
    int NumMessages = SteamNetworking->ReceiveMessagesOnConnection(Connection, Messages, 10);

    if (NumMessages > 0)
    {
        for (int i = 0; i < NumMessages; ++i)
        {
            FString ReceivedMessage(UTF8_TO_TCHAR((char*)Messages[i]->m_pData));
            UE_LOG(LogTemp, Log, TEXT("P2P 메시지 수신: %s"), *ReceivedMessage);

            // 메시지 해제
            Messages[i]->Release();
        }
    }
    else if (NumMessages < 0)
    {
        UE_LOG(LogTemp, Error, TEXT("메시지 수신 오류."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("수신된 메시지가 없습니다."));
    }
}

// 매 프레임 호출
void ASteamSocketsTest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 메시지 수신
    ReceiveP2PMessage();
}
