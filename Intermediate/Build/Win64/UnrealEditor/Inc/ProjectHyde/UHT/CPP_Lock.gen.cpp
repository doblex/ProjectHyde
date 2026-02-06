// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHyde/Actors/CPP_Lock.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCPP_Lock() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_Lock();
PROJECTHYDE_API UClass* Z_Construct_UClass_ACPP_Lock_NoRegister();
PROJECTHYDE_API UEnum* Z_Construct_UEnum_ProjectHyde_ELockDigits();
UPackage* Z_Construct_UPackage__Script_ProjectHyde();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ELockDigits ***************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ELockDigits;
static UEnum* ELockDigits_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ELockDigits.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ELockDigits.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ProjectHyde_ELockDigits, (UObject*)Z_Construct_UPackage__Script_ProjectHyde(), TEXT("ELockDigits"));
	}
	return Z_Registration_Info_UEnum_ELockDigits.OuterSingleton;
}
template<> PROJECTHYDE_API UEnum* StaticEnum<ELockDigits>()
{
	return ELockDigits_StaticEnum();
}
struct Z_Construct_UEnum_ProjectHyde_ELockDigits_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Eight.DisplayName", "8" },
		{ "Eight.Name", "ELockDigits::Eight" },
		{ "Five.DisplayName", "5" },
		{ "Five.Name", "ELockDigits::Five" },
		{ "Four.DisplayName", "4" },
		{ "Four.Name", "ELockDigits::Four" },
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
		{ "Nine.DisplayName", "9" },
		{ "Nine.Name", "ELockDigits::Nine" },
		{ "One.DisplayName", "1" },
		{ "One.Name", "ELockDigits::One" },
		{ "Seven.DisplayName", "7" },
		{ "Seven.Name", "ELockDigits::Seven" },
		{ "Six.DisplayName", "6" },
		{ "Six.Name", "ELockDigits::Six" },
		{ "Three.DisplayName", "3" },
		{ "Three.Name", "ELockDigits::Three" },
		{ "Two.DisplayName", "2" },
		{ "Two.Name", "ELockDigits::Two" },
		{ "Zero.DisplayName", "0" },
		{ "Zero.Name", "ELockDigits::Zero" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ELockDigits::Zero", (int64)ELockDigits::Zero },
		{ "ELockDigits::One", (int64)ELockDigits::One },
		{ "ELockDigits::Two", (int64)ELockDigits::Two },
		{ "ELockDigits::Three", (int64)ELockDigits::Three },
		{ "ELockDigits::Four", (int64)ELockDigits::Four },
		{ "ELockDigits::Five", (int64)ELockDigits::Five },
		{ "ELockDigits::Six", (int64)ELockDigits::Six },
		{ "ELockDigits::Seven", (int64)ELockDigits::Seven },
		{ "ELockDigits::Eight", (int64)ELockDigits::Eight },
		{ "ELockDigits::Nine", (int64)ELockDigits::Nine },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ProjectHyde_ELockDigits_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ProjectHyde,
	nullptr,
	"ELockDigits",
	"ELockDigits",
	Z_Construct_UEnum_ProjectHyde_ELockDigits_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectHyde_ELockDigits_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectHyde_ELockDigits_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ProjectHyde_ELockDigits_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ProjectHyde_ELockDigits()
{
	if (!Z_Registration_Info_UEnum_ELockDigits.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ELockDigits.InnerSingleton, Z_Construct_UEnum_ProjectHyde_ELockDigits_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ELockDigits.InnerSingleton;
}
// ********** End Enum ELockDigits *****************************************************************

// ********** Begin Class ACPP_Lock Function InsertDigit *******************************************
struct Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics
{
	struct CPP_Lock_eventInsertDigit_Parms
	{
		ELockDigits Digit;
		int32 Position;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Lock" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Insert a digit into the user combination at the specified position (starting from 0)\n" },
#endif
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Insert a digit into the user combination at the specified position (starting from 0)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Digit_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Digit;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Position;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::NewProp_Digit_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::NewProp_Digit = { "Digit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Lock_eventInsertDigit_Parms, Digit), Z_Construct_UEnum_ProjectHyde_ELockDigits, METADATA_PARAMS(0, nullptr) }; // 2586434701
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Lock_eventInsertDigit_Parms, Position), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::NewProp_Digit_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::NewProp_Digit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::NewProp_Position,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACPP_Lock, nullptr, "InsertDigit", Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::CPP_Lock_eventInsertDigit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::CPP_Lock_eventInsertDigit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_Lock_InsertDigit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Lock_InsertDigit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Lock::execInsertDigit)
{
	P_GET_ENUM(ELockDigits,Z_Param_Digit);
	P_GET_PROPERTY(FIntProperty,Z_Param_Position);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InsertDigit(ELockDigits(Z_Param_Digit),Z_Param_Position);
	P_NATIVE_END;
}
// ********** End Class ACPP_Lock Function InsertDigit *********************************************

// ********** Begin Class ACPP_Lock Function IsLocked **********************************************
struct Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics
{
	struct CPP_Lock_eventIsLocked_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Lock" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Check if lock is locked\n" },
#endif
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if lock is locked" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CPP_Lock_eventIsLocked_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CPP_Lock_eventIsLocked_Parms), &Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACPP_Lock, nullptr, "IsLocked", Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::CPP_Lock_eventIsLocked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::CPP_Lock_eventIsLocked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_Lock_IsLocked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Lock_IsLocked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Lock::execIsLocked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsLocked();
	P_NATIVE_END;
}
// ********** End Class ACPP_Lock Function IsLocked ************************************************

// ********** Begin Class ACPP_Lock Function TryUnlock *********************************************
struct Z_Construct_UFunction_ACPP_Lock_TryUnlock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Lock" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Test the user submitted combination against the correct combination\n" },
#endif
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Test the user submitted combination against the correct combination" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Lock_TryUnlock_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACPP_Lock, nullptr, "TryUnlock", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Lock_TryUnlock_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Lock_TryUnlock_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ACPP_Lock_TryUnlock()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Lock_TryUnlock_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Lock::execTryUnlock)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TryUnlock();
	P_NATIVE_END;
}
// ********** End Class ACPP_Lock Function TryUnlock ***********************************************

