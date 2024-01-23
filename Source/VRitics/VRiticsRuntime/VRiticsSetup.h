// Fill out your copyright notice in the Description page of Project Settings.

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
