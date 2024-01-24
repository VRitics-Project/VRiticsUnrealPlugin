// Copyright 2024 Vritics sp. z o.o.

#pragma once

#include "Modules/ModuleManager.h"

class FVRiticsEditorModule : public IModuleInterface
{
public:
	static FText Result;

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void AddPullDownMenu(FMenuBarBuilder& MenuBuilder);
	void FillMenu(FMenuBuilder& MenuBuilder);
	void OnIntroductionClicked();
	void OnConnectionTestClicked();
	TSharedRef<SDockTab> SpawnIntroductionTab(const FSpawnTabArgs&) const;
	TSharedRef<SDockTab> SpawnConnectionTestTab(const FSpawnTabArgs&) const;
	static void RefreshResult(FString Text);
	TSharedPtr<FExtender> MyExtender;
};
