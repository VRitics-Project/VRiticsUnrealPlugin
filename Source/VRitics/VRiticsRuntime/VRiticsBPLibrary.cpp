// Copyright 2024 Vritis sp. z o.o.

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
	UVRiticsSetup::Init(PlayerName, AppID, Token);
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



