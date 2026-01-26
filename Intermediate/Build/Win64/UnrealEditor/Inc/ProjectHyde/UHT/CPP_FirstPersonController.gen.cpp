// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHyde/Core/CPP_FirstPersonController.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCPP_FirstPersonController() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_FirstPersonController();
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_FirstPersonController_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHyde();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACPP_FirstPersonController ***********************************************
void ACPP_FirstPersonController::StaticRegisterNativesACPP_FirstPersonController()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ACPP_FirstPersonController;
UClass* ACPP_FirstPersonController::GetPrivateStaticClass()
{
	using TClass = ACPP_FirstPersonController;
	if (!Z_Registration_Info_UClass_ACPP_FirstPersonController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CPP_FirstPersonController"),
			Z_Registration_Info_UClass_ACPP_FirstPersonController.InnerSingleton,
			StaticRegisterNativesACPP_FirstPersonController,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ACPP_FirstPersonController.InnerSingleton;
}
UClass* Z_Construct_UClass_ACPP_FirstPersonController_NoRegister()
{
	return ACPP_FirstPersonController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACPP_FirstPersonController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Core/CPP_FirstPersonController.h" },
		{ "ModuleRelativePath", "Core/CPP_FirstPersonController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMapping_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Core/CPP_FirstPersonController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMapping;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_FirstPersonController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_FirstPersonController_Statics::NewProp_InputMapping = { "InputMapping", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_FirstPersonController, InputMapping), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMapping_MetaData), NewProp_InputMapping_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_FirstPersonController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_FirstPersonController_Statics::NewProp_InputMapping,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_FirstPersonController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACPP_FirstPersonController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHyde,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_FirstPersonController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_FirstPersonController_Statics::ClassParams = {
	&ACPP_FirstPersonController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACPP_FirstPersonController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_FirstPersonController_Statics::PropPointers),
	0,
	0x009003A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_FirstPersonController_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_FirstPersonController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACPP_FirstPersonController()
{
	if (!Z_Registration_Info_UClass_ACPP_FirstPersonController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_FirstPersonController.OuterSingleton, Z_Construct_UClass_ACPP_FirstPersonController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACPP_FirstPersonController.OuterSingleton;
}
ACPP_FirstPersonController::ACPP_FirstPersonController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_FirstPersonController);
ACPP_FirstPersonController::~ACPP_FirstPersonController() {}
// ********** End Class ACPP_FirstPersonController *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h__Script_ProjectHyde_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_FirstPersonController, ACPP_FirstPersonController::StaticClass, TEXT("ACPP_FirstPersonController"), &Z_Registration_Info_UClass_ACPP_FirstPersonController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_FirstPersonController), 977316080U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h__Script_ProjectHyde_2213976698(TEXT("/Script/ProjectHyde"),
	Z_CompiledInDeferFile_FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h__Script_ProjectHyde_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonController_h__Script_ProjectHyde_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
