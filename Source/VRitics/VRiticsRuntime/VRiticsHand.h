// Copyright 2024 Vritics sp. z o.o.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VRiticsHand.generated.h"

UINTERFACE()
class UVRiticsHand : public UInterface
{
	GENERATED_BODY()
};

class VRITICS_API IVRiticsHand
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRitics|Hand")
	void TryInteract() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRitics|Hand")
	void InteractionSuccessful() const;
};
