// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHyde/Subsystems/CPP_EventFlagSubsystem.h"
#include "Engine/GameInstance.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCPP_EventFlagSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
PROJECTHYDE_API UClass* Z_Construct_UClass_UCPP_EventFlagSubsystem();
PROJECTHYDE_API UClass* Z_Construct_UClass_UCPP_EventFlagSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHyde();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCPP_EventFlagSubsystem Function GetEventFlag ****************************
struct Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics
{
	struct CPP_EventFlagSubsystem_eventGetEventFlag_Parms
	{
		FGameplayTag Flag;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/CPP_EventFlagSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Flag;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_EventFlagSubsystem_eventGetEventFlag_Parms, Flag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 133831994
void Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CPP_EventFlagSubsystem_eventGetEventFlag_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CPP_EventFlagSubsystem_eventGetEventFlag_Parms), &Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::NewProp_Flag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCPP_EventFlagSubsystem, nullptr, "GetEventFlag", Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::CPP_EventFlagSubsystem_eventGetEventFlag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::CPP_EventFlagSubsystem_eventGetEventFlag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCPP_EventFlagSubsystem::execGetEventFlag)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_Flag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetEventFlag(Z_Param_Flag);
	P_NATIVE_END;
}
// ********** End Class UCPP_EventFlagSubsystem Function GetEventFlag ******************************

// ********** Begin Class UCPP_EventFlagSubsystem Function GetEventFlagMap *************************
struct Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics
{
	struct CPP_EventFlagSubsystem_eventGetEventFlagMap_Parms
	{
		TMap<FGameplayTag,bool> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/CPP_EventFlagSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 133831994
const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_EventFlagSubsystem_eventGetEventFlagMap_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 133831994
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::NewProp_ReturnValue_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::NewProp_ReturnValue_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCPP_EventFlagSubsystem, nullptr, "GetEventFlagMap", Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::CPP_EventFlagSubsystem_eventGetEventFlagMap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::CPP_EventFlagSubsystem_eventGetEventFlagMap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCPP_EventFlagSubsystem::execGetEventFlagMap)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TMap<FGameplayTag,bool>*)Z_Param__Result=P_THIS->GetEventFlagMap();
	P_NATIVE_END;
}
// ********** End Class UCPP_EventFlagSubsystem Function GetEventFlagMap ***************************

// ********** Begin Class UCPP_EventFlagSubsystem Function SetEventFlag ****************************
struct Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics
{
	struct CPP_EventFlagSubsystem_eventSetEventFlag_Parms
	{
		FGameplayTag Flag;
		bool bValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// End USubsystem\n" },
#endif
		{ "ModuleRelativePath", "Subsystems/CPP_EventFlagSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "End USubsystem" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Flag;
	static void NewProp_bValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_Flag = { "Flag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_EventFlagSubsystem_eventSetEventFlag_Parms, Flag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 133831994
void Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_bValue_SetBit(void* Obj)
{
	((CPP_EventFlagSubsystem_eventSetEventFlag_Parms*)Obj)->bValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CPP_EventFlagSubsystem_eventSetEventFlag_Parms), &Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CPP_EventFlagSubsystem_eventSetEventFlag_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CPP_EventFlagSubsystem_eventSetEventFlag_Parms), &Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_Flag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_bValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCPP_EventFlagSubsystem, nullptr, "SetEventFlag", Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::CPP_EventFlagSubsystem_eventSetEventFlag_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::CPP_EventFlagSubsystem_eventSetEventFlag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCPP_EventFlagSubsystem::execSetEventFlag)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_Flag);
	P_GET_UBOOL(Z_Param_bValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetEventFlag(Z_Param_Flag,Z_Param_bValue);
	P_NATIVE_END;
}
// ********** End Class UCPP_EventFlagSubsystem Function SetEventFlag ******************************

// ********** Begin Class UCPP_EventFlagSubsystem **************************************************
void UCPP_EventFlagSubsystem::StaticRegisterNativesUCPP_EventFlagSubsystem()
{
	UClass* Class = UCPP_EventFlagSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetEventFlag", &UCPP_EventFlagSubsystem::execGetEventFlag },
		{ "GetEventFlagMap", &UCPP_EventFlagSubsystem::execGetEventFlagMap },
		{ "SetEventFlag", &UCPP_EventFlagSubsystem::execSetEventFlag },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCPP_EventFlagSubsystem;
UClass* UCPP_EventFlagSubsystem::GetPrivateStaticClass()
{
	using TClass = UCPP_EventFlagSubsystem;
	if (!Z_Registration_Info_UClass_UCPP_EventFlagSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CPP_EventFlagSubsystem"),
			Z_Registration_Info_UClass_UCPP_EventFlagSubsystem.InnerSingleton,
			StaticRegisterNativesUCPP_EventFlagSubsystem,
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
	return Z_Registration_Info_UClass_UCPP_EventFlagSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UCPP_EventFlagSubsystem_NoRegister()
{
	return UCPP_EventFlagSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCPP_EventFlagSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Subsystems/CPP_EventFlagSubsystem.h" },
		{ "ModuleRelativePath", "Subsystems/CPP_EventFlagSubsystem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlag, "GetEventFlag" }, // 379302030
		{ &Z_Construct_UFunction_UCPP_EventFlagSubsystem_GetEventFlagMap, "GetEventFlagMap" }, // 1496348177
		{ &Z_Construct_UFunction_UCPP_EventFlagSubsystem_SetEventFlag, "SetEventFlag" }, // 3969975199
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCPP_EventFlagSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCPP_EventFlagSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHyde,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCPP_EventFlagSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCPP_EventFlagSubsystem_Statics::ClassParams = {
	&UCPP_EventFlagSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCPP_EventFlagSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UCPP_EventFlagSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCPP_EventFlagSubsystem()
{
	if (!Z_Registration_Info_UClass_UCPP_EventFlagSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCPP_EventFlagSubsystem.OuterSingleton, Z_Construct_UClass_UCPP_EventFlagSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCPP_EventFlagSubsystem.OuterSingleton;
}
UCPP_EventFlagSubsystem::UCPP_EventFlagSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCPP_EventFlagSubsystem);
UCPP_EventFlagSubsystem::~UCPP_EventFlagSubsystem() {}
// ********** End Class UCPP_EventFlagSubsystem ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Subsystems_CPP_EventFlagSubsystem_h__Script_ProjectHyde_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCPP_EventFlagSubsystem, UCPP_EventFlagSubsystem::StaticClass, TEXT("UCPP_EventFlagSubsystem"), &Z_Registration_Info_UClass_UCPP_EventFlagSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCPP_EventFlagSubsystem), 859105101U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Subsystems_CPP_EventFlagSubsystem_h__Script_ProjectHyde_2104890880(TEXT("/Script/ProjectHyde"),
	Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Subsystems_CPP_EventFlagSubsystem_h__Script_ProjectHyde_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Subsystems_CPP_EventFlagSubsystem_h__Script_ProjectHyde_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
