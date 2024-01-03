#pragma once

#include "Modules/ModuleManager.h"

class FVRiticsModule : public IModuleInterface
{
	static FText Token;
public:
	static FText AppID;
	static FText Result;

	FText aaa;
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddPullDownMenu(FMenuBarBuilder& MenuBuilder);
	void FillMenu(FMenuBuilder& MenuBuilder);
	void OnIntroductionClicked();
	void OnConnectionTestClicked();
	const void UpdateConnectionResult() const;
	TSharedRef<SDockTab> SpawnIntroductionTab(const FSpawnTabArgs&) const;
	TSharedRef<SDockTab> SpawnConnectionTestTab(const FSpawnTabArgs&) const;
	static void RefreshResult(const FText& Text);
	TSharedPtr<FExtender> MyExtender;
};
