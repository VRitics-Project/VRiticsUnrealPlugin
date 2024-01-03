#pragma once
#include "Framework/Commands/GenericCommands.h"

class FVRiticsMenuCommands final : public TCommands<FVRiticsMenuCommands>
{
public:
	virtual void RegisterCommands() override;
	FVRiticsMenuCommands()
		: TCommands<FVRiticsMenuCommands>( TEXT("GenericCommands"), NSLOCTEXT("GenericCommands", "Generic Commands", "Common Commands"), NAME_None, FCoreStyle::Get().GetStyleSetName() )
	{
	}

	virtual ~FVRiticsMenuCommands()
	{
	}
	
	TSharedPtr<FUICommandInfo> Clap;
	TSharedPtr<FUICommandInfo> Clap2;
};
