// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectHyde_init() {}
	PROJECTHYDE_API UFunction* Z_Construct_UDelegateFunction_ProjectHyde_OnDialogueEnded__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProjectHyde;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProjectHyde()
	{
		if (!Z_Registration_Info_UPackage__Script_ProjectHyde.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectHyde_OnDialogueEnded__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProjectHyde",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x4A765DFB,
				0x3EBD77CC,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProjectHyde.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ProjectHyde.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProjectHyde(Z_Construct_UPackage__Script_ProjectHyde, TEXT("/Script/ProjectHyde"), Z_Registration_Info_UPackage__Script_ProjectHyde, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4A765DFB, 0x3EBD77CC));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
