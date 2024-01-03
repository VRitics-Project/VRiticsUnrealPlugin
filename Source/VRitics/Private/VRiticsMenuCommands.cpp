#include "VRiticsMenuCommands.h"


void FVRiticsMenuCommands::RegisterCommands()
{
	#define LOCTEXT_NAMESPACE "VRiticsMenuCommands"

	UI_COMMAND(Introduction, "Introduction", "See introduction", EUserInterfaceActionType::Button, FInputChord())
	UI_COMMAND(ConnectionTest, "ConnectionTest", "Test connection", EUserInterfaceActionType::Button, FInputChord())

	#undef LOCTEXT_NAMESPACE
}
