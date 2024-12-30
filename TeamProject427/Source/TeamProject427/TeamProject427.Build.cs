using UnrealBuildTool;
using System.IO; // Path를 사용하기 위해 추가

public class TeamProject427 : ModuleRules
{
	public TeamProject427(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "OnlineSubsystemSteam", "OnlineSubsystem" });

        bEnableUndefinedIdentifierWarnings = false; //Steamworks 함수선언 버전경고무시 

        // Steamworks SDK 절대경로
        string SteamworksPath = "C:/Program Files/Epic Games/UE_4.27/Engine/Source/ThirdParty/Steamworks/Steamv151";

        // C 드라이브에 경로가 없으면 D 드라이브를 사용
        if (!Directory.Exists(SteamworksPath))
        {
            SteamworksPath = "D:/Program Files/Epic Games/UE_4.27/Engine/Source/ThirdParty/Steamworks/Steamv151";

            // D 드라이브에도 경로가 없으면 E 드라이브 확인
            if (!Directory.Exists(SteamworksPath))
            {
                SteamworksPath = "E:/Program Files/Epic Games/UE_4.27/Engine/Source/ThirdParty/Steamworks/Steamv151"; 
            }
        }
       

        PublicIncludePaths.Add(Path.Combine(SteamworksPath, "sdk/public"));
        PublicIncludePaths.Add(Path.Combine(SteamworksPath, "sdk/public/steam"));

        // 정확한 Win64 라이브러리 경로 추가
        PublicAdditionalLibraries.Add(Path.Combine(SteamworksPath, "sdk/redistributable_bin/win64/steam_api64.lib"));

        // 정확한 Win64 DLL 경로 추가
        RuntimeDependencies.Add(Path.Combine(SteamworksPath, "sdk/redistributable_bin/win64/steam_api64.dll"));

    }

}
