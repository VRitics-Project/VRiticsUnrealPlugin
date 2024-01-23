// Some copyright should be here...

using UnrealBuildTool;

public class VRitics : ModuleRules
{
	public VRitics(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core", 
				"CoreUObject",
				"Engine",
				"XRBase",
				"Http"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Slate",
				"SlateCore",
				"XRBase"
			}
			);
		
		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
		}
	}
}