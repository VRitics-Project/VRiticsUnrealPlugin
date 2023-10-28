// Copyright Epic Games, Inc. All Rights Reserved.

#include "VRiticsBPLibrary.h"
#include "VRiticsSession.h"
#include "VRiticsSetup.h"

class VRiticsSession;

UVRiticsBPLibrary::UVRiticsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	
}

void UVRiticsBPLibrary::Setup(FString PlayerName, FString AppID, FString Token)
{
	UVRiticsSetup(PlayerName, AppID, Token);
}

void UVRiticsBPLibrary::RegisterEvent(FVector3f Position, FString Name, bool bIsSuccessful)
{
	VRiticsSession::RegisterEvent(Name, Position, bIsSuccessful);
}

void UVRiticsBPLibrary::StartSession(FString Name)
{
	VRiticsSession::AddSession(Name);
}

void UVRiticsBPLibrary::SendSession()
{
	VRiticsSession::SendSessions();
}



