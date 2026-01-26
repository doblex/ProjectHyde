// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/CPP_FirstPersonCharater.h"

#ifdef PROJECTHYDE_CPP_FirstPersonCharater_generated_h
#error "CPP_FirstPersonCharater.generated.h already included, missing '#pragma once' in CPP_FirstPersonCharater.h"
#endif
#define PROJECTHYDE_CPP_FirstPersonCharater_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ACPP_FirstPersonCharater *************************************************
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_FirstPersonCharater_NoRegister();

#define FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACPP_FirstPersonCharater(); \
	friend struct Z_Construct_UClass_ACPP_FirstPersonCharater_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_FirstPersonCharater_NoRegister(); \
public: \
	DECLARE_CLASS2(ACPP_FirstPersonCharater, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHyde"), Z_Construct_UClass_ACPP_FirstPersonCharater_NoRegister) \
	DECLARE_SERIALIZER(ACPP_FirstPersonCharater)


#define FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACPP_FirstPersonCharater(ACPP_FirstPersonCharater&&) = delete; \
	ACPP_FirstPersonCharater(const ACPP_FirstPersonCharater&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPP_FirstPersonCharater); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPP_FirstPersonCharater); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACPP_FirstPersonCharater) \
	NO_API virtual ~ACPP_FirstPersonCharater();


#define FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h_12_PROLOG
#define FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h_15_INCLASS_NO_PURE_DECLS \
	FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACPP_FirstPersonCharater;

// ********** End Class ACPP_FirstPersonCharater ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
