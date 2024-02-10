// Copyright 2024 Vritics sp. z o.o.

#include "VRiticsSetup.h"
#include "VRitics.h"

FString FVRiticsModule::PlayerID;
FString FVRiticsModule::AppID;
FString FVRiticsModule::Token;

UVRiticsSetup::UVRiticsSetup()
{
}

UVRiticsSetup::~UVRiticsSetup()
{
}

void UVRiticsSetup::Init(FString playerId, FString appId, FString token)
{
	FVRiticsModule::PlayerID = playerId;
	FVRiticsModule::AppID = appId;
	FVRiticsModule::Token = token;
}

void UVRiticsSetup::SetToken(const FText& NewText, ETextCommit::Type TextType)
{
	FVRiticsModule::Token = NewText.ToString();
}

void UVRiticsSetup::SetAppId(const FText& NewText, ETextCommit::Type TextType)
{
	FVRiticsModule::AppID = NewText.ToString();
}

FString UVRiticsSetup::GetAppId()
{
	return FVRiticsModule::AppID;
}

FString UVRiticsSetup::GetToken()
{
	return FVRiticsModule::Token;
}
