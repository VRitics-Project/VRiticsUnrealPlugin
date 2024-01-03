#include "VRitics.h"

#include "EditorStyleSet.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "VRiticsMenuCommands.h"

DEFINE_LOG_CATEGORY_STATIC(LogSimplePlugin, Log, All);

static const FName TabName("ClapTab");

void FVRiticsModule::StartupModule()
{
	FVRiticsMenuCommands::Register();

	TSharedPtr<FUICommandList> MyPluginCommands = MakeShareable(new FUICommandList);

	MyPluginCommands->MapAction(
		FVRiticsMenuCommands::Get().Clap,
		FExecuteAction::CreateRaw(this, &FVRiticsModule::OnBtnClicked),
		FCanExecuteAction());

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	MyExtender = MakeShareable(new FExtender);
	MyExtender->AddToolBarExtension("Settings", EExtensionHook::After, MyPluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FVRiticsModule::AddToolbarExtension));

	MyExtender->AddMenuBarExtension(
		"Help",
		EExtensionHook::After,
		MyPluginCommands,
		FMenuBarExtensionDelegate::CreateRaw(this, &FVRiticsModule::AddPullDownMenu)
	);

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(MyExtender);
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MyExtender);

	TSharedRef<class FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
	TabManager->RegisterNomadTabSpawner(TabName, FOnSpawnTab::CreateRaw(this, &FVRiticsModule::SpawnTab))
		.SetDisplayName(FText::FromString(TEXT("Clap")));
}

void FVRiticsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.GetToolBarExtensibilityManager()->RemoveExtender(MyExtender);
	LevelEditorModule.GetMenuExtensibilityManager()->RemoveExtender(MyExtender);

	FVRiticsMenuCommands::Unregister();

	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->UnregisterNomadTabSpawner(TabName);

}

void FVRiticsModule::AddToolbarExtension(class FToolBarBuilder& Builder)
{
#define LOCTEXT_NAMESPACE "LevelEditorToolBar"
	FSlateIcon IconBrush = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions", "LevelEditor.ViewOptions.Small");
	Builder.AddToolBarButton(FVRiticsMenuCommands::Get().Clap, NAME_None, LOCTEXT("MyButton_Override", "Clap"), LOCTEXT("MyButton_ToolTipOverride", "Click to clap"), IconBrush, NAME_None);
#undef LOCTEXT_NAMESPACE

}

void FVRiticsModule::AddPullDownMenu(FMenuBarBuilder& MenuBuilder)
{
	MenuBuilder.AddPullDownMenu(
		FText::FromString("VRitics"),
		FText::FromString("VRitics plugin tools"),
		FNewMenuDelegate::CreateRaw(this, &FVRiticsModule::FillMenu),
		"Custom"
	);
}

void FVRiticsModule::FillMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection("Clap");
	{
		MenuBuilder.AddMenuEntry(
			FVRiticsMenuCommands::Get().Clap, NAME_None,
			FText::FromString("Introduction"),
			FText::FromString("Open the introduction window"),
			FSlateIcon()
		);
	}
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection("Clap2");
	{
		MenuBuilder.AddMenuEntry(
		FVRiticsMenuCommands::Get().Clap2, NAME_None,
			FText::FromString("Connection tester"),
			FText::FromString("Open the connection tester window"),
			FSlateIcon()
			);
	}
	MenuBuilder.EndSection();
}

void FVRiticsModule::OnBtnClicked()
{
	UE_LOG(LogSimplePlugin, Log, TEXT("FVRiticsModule::OnBtnClicked"));
	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->TryInvokeTab(TabName);
}


TSharedRef<SDockTab> FVRiticsModule::SpawnTab(const FSpawnTabArgs& TabSpawnArgs)
{
	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
		SNew(SButton)
			.Text(FText::FromString(TEXT("Clap")))
			.ContentPadding(3)
		];

	return SpawnedTab;
}

IMPLEMENT_MODULE(FVRiticsModule, SimplePlugin)