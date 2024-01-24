// Copyright 2024 Vritics sp. z o.o.

#pragma once

#include "CoreMinimal.h"

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
