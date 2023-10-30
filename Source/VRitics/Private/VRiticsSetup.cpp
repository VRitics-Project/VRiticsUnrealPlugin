#include "VRiticsSetup.h"

FString UVRiticsSetup::PlayerID;
FString UVRiticsSetup::AppID;
FString UVRiticsSetup::Token;

UVRiticsSetup::UVRiticsSetup()
{
}

UVRiticsSetup::~UVRiticsSetup()
{
}

void UVRiticsSetup::Init(FString playerId, FString appId, FString token)
{
	PlayerID = playerId;
	AppID = appId;
	Token = token;
}
