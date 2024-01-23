#pragma once

#include "Modules/ModuleManager.h"

class FVRiticsModule : public IModuleInterface
{
public:
	static FString PlayerID; 
	static FString Token; 
	static FString AppID;

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