// ********** Begin Class ACPP_Lock ****************************************************************
void ACPP_Lock::StaticRegisterNativesACPP_Lock()
{
	UClass* Class = ACPP_Lock::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "InsertDigit", &ACPP_Lock::execInsertDigit },
		{ "IsLocked", &ACPP_Lock::execIsLocked },
		{ "TryUnlock", &ACPP_Lock::execTryUnlock },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ACPP_Lock;
UClass* ACPP_Lock::GetPrivateStaticClass()
{
	using TClass = ACPP_Lock;
	if (!Z_Registration_Info_UClass_ACPP_Lock.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CPP_Lock"),
			Z_Registration_Info_UClass_ACPP_Lock.InnerSingleton,
			StaticRegisterNativesACPP_Lock,
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
	return Z_Registration_Info_UClass_ACPP_Lock.InnerSingleton;
}
UClass* Z_Construct_UClass_ACPP_Lock_NoRegister()
{
	return ACPP_Lock::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACPP_Lock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Actors/CPP_Lock.h" },
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockCombination_MetaData[] = {
		{ "Category", "Lock" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Lock combination to insert in inspector\n" },
#endif
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lock combination to insert in inspector" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentUserCombination_MetaData[] = {
		{ "Category", "Lock" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Lock combination currently inserted by user\n" },
#endif
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lock combination currently inserted by user" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsLocked_MetaData[] = {
		{ "Category", "Lock" },
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClosedLockMesh_MetaData[] = {
		{ "Category", "Lock" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Mesh to use when the lock is closed\n" },
#endif
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mesh to use when the lock is closed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenLockMesh_MetaData[] = {
		{ "Category", "Lock" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Mesh to use when the lock is open\n" },
#endif
		{ "ModuleRelativePath", "Actors/CPP_Lock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mesh to use when the lock is open" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_LockCombination_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LockCombination_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LockCombination;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentUserCombination_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentUserCombination_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CurrentUserCombination;
	static void NewProp_bIsLocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsLocked;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClosedLockMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OpenLockMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPP_Lock_InsertDigit, "InsertDigit" }, // 2116939579
		{ &Z_Construct_UFunction_ACPP_Lock_IsLocked, "IsLocked" }, // 2410491934
		{ &Z_Construct_UFunction_ACPP_Lock_TryUnlock, "TryUnlock" }, // 1746832819
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_Lock>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACPP_Lock_Statics::NewProp_LockCombination_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACPP_Lock_Statics::NewProp_LockCombination_Inner = { "LockCombination", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ProjectHyde_ELockDigits, METADATA_PARAMS(0, nullptr) }; // 2586434701
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACPP_Lock_Statics::NewProp_LockCombination = { "LockCombination", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Lock, LockCombination), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockCombination_MetaData), NewProp_LockCombination_MetaData) }; // 2586434701
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACPP_Lock_Statics::NewProp_CurrentUserCombination_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACPP_Lock_Statics::NewProp_CurrentUserCombination_Inner = { "CurrentUserCombination", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ProjectHyde_ELockDigits, METADATA_PARAMS(0, nullptr) }; // 2586434701
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACPP_Lock_Statics::NewProp_CurrentUserCombination = { "CurrentUserCombination", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Lock, CurrentUserCombination), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentUserCombination_MetaData), NewProp_CurrentUserCombination_MetaData) }; // 2586434701
void Z_Construct_UClass_ACPP_Lock_Statics::NewProp_bIsLocked_SetBit(void* Obj)
{
	((ACPP_Lock*)Obj)->bIsLocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_Lock_Statics::NewProp_bIsLocked = { "bIsLocked", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACPP_Lock), &Z_Construct_UClass_ACPP_Lock_Statics::NewProp_bIsLocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsLocked_MetaData), NewProp_bIsLocked_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Lock_Statics::NewProp_ClosedLockMesh = { "ClosedLockMesh", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Lock, ClosedLockMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClosedLockMesh_MetaData), NewProp_ClosedLockMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Lock_Statics::NewProp_OpenLockMesh = { "OpenLockMesh", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Lock, OpenLockMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenLockMesh_MetaData), NewProp_OpenLockMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_Lock_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Lock_Statics::NewProp_LockCombination_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Lock_Statics::NewProp_LockCombination_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Lock_Statics::NewProp_LockCombination,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Lock_Statics::NewProp_CurrentUserCombination_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Lock_Statics::NewProp_CurrentUserCombination_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Lock_Statics::NewProp_CurrentUserCombination,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Lock_Statics::NewProp_bIsLocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Lock_Statics::NewProp_ClosedLockMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Lock_Statics::NewProp_OpenLockMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Lock_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACPP_Lock_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHyde,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Lock_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_Lock_Statics::ClassParams = {
	&ACPP_Lock::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACPP_Lock_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Lock_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Lock_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_Lock_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACPP_Lock()
{
	if (!Z_Registration_Info_UClass_ACPP_Lock.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_Lock.OuterSingleton, Z_Construct_UClass_ACPP_Lock_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACPP_Lock.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_Lock);
ACPP_Lock::~ACPP_Lock() {}
// ********** End Class ACPP_Lock ******************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h__Script_ProjectHyde_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ELockDigits_StaticEnum, TEXT("ELockDigits"), &Z_Registration_Info_UEnum_ELockDigits, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2586434701U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_Lock, ACPP_Lock::StaticClass, TEXT("ACPP_Lock"), &Z_Registration_Info_UClass_ACPP_Lock, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_Lock), 1199059644U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h__Script_ProjectHyde_4232866377(TEXT("/Script/ProjectHyde"),
	Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h__Script_ProjectHyde_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h__Script_ProjectHyde_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h__Script_ProjectHyde_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Admin_Desktop_Unreal_ProjectHyde_Source_ProjectHyde_Actors_CPP_Lock_h__Script_ProjectHyde_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
