// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEAMGAME_teamgameCharacter_generated_h
#error "teamgameCharacter.generated.h already included, missing '#pragma once' in teamgameCharacter.h"
#endif
#define TEAMGAME_teamgameCharacter_generated_h

#define teamgame_Source_teamgame_teamgameCharacter_h_12_SPARSE_DATA
#define teamgame_Source_teamgame_teamgameCharacter_h_12_RPC_WRAPPERS
#define teamgame_Source_teamgame_teamgameCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define teamgame_Source_teamgame_teamgameCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAteamgameCharacter(); \
	friend struct Z_Construct_UClass_AteamgameCharacter_Statics; \
public: \
	DECLARE_CLASS(AteamgameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/teamgame"), NO_API) \
	DECLARE_SERIALIZER(AteamgameCharacter)


#define teamgame_Source_teamgame_teamgameCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAteamgameCharacter(); \
	friend struct Z_Construct_UClass_AteamgameCharacter_Statics; \
public: \
	DECLARE_CLASS(AteamgameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/teamgame"), NO_API) \
	DECLARE_SERIALIZER(AteamgameCharacter)


#define teamgame_Source_teamgame_teamgameCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AteamgameCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AteamgameCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AteamgameCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AteamgameCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AteamgameCharacter(AteamgameCharacter&&); \
	NO_API AteamgameCharacter(const AteamgameCharacter&); \
public:


#define teamgame_Source_teamgame_teamgameCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AteamgameCharacter(AteamgameCharacter&&); \
	NO_API AteamgameCharacter(const AteamgameCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AteamgameCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AteamgameCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AteamgameCharacter)


#define teamgame_Source_teamgame_teamgameCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TopDownCameraComponent() { return STRUCT_OFFSET(AteamgameCharacter, TopDownCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AteamgameCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__CursorToWorld() { return STRUCT_OFFSET(AteamgameCharacter, CursorToWorld); }


#define teamgame_Source_teamgame_teamgameCharacter_h_9_PROLOG
#define teamgame_Source_teamgame_teamgameCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	teamgame_Source_teamgame_teamgameCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	teamgame_Source_teamgame_teamgameCharacter_h_12_SPARSE_DATA \
	teamgame_Source_teamgame_teamgameCharacter_h_12_RPC_WRAPPERS \
	teamgame_Source_teamgame_teamgameCharacter_h_12_INCLASS \
	teamgame_Source_teamgame_teamgameCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define teamgame_Source_teamgame_teamgameCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	teamgame_Source_teamgame_teamgameCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	teamgame_Source_teamgame_teamgameCharacter_h_12_SPARSE_DATA \
	teamgame_Source_teamgame_teamgameCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	teamgame_Source_teamgame_teamgameCharacter_h_12_INCLASS_NO_PURE_DECLS \
	teamgame_Source_teamgame_teamgameCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEAMGAME_API UClass* StaticClass<class AteamgameCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID teamgame_Source_teamgame_teamgameCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
