// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "VRiticsSession.h"
#include "Modules/ModuleManager.h"

class FVRiticsModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};