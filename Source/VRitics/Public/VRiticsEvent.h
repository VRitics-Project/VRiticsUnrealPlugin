// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class VRITICS_API VRiticsEvent
{
public:
	VRiticsEvent();
	VRiticsEvent(FString, FVector3f, bool);
	~VRiticsEvent();
	FString ToJsonFormat();

	FString Name;
	FVector3f Position;
	FDateTime DateTime;
	bool bIsSuccessful;
};
