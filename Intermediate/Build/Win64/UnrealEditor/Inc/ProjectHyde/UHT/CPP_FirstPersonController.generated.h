// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/CPP_FirstPersonController.h"

#ifdef PROJECTHYDE_CPP_FirstPersonController_generated_h
#error "CPP_FirstPersonController.generated.h already included, missing '#pragma once' in CPP_FirstPersonController.h"
#endif
#define PROJECTHYDE_CPP_FirstPersonController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ACPP_FirstPersonController ***********************************************
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_FirstPersonController_NoRegister();

#define FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACPP_FirstPersonController(); \
	friend struct Z_Construct_UClass_ACPP_FirstPersonController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_FirstPersonController_NoRegister(); \
public: \
	DECLARE_CLASS2(ACPP_FirstPersonController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHyde"), Z_Construct_UClass_ACPP_FirstPersonController_NoRegister) \
	DECLARE_SERIALIZER(ACPP_FirstPersonController)


#define FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACPP_FirstPersonController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACPP_FirstPersonController(ACPP_FirstPersonController&&) = delete; \
	ACPP_FirstPersonController(const ACPP_FirstPersonController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPP_FirstPersonController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPP_FirstPersonController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACPP_FirstPersonController) \
	NO_API virtual ~ACPP_FirstPersonController();


#define FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h_12_PROLOG
#define FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h_15_INCLASS_NO_PURE_DECLS \
	FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACPP_FirstPersonController;

// ********** End Class ACPP_FirstPersonController *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
