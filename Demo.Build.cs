// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class YourProject : ModuleRules
{
	public YourProject(ReadOnlyTargetRules Target) : base(Target)
	{
		...
			
		// Required for UEUtils::GetEnhancedInputLocalPlayerSubsystem()
		PrivateDependencyModuleNames.Add("EnhancedInput");
		
		// Required for UEUtils::AssetActions::SaveAsset()
		if(Target.bBuildEditor)
			PrivateDependencyModuleNames.Add("SourceControl");

        // Preprocessor Definitions
        PrivateDefinitions.AddRange(new string[]
        {
	        // not using lean and mean mode in win32 breaks compilation on some systems
	        "WIN32_LEAN_AND_MEAN",
	        // disables some useless warnings
	        "_CRT_SECURE_NO_WARNINGS",
	        // disables the console
	        "UEUTILS_NO_CONSOLE",
	        // enables networking functions
	        "UEUTILS_ONLINE_IMPLEMENTATION",
	        // enables discord RPC functions
	        "UEUTILS_DISCORD_RICH_PRESENCE_IMPLEMENTATION",
	        "UEUTILS_DISCORD_RICH_PRESENCE_APP_ID=\"0123456789012345678\"",
        });
        
        // Discord rich presence API (optional)
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "3rd Party Libraries/discord-rpc/include"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "3rd Party Libraries/discord-rpc/lib/discord-rpc.lib"));
        
        // Required for networking functions (optional)
        PrivateDependencyModuleNames.Add("OnlineSubsystem");
        
		...
    }
}
