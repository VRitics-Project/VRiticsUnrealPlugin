// Copyright 2024 Vritics sp. z o.o.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VRiticsSetup.generated.h"

UCLASS()
class VRITICS_API UVRiticsSetup : public UObject
{
	GENERATED_BODY()
public:
	UVRiticsSetup();
	~UVRiticsSetup();
	static void Init(FString, FString, FString);
};
