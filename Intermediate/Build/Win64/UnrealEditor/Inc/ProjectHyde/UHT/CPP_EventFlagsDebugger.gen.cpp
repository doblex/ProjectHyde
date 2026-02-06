// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHyde/Actors/CPP_EventFlagsDebugger.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCPP_EventFlagsDebugger() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_EventFlagsDebugger();
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_EventFlagsDebugger_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHyde();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ACPP_EventFlagsDebugger **************************************************
void ACPP_EventFlagsDebugger::StaticRegisterNativesACPP_EventFlagsDebugger()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ACPP_EventFlagsDebugger;
UClass* ACPP_EventFlagsDebugger::GetPrivateStaticClass()
{
	using TClass = ACPP_EventFlagsDebugger;
	if (!Z_Registration_Info_UClass_ACPP_EventFlagsDebugger.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CPP_EventFlagsDebugger"),
			Z_Registration_Info_UClass_ACPP_EventFlagsDebugger.InnerSingleton,
			StaticRegisterNativesACPP_EventFlagsDebugger,
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
	return Z_Registration_Info_UClass_ACPP_EventFlagsDebugger.InnerSingleton;
}
UClass* Z_Construct_UClass_ACPP_EventFlagsDebugger_NoRegister()
{
	return ACPP_EventFlagsDebugger::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Actors/CPP_EventFlagsDebugger.h" },
		{ "ModuleRelativePath", "Actors/CPP_EventFlagsDebugger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RefreshTimer_MetaData[] = {
		{ "Category", "Event Flags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Set how often the debugger updates its map copy to reflect the subsystem's event flag map\n" },
#endif
		{ "ModuleRelativePath", "Actors/CPP_EventFlagsDebugger.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set how often the debugger updates its map copy to reflect the subsystem's event flag map" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventFlagMapMirror_MetaData[] = {
		{ "Category", "Event Flags" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// A read only copy of the events registered in the Event Flag Subsystem\n" },
#endif
		{ "ModuleRelativePath", "Actors/CPP_EventFlagsDebugger.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A read only copy of the events registered in the Event Flag Subsystem" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RefreshTimer;
	static const UECodeGen_Private::FBoolPropertyParams NewProp_EventFlagMapMirror_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventFlagMapMirror_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_EventFlagMapMirror;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_EventFlagsDebugger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::NewProp_RefreshTimer = { "RefreshTimer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_EventFlagsDebugger, RefreshTimer), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RefreshTimer_MetaData), NewProp_RefreshTimer_MetaData) };
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::NewProp_EventFlagMapMirror_ValueProp = { "EventFlagMapMirror", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::NewProp_EventFlagMapMirror_Key_KeyProp = { "EventFlagMapMirror_Key", nullptr, (EPropertyFlags)0x0000000000020001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 133831994
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::NewProp_EventFlagMapMirror = { "EventFlagMapMirror", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_EventFlagsDebugger, EventFlagMapMirror), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventFlagMapMirror_MetaData), NewProp_EventFlagMapMirror_MetaData) }; // 133831994
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::NewProp_RefreshTimer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::NewProp_EventFlagMapMirror_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::NewProp_EventFlagMapMirror_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::NewProp_EventFlagMapMirror,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHyde,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::ClassParams = {
	&ACPP_EventFlagsDebugger::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACPP_EventFlagsDebugger()
{
	if (!Z_Registration_Info_UClass_ACPP_EventFlagsDebugger.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_EventFlagsDebugger.OuterSingleton, Z_Construct_UClass_ACPP_EventFlagsDebugger_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACPP_EventFlagsDebugger.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_EventFlagsDebugger);
ACPP_EventFlagsDebugger::~ACPP_EventFlagsDebugger() {}
// ********** End Class ACPP_EventFlagsDebugger ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_EventFlagsDebugger_h__Script_ProjectHyde_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_EventFlagsDebugger, ACPP_EventFlagsDebugger::StaticClass, TEXT("ACPP_EventFlagsDebugger"), &Z_Registration_Info_UClass_ACPP_EventFlagsDebugger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_EventFlagsDebugger), 1899017528U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_EventFlagsDebugger_h__Script_ProjectHyde_4188984951(TEXT("/Script/ProjectHyde"),
	Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_EventFlagsDebugger_h__Script_ProjectHyde_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_EventFlagsDebugger_h__Script_ProjectHyde_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
