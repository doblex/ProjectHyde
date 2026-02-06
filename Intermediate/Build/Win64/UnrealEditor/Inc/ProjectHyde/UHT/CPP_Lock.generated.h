// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actors/CPP_Lock.h"

#ifdef PROJECTHYDE_CPP_Lock_generated_h
#error "CPP_Lock.generated.h already included, missing '#pragma once' in CPP_Lock.h"
#endif
#define PROJECTHYDE_CPP_Lock_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class ELockDigits : uint8;

// ********** Begin Class ACPP_Lock ****************************************************************
#define FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsLocked); \
	DECLARE_FUNCTION(execTryUnlock); \
	DECLARE_FUNCTION(execInsertDigit);


PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_Lock_NoRegister();

#define FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACPP_Lock(); \
	friend struct Z_Construct_UClass_ACPP_Lock_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_Lock_NoRegister(); \
public: \
	DECLARE_CLASS2(ACPP_Lock, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHyde"), Z_Construct_UClass_ACPP_Lock_NoRegister) \
	DECLARE_SERIALIZER(ACPP_Lock)


#define FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h_26_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACPP_Lock(ACPP_Lock&&) = delete; \
	ACPP_Lock(const ACPP_Lock&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPP_Lock); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPP_Lock); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACPP_Lock) \
	NO_API virtual ~ACPP_Lock();


#define FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h_23_PROLOG
#define FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h_26_INCLASS_NO_PURE_DECLS \
	FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACPP_Lock;

// ********** End Class ACPP_Lock ******************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h

// ********** Begin Enum ELockDigits ***************************************************************
#define FOREACH_ENUM_ELOCKDIGITS(op) \
	op(ELockDigits::Zero) \
	op(ELockDigits::One) \
	op(ELockDigits::Two) \
	op(ELockDigits::Three) \
	op(ELockDigits::Four) \
	op(ELockDigits::Five) \
	op(ELockDigits::Six) \
	op(ELockDigits::Seven) \
	op(ELockDigits::Eight) \
	op(ELockDigits::Nine) 

enum class ELockDigits : uint8;
template<> struct TIsUEnumClass<ELockDigits> { enum { Value = true }; };
template<> PROJECTHYDE_API UEnum* StaticEnum<ELockDigits>();
// ********** End Enum ELockDigits *****************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
