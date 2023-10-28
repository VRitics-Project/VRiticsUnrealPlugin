// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "VRiticsBPLibrary.generated.h"

UCLASS()
class UVRiticsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "VRitics sample test testing"), Category = "VRiticsTesting")
	static void RegisterEvent(FVector3f Position, FString Name, bool bIsSuccessful);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "VRitics sample test testing"), Category = "VRiticsTesting")
	static void StartSession(FString Name);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "VRitics sample test testing"), Category = "VRiticsTesting")
	static void SendSession();
};
