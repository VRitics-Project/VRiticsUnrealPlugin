// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "VRiticsBPLibrary.generated.h"

UCLASS()
class UVRiticsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Setup", Keywords = "VRitics setup"), Category = "VRitics")
	static void Setup(FString PlayerID, FString AppID, FString Token);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "RegisterEvent", Keywords = "VRitics register event"), Category = "VRitics")
	static void RegisterEvent(FVector3f Position, FString Name, bool bIsSuccessful);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StartSession", Keywords = "VRitics start session"), Category = "VRitics")
	static void StartSession(FString Name);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SendSession", Keywords = "VRitics send session"), Category = "VRitics")
	static void SendSession();
};
