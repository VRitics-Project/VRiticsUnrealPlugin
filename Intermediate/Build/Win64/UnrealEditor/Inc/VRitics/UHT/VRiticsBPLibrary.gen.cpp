// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VRitics/VRiticsRuntime/VRiticsBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRiticsBPLibrary() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector3f();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_VRitics();
	VRITICS_API UClass* Z_Construct_UClass_UVRiticsBPLibrary();
	VRITICS_API UClass* Z_Construct_UClass_UVRiticsBPLibrary_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVRiticsBPLibrary::execSendSession)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UVRiticsBPLibrary::SendSession();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVRiticsBPLibrary::execStartSession)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Name);
		P_FINISH;
		P_NATIVE_BEGIN;
		UVRiticsBPLibrary::StartSession(Z_Param_Name);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVRiticsBPLibrary::execRegisterEvent)
	{
		P_GET_STRUCT(FVector3f,Z_Param_Position);
		P_GET_PROPERTY(FStrProperty,Z_Param_Name);
		P_GET_UBOOL(Z_Param_bIsSuccessful);
		P_FINISH;
		P_NATIVE_BEGIN;
		UVRiticsBPLibrary::RegisterEvent(Z_Param_Position,Z_Param_Name,Z_Param_bIsSuccessful);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVRiticsBPLibrary::execSetup)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_PlayerID);
		P_GET_PROPERTY(FStrProperty,Z_Param_AppID);
		P_GET_PROPERTY(FStrProperty,Z_Param_Token);
		P_FINISH;
		P_NATIVE_BEGIN;
		UVRiticsBPLibrary::Setup(Z_Param_PlayerID,Z_Param_AppID,Z_Param_Token);
		P_NATIVE_END;
	}
	void UVRiticsBPLibrary::StaticRegisterNativesUVRiticsBPLibrary()
	{
		UClass* Class = UVRiticsBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RegisterEvent", &UVRiticsBPLibrary::execRegisterEvent },
			{ "SendSession", &UVRiticsBPLibrary::execSendSession },
			{ "Setup", &UVRiticsBPLibrary::execSetup },
			{ "StartSession", &UVRiticsBPLibrary::execStartSession },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics
	{
		struct VRiticsBPLibrary_eventRegisterEvent_Parms
		{
			FVector3f Position;
			FString Name;
			bool bIsSuccessful;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
		static void NewProp_bIsSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRiticsBPLibrary_eventRegisterEvent_Parms, Position), Z_Construct_UScriptStruct_FVector3f, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRiticsBPLibrary_eventRegisterEvent_Parms, Name), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::NewProp_bIsSuccessful_SetBit(void* Obj)
	{
		((VRiticsBPLibrary_eventRegisterEvent_Parms*)Obj)->bIsSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::NewProp_bIsSuccessful = { "bIsSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VRiticsBPLibrary_eventRegisterEvent_Parms), &Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::NewProp_bIsSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::NewProp_bIsSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "VRitics" },
		{ "DisplayName", "RegisterEvent" },
		{ "Keywords", "VRitics register event" },
		{ "ModuleRelativePath", "VRiticsBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRiticsBPLibrary, nullptr, "RegisterEvent", nullptr, nullptr, Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::VRiticsBPLibrary_eventRegisterEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::VRiticsBPLibrary_eventRegisterEvent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVRiticsBPLibrary_SendSession_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVRiticsBPLibrary_SendSession_Statics::Function_MetaDataParams[] = {
		{ "Category", "VRitics" },
		{ "DisplayName", "SendSession" },
		{ "Keywords", "VRitics send session" },
		{ "ModuleRelativePath", "VRiticsBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVRiticsBPLibrary_SendSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRiticsBPLibrary, nullptr, "SendSession", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_SendSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVRiticsBPLibrary_SendSession_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVRiticsBPLibrary_SendSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVRiticsBPLibrary_SendSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics
	{
		struct VRiticsBPLibrary_eventSetup_Parms
		{
			FString PlayerID;
			FString AppID;
			FString Token;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerID;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AppID;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Token;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::NewProp_PlayerID = { "PlayerID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRiticsBPLibrary_eventSetup_Parms, PlayerID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::NewProp_AppID = { "AppID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRiticsBPLibrary_eventSetup_Parms, AppID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::NewProp_Token = { "Token", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRiticsBPLibrary_eventSetup_Parms, Token), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::NewProp_PlayerID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::NewProp_AppID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::NewProp_Token,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::Function_MetaDataParams[] = {
		{ "Category", "VRitics" },
		{ "DisplayName", "Setup" },
		{ "Keywords", "VRitics setup" },
		{ "ModuleRelativePath", "VRiticsBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRiticsBPLibrary, nullptr, "Setup", nullptr, nullptr, Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::VRiticsBPLibrary_eventSetup_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::VRiticsBPLibrary_eventSetup_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVRiticsBPLibrary_Setup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVRiticsBPLibrary_Setup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics
	{
		struct VRiticsBPLibrary_eventStartSession_Parms
		{
			FString Name;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VRiticsBPLibrary_eventStartSession_Parms, Name), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::NewProp_Name,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::Function_MetaDataParams[] = {
		{ "Category", "VRitics" },
		{ "DisplayName", "StartSession" },
		{ "Keywords", "VRitics start session" },
		{ "ModuleRelativePath", "VRiticsBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRiticsBPLibrary, nullptr, "StartSession", nullptr, nullptr, Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::VRiticsBPLibrary_eventStartSession_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::VRiticsBPLibrary_eventStartSession_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVRiticsBPLibrary_StartSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVRiticsBPLibrary_StartSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVRiticsBPLibrary);
	UClass* Z_Construct_UClass_UVRiticsBPLibrary_NoRegister()
	{
		return UVRiticsBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UVRiticsBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVRiticsBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_VRitics,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVRiticsBPLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVRiticsBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVRiticsBPLibrary_RegisterEvent, "RegisterEvent" }, // 3628264834
		{ &Z_Construct_UFunction_UVRiticsBPLibrary_SendSession, "SendSession" }, // 3858191318
		{ &Z_Construct_UFunction_UVRiticsBPLibrary_Setup, "Setup" }, // 4129395316
		{ &Z_Construct_UFunction_UVRiticsBPLibrary_StartSession, "StartSession" }, // 1293541658
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVRiticsBPLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVRiticsBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VRiticsBPLibrary.h" },
		{ "ModuleRelativePath", "VRiticsBPLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVRiticsBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVRiticsBPLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVRiticsBPLibrary_Statics::ClassParams = {
		&UVRiticsBPLibrary::StaticClass,
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
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVRiticsBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UVRiticsBPLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVRiticsBPLibrary()
	{
		if (!Z_Registration_Info_UClass_UVRiticsBPLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVRiticsBPLibrary.OuterSingleton, Z_Construct_UClass_UVRiticsBPLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVRiticsBPLibrary.OuterSingleton;
	}
	template<> VRITICS_API UClass* StaticClass<UVRiticsBPLibrary>()
	{
		return UVRiticsBPLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVRiticsBPLibrary);
	UVRiticsBPLibrary::~UVRiticsBPLibrary() {}
	struct Z_CompiledInDeferFile_FID_Users_topto_OneDrive_Dokumenty_Unreal_Projects_VRiticsTest_Plugins_VRitics_Source_VRitics_VRiticsRuntime_VRiticsBPLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_topto_OneDrive_Dokumenty_Unreal_Projects_VRiticsTest_Plugins_VRitics_Source_VRitics_VRiticsRuntime_VRiticsBPLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVRiticsBPLibrary, UVRiticsBPLibrary::StaticClass, TEXT("UVRiticsBPLibrary"), &Z_Registration_Info_UClass_UVRiticsBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVRiticsBPLibrary), 1507683173U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_topto_OneDrive_Dokumenty_Unreal_Projects_VRiticsTest_Plugins_VRitics_Source_VRitics_VRiticsRuntime_VRiticsBPLibrary_h_662915489(TEXT("/Script/VRitics"),
		Z_CompiledInDeferFile_FID_Users_topto_OneDrive_Dokumenty_Unreal_Projects_VRiticsTest_Plugins_VRitics_Source_VRitics_VRiticsRuntime_VRiticsBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_topto_OneDrive_Dokumenty_Unreal_Projects_VRiticsTest_Plugins_VRitics_Source_VRitics_VRiticsRuntime_VRiticsBPLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
