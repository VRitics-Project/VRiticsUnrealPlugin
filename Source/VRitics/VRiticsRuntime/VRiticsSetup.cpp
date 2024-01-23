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
