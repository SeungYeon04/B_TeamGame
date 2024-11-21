// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "teamgame/teamgameGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeteamgameGameMode() {}
// Cross Module References
	TEAMGAME_API UClass* Z_Construct_UClass_AteamgameGameMode_NoRegister();
	TEAMGAME_API UClass* Z_Construct_UClass_AteamgameGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_teamgame();
// End Cross Module References
	void AteamgameGameMode::StaticRegisterNativesAteamgameGameMode()
	{
	}
	UClass* Z_Construct_UClass_AteamgameGameMode_NoRegister()
	{
		return AteamgameGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AteamgameGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AteamgameGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_teamgame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AteamgameGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "teamgameGameMode.h" },
		{ "ModuleRelativePath", "teamgameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AteamgameGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AteamgameGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AteamgameGameMode_Statics::ClassParams = {
		&AteamgameGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AteamgameGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AteamgameGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AteamgameGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AteamgameGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AteamgameGameMode, 3211314571);
	template<> TEAMGAME_API UClass* StaticClass<AteamgameGameMode>()
	{
		return AteamgameGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AteamgameGameMode(Z_Construct_UClass_AteamgameGameMode, &AteamgameGameMode::StaticClass, TEXT("/Script/teamgame"), TEXT("AteamgameGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AteamgameGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
