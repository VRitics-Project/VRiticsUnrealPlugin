// Copyright 2024 Vritics sp. z o.o.

#pragma once

#include "CoreMinimal.h"
#include "VRiticsEvent.h"

class VRITICS_API VRiticsSession
{
public:
	VRiticsSession();
	~VRiticsSession();
	VRiticsSession(FString);
	static void AddSession(FString);
	static void RegisterEvent(FString, FVector3f, bool);
	static void SendSession(const FString&, const FString&, const FString&, VRiticsSession&, const void (*)(const FString&));
	static void SendSessions();
	static void TestSessions(const FString&, const FString&,  const void (*)(const FString&)); 

	static TArray<VRiticsSession> CurrentSessions;
	
	FString Name;
	FString SceneName;
	TArray<VRiticsEvent> Events;
};
