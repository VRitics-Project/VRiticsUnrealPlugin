// Copyright 2024 Vritics sp. z o.o.

#include "VRiticsEditor.h"

#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Text/SRichTextBlock.h"

#include "VRiticsMenuCommands.h"
#include "VRitics/VRiticsRuntime/VRitics.h"
#include "VRitics/VRiticsRuntime/VRiticsSession.h"
#include "VRitics/VRiticsRuntime/VRiticsSetup.h"

IMPLEMENT_MODULE(FVRiticsEditorModule, VRiticsEditor)

DEFINE_LOG_CATEGORY_STATIC(LogSimplePlugin, Log, All);

static const FName IntroductionTabName("Introduction Tab");
static const FName ConnectionTestTabName("Connection Test Tab");

FString FVRiticsModule::AppID;
FString FVRiticsModule::Token;

FText FVRiticsEditorModule::Result;
TSharedPtr<STextBlock> FVRiticsEditorModule::TextBlock;

void FVRiticsEditorModule::StartupModule()
{
	FVRiticsMenuCommands::Register();

	TSharedPtr<FUICommandList> MyPluginCommands = MakeShareable(new FUICommandList);

	MyPluginCommands->MapAction(
		FVRiticsMenuCommands::Get().Introduction,
		FExecuteAction::CreateRaw(this, &FVRiticsEditorModule::OnIntroductionClicked),
		FCanExecuteAction());

	MyPluginCommands->MapAction(
		FVRiticsMenuCommands::Get().ConnectionTest,
		FExecuteAction::CreateRaw(this, &FVRiticsEditorModule::OnConnectionTestClicked),
		FCanExecuteAction());

	MyExtender = MakeShareable(new FExtender);
	MyExtender->AddMenuBarExtension(
		"Help",
		EExtensionHook::After,
		MyPluginCommands,
		FMenuBarExtensionDelegate::CreateRaw(this, &FVRiticsEditorModule::AddPullDownMenu)
	);

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MyExtender);

	const TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
	TabManager->RegisterDefaultTabWindowSize(IntroductionTabName, FVector2D(400, 300));
	TabManager->RegisterNomadTabSpawner(IntroductionTabName,
	                                    FOnSpawnTab::CreateRaw(this, &FVRiticsEditorModule::SpawnIntroductionTab))
	          .SetDisplayName(FText::FromString(TEXT("Introduction"))).SetMenuType(ETabSpawnerMenuType::Hidden);
	TabManager->RegisterDefaultTabWindowSize(ConnectionTestTabName, FVector2D(100, 100));
	TabManager->RegisterNomadTabSpawner(ConnectionTestTabName,
	                                    FOnSpawnTab::CreateRaw(this, &FVRiticsEditorModule::SpawnConnectionTestTab))
	          .SetDisplayName(FText::FromString(TEXT("Connection Test"))).SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FVRiticsEditorModule::ShutdownModule()
{
	FVRiticsMenuCommands::Unregister();

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MyExtender);

	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->UnregisterNomadTabSpawner(IntroductionTabName);
	tm->UnregisterNomadTabSpawner(ConnectionTestTabName);
}

void FVRiticsEditorModule::AddPullDownMenu(FMenuBarBuilder& MenuBuilder)
{
	MenuBuilder.AddPullDownMenu(
		FText::FromString("VRitics"),
		FText::FromString("VRitics plugin tools"),
		FNewMenuDelegate::CreateRaw(this, &FVRiticsEditorModule::FillMenu),
		"Custom"
	);
}

void FVRiticsEditorModule::FillMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection("Introduction");
	{
		MenuBuilder.AddMenuEntry(
			FVRiticsMenuCommands::Get().Introduction, NAME_None,
			FText::FromString("Introduction"),
			FText::FromString("Open the introduction window"),
			FSlateIcon()
		);
	}
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection("ConnectionTester");
	{
		MenuBuilder.AddMenuEntry(
			FVRiticsMenuCommands::Get().ConnectionTest, NAME_None,
			FText::FromString("Connection tester"),
			FText::FromString("Open the connection tester window"),
			FSlateIcon()
		);
	}
	MenuBuilder.EndSection();
}

void FVRiticsEditorModule::OnIntroductionClicked()
{
	UE_LOG(LogSimplePlugin, Log, TEXT("FVRiticsModule::OnBtnClicked"));
	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->TryInvokeTab(IntroductionTabName);
}


void FVRiticsEditorModule::OnConnectionTestClicked()
{
	UE_LOG(LogSimplePlugin, Log, TEXT("FVRiticsModule::OnBtnClicked"));
	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->TryInvokeTab(ConnectionTestTabName);
}

