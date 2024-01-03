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
	static void SendSession(const FString&, const FString&, const FString&, VRiticsSession&);
	static void SendSessions();
	static void TestSessions(const FText&, const FText&);

	static TArray<VRiticsSession> CurrentSessions;
	
	FString Name;
	FString SceneName;
	TArray<VRiticsEvent> Events;
};
