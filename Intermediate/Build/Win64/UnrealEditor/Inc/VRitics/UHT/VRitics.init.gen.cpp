// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRitics_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VRitics;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VRitics()
	{
		if (!Z_Registration_Info_UPackage__Script_VRitics.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VRitics",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xB4221DCF,
				0x46403E8D,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VRitics.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VRitics.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VRitics(Z_Construct_UPackage__Script_VRitics, TEXT("/Script/VRitics"), Z_Registration_Info_UPackage__Script_VRitics, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB4221DCF, 0x46403E8D));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
