// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FVRiticsModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddPullDownMenu(FMenuBarBuilder& MenuBuilder);
	void FillMenu(FMenuBuilder& MenuBuilder);
	void OnBtnClicked();
	TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs&);
	TSharedPtr<FExtender> MyExtender;
};
