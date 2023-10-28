#pragma once

class FVRiticsEvent
{
public:
	FString Name;
	FVector3f Position;
	bool bIsSuccessful;
	FString ToJsonFormat();
};
