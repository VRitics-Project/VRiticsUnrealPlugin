#include "VRiticsEditor.h"

#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Text/SRichTextBlock.h"

#include "VRiticsMenuCommands.h"
#include "VRitics/VRiticsRuntime/VRitics.h"
#include "VRitics/VRiticsRuntime/VRiticsSession.h"

IMPLEMENT_MODULE(FVRiticsEditorModule, VRiticsEditor)

DEFINE_LOG_CATEGORY_STATIC(LogSimplePlugin, Log, All);

static const FName IntroductionTabName("Introduction Tab");
static const FName ConnectionTestTabName("Connection Test Tab");

FString FVRiticsModule::AppID;
FString FVRiticsModule::Token;

FText FVRiticsEditorModule::Result;

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
	TabManager->RegisterNomadTabSpawner(IntroductionTabName, FOnSpawnTab::CreateRaw(this, &FVRiticsEditorModule::SpawnIntroductionTab))
		.SetDisplayName(FText::FromString(TEXT("Introduction"))).SetMenuType(ETabSpawnerMenuType::Hidden);
	TabManager->RegisterNomadTabSpawner(ConnectionTestTabName, FOnSpawnTab::CreateRaw(this, &FVRiticsEditorModule::SpawnConnectionTestTab))
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
	      .Text(FText::FromString(TEXT("To correctly send events to VRitics' backend you need to follow the steps:\n"
	          "1. Call the Setup node with the correct Token and AppID.\n"
	          "2.Call the StartSession node with the name of the object that sends it for the events to start registering.\n"
	          "3.Use the RegisterEvent node to record a failed or successful interaction attempt.\n"
	          "4. To send packed events to the backend you need to call the SendSession node.\n"
	          "If executed properly, all the registered events and sessions should be visible in the dashboard panel of the app with the corresponding AppID.")))
	          ]
	          + SVerticalBox::Slot()[
			SNew(SButton)
				.Text(FText::FromString(TEXT("Open VRitics website")))
				.OnClicked_Lambda([&]()
				{
					const FString URL = TEXT("http://vr-dashboard.server306419.nazwa.pl/");
					FPlatformProcess::LaunchURL(*URL, nullptr, nullptr);
					return FReply::Handled();
				})
			]
	          
	          ];

	return SpawnedTab;
}

TSharedRef<SDockTab> FVRiticsEditorModule::SpawnConnectionTestTab(const FSpawnTabArgs& TabSpawnArgs) const
{
	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()[
			SNew(SHorizontalBox) +
				SHorizontalBox::Slot()[
					SNew(STextBlock).Text(FText::FromString(TEXT("AppID")))
				].VAlign(VAlign_Center).HAlign(HAlign_Right)
 +
				SHorizontalBox::Slot()[
					SNew(SEditableTextBox).Text(FText::FromString(FVRiticsModule::AppID))
				].VAlign(VAlign_Center).HAlign(HAlign_Fill)
			]
			+ SVerticalBox::Slot()[
			SNew(SHorizontalBox) +
				SHorizontalBox::Slot()[
					SNew(STextBlock).Text(FText::FromString(TEXT("Token")))
				].VAlign(VAlign_Center).HAlign(HAlign_Right)
 +
				SHorizontalBox::Slot()[
					SNew(SEditableTextBox).Text(FText::FromString(FVRiticsModule::Token))
				].VAlign(VAlign_Center).HAlign(HAlign_Fill)
			]
			+ SVerticalBox::Slot()[
			SNew(SButton)
				.Text(FText::FromString(TEXT("TestConnection")))
				.ContentPadding(3)
				.OnClicked_Lambda([&]()
				{
					VRiticsSession::TestSessions(FVRiticsModule::AppID, FVRiticsModule::Token, FVRiticsEditorModule::RefreshResult);
					return FReply::Handled();
				})
			].VAlign(VAlign_Center).HAlign(HAlign_Center)

			+ SVerticalBox::Slot()[
			SNew(SScrollBox)
				+ SScrollBox::Slot()
				.VAlign(VAlign_Top)
				.Padding(5)
				[
					SNew(SBorder)
					.BorderBackgroundColor(FColor(192, 192, 192, 255))
					.Padding(15.0f)
					[
						SNew(STextBlock).Text(Result)
					]
				]
			]
		];
	return SpawnedTab;
}

void FVRiticsEditorModule::RefreshResult(FString Text)
{
	Result = FText::FromString(Text);
}