TSharedRef<SDockTab> FVRiticsEditorModule::SpawnIntroductionTab(const FSpawnTabArgs& TabSpawnArgs) const
{
	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.TabRole(NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.Padding(20)
			[
				SNew(SRichTextBlock)
				.Text(FText::FromString(TEXT(
					"To correctly send events to VRitics' backend you need to follow the steps:\n\n"
					"1. Go to VRitics website, once registered create App to get AppId and generate Token.\n")))
			].FillHeight(0.1f)
			+ SVerticalBox::Slot()[
				SNew(SButton)
				.Text(FText::FromString(TEXT("Open VRitics website")))
				.OnClicked_Lambda([&]()
				             {
					             const FString URL = TEXT("https://dashboard.vritics.com/");
					             FPlatformProcess::LaunchURL(*URL, nullptr, nullptr);
					             return FReply::Handled();
				             })
			].VAlign(VAlign_Center).HAlign(HAlign_Center).FillHeight(0.1f)
			+ SVerticalBox::Slot()
			.Padding(20)
			[
				SNew(SRichTextBlock)
				.Text(FText::FromString(TEXT(
					"2. Call the Setup node with the any PlayerID. Use Token and AppID that you got from VRitics website.\n"
					"3. Call the StartSession node with session name of your choice in the Name field. Now the events will start registering.\n"
					"4. Use the RegisterEvent node to record a successful or failed interaction attempt. Events will be added to current session.\n"
					"5. Call SendSession node to end current session end send events to the server.\n\n"
					"If executed properly, all the registered events and sessions should be visible in the dashboard panel of the app with the corresponding AppID.")))
			].FillHeight(0.8f)
			+ SVerticalBox::Slot()[
				SNew(SButton)
				.Text(FText::FromString(TEXT("See full manual")))
				.OnClicked_Lambda([&]()
							 {
								 const FString URL = TEXT("https://drive.google.com/file/d/1PI4wqcVZvRQcjYI_UD_cC-PbED4EcBQl/view?usp=drive_link");
								 FPlatformProcess::LaunchURL(*URL, nullptr, nullptr);
								 return FReply::Handled();
							 })
			].VAlign(VAlign_Center).HAlign(HAlign_Center).FillHeight(0.1f)
		];

	return SpawnedTab;
}

TSharedRef<SDockTab> FVRiticsEditorModule::SpawnConnectionTestTab(const FSpawnTabArgs& TabSpawnArgs)
{
	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.TabRole(NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()[
				SNew(SHorizontalBox) +
				SHorizontalBox::Slot()[
					SNew(STextBlock).Text(FText::FromString(TEXT("AppID")))
				].VAlign(VAlign_Center).HAlign(HAlign_Right).AutoWidth().Padding(20)
				+
				SHorizontalBox::Slot()[
					SNew(SEditableTextBox).Text(FText::FromString(FVRiticsModule::AppID)).OnTextCommitted(FOnTextCommitted::CreateLambda(&UVRiticsSetup::SetAppId))
				].VAlign(VAlign_Center).HAlign(HAlign_Fill).MaxWidth(50.0f)
			].HAlign(HAlign_Fill).VAlign(VAlign_Top).AutoHeight()
			+ SVerticalBox::Slot()[
				SNew(SHorizontalBox) +
				SHorizontalBox::Slot()[
					SNew(STextBlock).Text(FText::FromString(TEXT("Token")))
				].VAlign(VAlign_Center).HAlign(HAlign_Right).AutoWidth().Padding(20)
				+
				SHorizontalBox::Slot()[
					SNew(SEditableTextBox).Text(FText::FromString(FVRiticsModule::Token)).OnTextCommitted(FOnTextCommitted::CreateLambda(&UVRiticsSetup::SetToken))
				].VAlign(VAlign_Center).HAlign(HAlign_Fill).MaxWidth(400.0f)
			].HAlign(HAlign_Fill).VAlign(VAlign_Top).AutoHeight()
			+ SVerticalBox::Slot()[
				SNew(SButton)
				.Text(FText::FromString(TEXT("TestConnection")))
				.ContentPadding(3)
				.OnClicked_Lambda([&]()
				             {
								 RefreshResult(TEXT("..."));
					             VRiticsSession::TestSessions(UVRiticsSetup::GetAppId(), UVRiticsSetup::GetToken(),
					                                          RefreshResult);
					             return FReply::Handled();
				             })
			].VAlign(VAlign_Center).HAlign(HAlign_Center)
			+ SVerticalBox::Slot()[
				SNew(SScrollBox)
				+ SScrollBox::Slot()
				  .VAlign(VAlign_Fill)
				  .Padding(5)
				[
					SNew(SBorder)
					.BorderBackgroundColor(FColor(192, 192, 192, 255))
					.Padding(15.0f)
					[
						SAssignNew(TextBlock, STextBlock).Text(Result)
					].VAlign(VAlign_Fill)
				]
			].VAlign(VAlign_Fill)
		];
	return SpawnedTab;
}

const void FVRiticsEditorModule::RefreshResult(const FString& Text)
{
	Result = FText::FromString(Text);
	TextBlock.Get()->SetText(Result);
}
