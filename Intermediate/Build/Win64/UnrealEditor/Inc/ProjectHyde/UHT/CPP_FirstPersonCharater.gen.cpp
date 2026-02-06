// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHyde/Core/CPP_FirstPersonCharater.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCPP_FirstPersonCharater() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_FirstPersonCharater();
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_FirstPersonCharater_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHyde();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACPP_FirstPersonCharater *************************************************
void ACPP_FirstPersonCharater::StaticRegisterNativesACPP_FirstPersonCharater()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ACPP_FirstPersonCharater;
UClass* ACPP_FirstPersonCharater::GetPrivateStaticClass()
{
	using TClass = ACPP_FirstPersonCharater;
	if (!Z_Registration_Info_UClass_ACPP_FirstPersonCharater.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CPP_FirstPersonCharater"),
			Z_Registration_Info_UClass_ACPP_FirstPersonCharater.InnerSingleton,
			StaticRegisterNativesACPP_FirstPersonCharater,
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
	return Z_Registration_Info_UClass_ACPP_FirstPersonCharater.InnerSingleton;
}
UClass* Z_Construct_UClass_ACPP_FirstPersonCharater_NoRegister()
{
	return ACPP_FirstPersonCharater::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACPP_FirstPersonCharater_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Core/CPP_FirstPersonCharater.h" },
		{ "ModuleRelativePath", "Core/CPP_FirstPersonCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Player|Input" },
		{ "ModuleRelativePath", "Core/CPP_FirstPersonCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Player|Input" },
		{ "ModuleRelativePath", "Core/CPP_FirstPersonCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PauseAction_MetaData[] = {
		{ "Category", "Player|Input" },
		{ "ModuleRelativePath", "Core/CPP_FirstPersonCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractAction_MetaData[] = {
		{ "Category", "Player|Input" },
		{ "ModuleRelativePath", "Core/CPP_FirstPersonCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractRange_MetaData[] = {
		{ "Category", "Player|Interaction" },
		{ "ModuleRelativePath", "Core/CPP_FirstPersonCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractChannel_MetaData[] = {
		{ "Category", "Player|Interaction" },
		{ "ModuleRelativePath", "Core/CPP_FirstPersonCharater.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PauseAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractRange;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InteractChannel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_FirstPersonCharater>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_FirstPersonCharater, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_FirstPersonCharater, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_PauseAction = { "PauseAction", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_FirstPersonCharater, PauseAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PauseAction_MetaData), NewProp_PauseAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_InteractAction = { "InteractAction", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_FirstPersonCharater, InteractAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractAction_MetaData), NewProp_InteractAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_InteractRange = { "InteractRange", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_FirstPersonCharater, InteractRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractRange_MetaData), NewProp_InteractRange_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_InteractChannel = { "InteractChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_FirstPersonCharater, InteractChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractChannel_MetaData), NewProp_InteractChannel_MetaData) }; // 756624936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_PauseAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_InteractAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_InteractRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::NewProp_InteractChannel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHyde,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::ClassParams = {
	&ACPP_FirstPersonCharater::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACPP_FirstPersonCharater()
{
	if (!Z_Registration_Info_UClass_ACPP_FirstPersonCharater.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_FirstPersonCharater.OuterSingleton, Z_Construct_UClass_ACPP_FirstPersonCharater_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACPP_FirstPersonCharater.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_FirstPersonCharater);
ACPP_FirstPersonCharater::~ACPP_FirstPersonCharater() {}
// ********** End Class ACPP_FirstPersonCharater ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h__Script_ProjectHyde_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_FirstPersonCharater, ACPP_FirstPersonCharater::StaticClass, TEXT("ACPP_FirstPersonCharater"), &Z_Registration_Info_UClass_ACPP_FirstPersonCharater, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_FirstPersonCharater), 3625074029U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h__Script_ProjectHyde_332675086(TEXT("/Script/ProjectHyde"),
	Z_CompiledInDeferFile_FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h__Script_ProjectHyde_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_EH_UE5_ProjectHyde_Source_ProjectHyde_Core_CPP_FirstPersonCharater_h__Script_ProjectHyde_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
