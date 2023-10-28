// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRiticsEvent.h"

/**
 * 
 */
class VRITICS_API VRiticsSession
{
public:
	VRiticsSession();
	~VRiticsSession();
	VRiticsSession(FString);
	static void AddSession(FString);
	static void RegisterEvent(FString, FVector3f, bool);
	static void SendSessions();

	static TArray<VRiticsSession> CurrentSessions;

	FString Name;
	FString SceneName;
	TArray<VRiticsEvent> Events;
};
