VRitics plugin for Unreal Engine

Open your Unreal Engine project folder.
If it doesn't already exist, create a new folder named "Plugins" in the root directory of your project.
![Alt text](Resources/image1.png?raw=true "Image1")

Extract the downloaded files if necessary.
Copy the entire "VRitics" plugin folder (containing necessary files and directories) into your project's "Plugins" folder.

Close the Unreal Editor if it's open.
Reopen the project. Unreal Engine will detect and load the "VRitics" plugin.

In the Unreal Editor, go to the "Edit" menu and select "Plugins."
In the Plugins window, find "VRitics" in the list and make sure it's enabled.
![Alt text](Resources/image2.png?raw=true "Image2")

In some cases, you might need to rebuild your project to ensure that the plugin is properly integrated. Go to "File" > "Generate Visual Studio project files" and then open the generated project file to build your project.

If the configuration was successful you can type “VRitics” in the blueprint editor and a list of available functions should appear in the context menu. 
![Alt text](Resources/image3.png?raw=true "Image3")

To correctly send events to VRitics' backend you need to follow the steps:
1. Call the Setup node with the correct Token and AppID. 
2. Call the StartSession node with the name of the object that sends it for the events to start registering. 
3. Use the RegisterEvent node to record a failed or successful interaction attempt. 
4. To send packed events to the backend you need to call the SendSession node.
If executed properly, all the registered events and sessions should be visible in the dashboard panel of the app with the corresponding AppID.