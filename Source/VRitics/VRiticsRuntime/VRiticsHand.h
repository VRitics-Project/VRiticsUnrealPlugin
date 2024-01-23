// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VRiticsHand.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UVRiticsHand : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VRITICS_API IVRiticsHand
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRitics|Hand")
	void TryInteract() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VRitics|Hand")
	void InteractionSuccessful() const;
};
