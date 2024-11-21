// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "teamgame/teamgamePlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeteamgamePlayerController() {}
// Cross Module References
	TEAMGAME_API UClass* Z_Construct_UClass_AteamgamePlayerController_NoRegister();
	TEAMGAME_API UClass* Z_Construct_UClass_AteamgamePlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_teamgame();
// End Cross Module References
	void AteamgamePlayerController::StaticRegisterNativesAteamgamePlayerController()
	{
	}
	UClass* Z_Construct_UClass_AteamgamePlayerController_NoRegister()
	{
		return AteamgamePlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AteamgamePlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AteamgamePlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_teamgame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AteamgamePlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "teamgamePlayerController.h" },
		{ "ModuleRelativePath", "teamgamePlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AteamgamePlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AteamgamePlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AteamgamePlayerController_Statics::ClassParams = {
		&AteamgamePlayerController::StaticClass,
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
		0x008002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AteamgamePlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AteamgamePlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AteamgamePlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AteamgamePlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AteamgamePlayerController, 1693713024);
	template<> TEAMGAME_API UClass* StaticClass<AteamgamePlayerController>()
	{
		return AteamgamePlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AteamgamePlayerController(Z_Construct_UClass_AteamgamePlayerController, &AteamgamePlayerController::StaticClass, TEXT("/Script/teamgame"), TEXT("AteamgamePlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AteamgamePlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
