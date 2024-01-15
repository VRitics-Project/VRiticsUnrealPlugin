#include "VRitics.h"

#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "VRiticsMenuCommands.h"
#include "VRiticsSession.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Text/SRichTextBlock.h"

DEFINE_LOG_CATEGORY_STATIC(LogSimplePlugin, Log, All);

static const FName IntroductionTabName("Introduction Tab");
static const FName ConnectionTestTabName("Connection Test Tab");

FText FVRiticsModule::AppID;
FText FVRiticsModule::Token;
FText FVRiticsModule::Result;

void FVRiticsModule::StartupModule()
{
	FVRiticsMenuCommands::Register();

	TSharedPtr<FUICommandList> MyPluginCommands = MakeShareable(new FUICommandList);

	MyPluginCommands->MapAction(
		FVRiticsMenuCommands::Get().Introduction,
		FExecuteAction::CreateRaw(this, &FVRiticsModule::OnIntroductionClicked),
		FCanExecuteAction());

	MyPluginCommands->MapAction(
		FVRiticsMenuCommands::Get().ConnectionTest,
		FExecuteAction::CreateRaw(this, &FVRiticsModule::OnConnectionTestClicked),
		FCanExecuteAction());
	
	MyExtender = MakeShareable(new FExtender);
	MyExtender->AddMenuBarExtension(
		"Help",
		EExtensionHook::After,
		MyPluginCommands,
		FMenuBarExtensionDelegate::CreateRaw(this, &FVRiticsModule::AddPullDownMenu)
	);

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MyExtender);

	const TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
	TabManager->RegisterNomadTabSpawner(IntroductionTabName, FOnSpawnTab::CreateRaw(this, &FVRiticsModule::SpawnIntroductionTab))
		.SetDisplayName(FText::FromString(TEXT("Introduction"))).SetMenuType(ETabSpawnerMenuType::Hidden);
	TabManager->RegisterNomadTabSpawner(ConnectionTestTabName, FOnSpawnTab::CreateRaw(this, &FVRiticsModule::SpawnConnectionTestTab))
	.SetDisplayName(FText::FromString(TEXT("Connection Test"))).SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FVRiticsModule::ShutdownModule()
{
	FVRiticsMenuCommands::Unregister();

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MyExtender);

	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->UnregisterNomadTabSpawner(IntroductionTabName);
	tm->UnregisterNomadTabSpawner(ConnectionTestTabName);
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

void FVRiticsModule::OnIntroductionClicked()
{
	UE_LOG(LogSimplePlugin, Log, TEXT("FVRiticsModule::OnBtnClicked"));
	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->TryInvokeTab(IntroductionTabName);
}


void FVRiticsModule::OnConnectionTestClicked()
{
	UE_LOG(LogSimplePlugin, Log, TEXT("FVRiticsModule::OnBtnClicked"));
	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->TryInvokeTab(ConnectionTestTabName);
}

TSharedRef<SDockTab> FVRiticsModule::SpawnIntroductionTab(const FSpawnTabArgs& TabSpawnArgs) const
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

TSharedRef<SDockTab> FVRiticsModule::SpawnConnectionTestTab(const FSpawnTabArgs& TabSpawnArgs) const
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
					SNew(SEditableTextBox).Text(AppID)
				].VAlign(VAlign_Center).HAlign(HAlign_Fill)
			]
			+ SVerticalBox::Slot()[
			SNew(SHorizontalBox) +
				SHorizontalBox::Slot()[
					SNew(STextBlock).Text(FText::FromString(TEXT("Token")))
				].VAlign(VAlign_Center).HAlign(HAlign_Right)
 +
				SHorizontalBox::Slot()[
					SNew(SEditableTextBox).Text(Token)
				].VAlign(VAlign_Center).HAlign(HAlign_Fill)
			]
			+ SVerticalBox::Slot()[
			SNew(SButton)
				.Text(FText::FromString(TEXT("TestConnection")))
				.ContentPadding(3)
				.OnClicked_Lambda([&]()
				{
					VRiticsSession::TestSessions(AppID, Token);
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

void FVRiticsModule::RefreshResult(FString Text)
{
	Result = FText::FromString(Text);
}

IMPLEMENT_MODULE(FVRiticsModule, SimplePlugin)
