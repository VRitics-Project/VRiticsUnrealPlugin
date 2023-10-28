// Copyright Epic Games, Inc. All Rights Reserved.

#include "VRiticsBPLibrary.h"
#include "VRitics.h"

UVRiticsBPLibrary::UVRiticsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	
}

void UVRiticsBPLibrary::RegisterEvent(FVector3f Position, FString Name, bool bIsSuccessful)
{
	
}


void UVRiticsBPLibrary::StartSession(FString Name)
{
	FVRiticsSession::CurrentSessions.Add(FVRiticsSession(Name));
}

void UVRiticsBPLibrary::SendSession()
{
}



