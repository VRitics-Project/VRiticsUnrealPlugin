// Copyright 2024 Vritics sp. z o.o.

using UnrealBuildTool;

public class VRiticsEditor : ModuleRules
{
	public VRiticsEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core", 
				"CoreUObject",
				"Engine",
				"UnrealEd",
				"VRitics",
				"Slate"
			}
			);
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore"
			}
			);
	}
}
