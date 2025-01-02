using UnrealBuildTool;
using System.IO; // Path�� ����ϱ� ���� �߰�

public class TeamProject427 : ModuleRules
{
	public TeamProject427(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "OnlineSubsystemSteam", "OnlineSubsystem" });

        bEnableUndefinedIdentifierWarnings = false; //Steamworks �Լ����� ��������� 

        // Steamworks SDK ������
        string SteamworksPath = "C:/Program Files/Epic Games/UE_4.27/Engine/Source/ThirdParty/Steamworks/Steamv151";

        // C ����̺꿡 ��ΰ� ������ D ����̺긦 ���
        if (!Directory.Exists(SteamworksPath))
        {
            SteamworksPath = "D:/Program Files/Epic Games/UE_4.27/Engine/Source/ThirdParty/Steamworks/Steamv151";

            // D ����̺꿡�� ��ΰ� ������ E ����̺� Ȯ��
            if (!Directory.Exists(SteamworksPath))
            {
                SteamworksPath = "E:/Program Files/Epic Games/UE_4.27/Engine/Source/ThirdParty/Steamworks/Steamv151"; 
            }
        }
       

        PublicIncludePaths.Add(Path.Combine(SteamworksPath, "sdk/public"));
        PublicIncludePaths.Add(Path.Combine(SteamworksPath, "sdk/public/steam"));

        // ��Ȯ�� Win64 ���̺귯�� ��� �߰�
        PublicAdditionalLibraries.Add(Path.Combine(SteamworksPath, "sdk/redistributable_bin/win64/steam_api64.lib"));

        // ��Ȯ�� Win64 DLL ��� �߰�
        RuntimeDependencies.Add(Path.Combine(SteamworksPath, "sdk/redistributable_bin/win64/steam_api64.dll"));

    }

}
