#pragma once

class FVRiticsMenuCommands final : public TCommands<FVRiticsMenuCommands>
{
public:
	virtual void RegisterCommands() override;

	FVRiticsMenuCommands()
		: TCommands(TEXT("VRitics Menu Commands"), NSLOCTEXT("VRitics Menu Commands", "VRitics Menu Commands", "VRitics Menu Commands"), NAME_None, FCoreStyle::Get().GetStyleSetName())
	{
	}

	virtual ~FVRiticsMenuCommands() override
	{
	}

	TSharedPtr<FUICommandInfo> Introduction;
	TSharedPtr<FUICommandInfo> ConnectionTest;
};
