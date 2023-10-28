#pragma once

#include "VRiticsEvent.h"

class FVRiticsSession
{
public:
	explicit FVRiticsSession(const FString& Name)
		: Name(Name)
	{
		Events = TArray<FVRiticsEvent>();
	}

	static TArray<FVRiticsSession> CurrentSessions;

	FString Name;
	TArray<FVRiticsEvent> Events;
};
