#include "VRiticsMenuCommands.h"

#define LOCTEXT_NAMESPACE "VRiticsMenuCommands"

void FVRiticsMenuCommands::RegisterCommands()
{
	UI_COMMAND(Clap, "Cut", "Cut selection", EUserInterfaceActionType::Button, FInputChord())

}
