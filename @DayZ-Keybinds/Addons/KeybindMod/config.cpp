class CfgPatches {
	class KeybindMod {
		requiredVersion=0.1;
		requiredAddons[]= {

			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods {
	class KeybindMod {
		dir="KeybindMod";
		type="mod";
		inputs="KeybindMod/Scripts/Data/Keybinds.xml";
		dependencies[]= {
			"World", "Mission"
		};
		class defs {
			class coreScriptModule {
                value = "";
                files[] = {
					"KeybindMod/Scripts/1_Core"
				};
            };
			class gameScriptModule {
				value="";
				files[]= {
					"KeybindMod/Scripts/3_Game"};
			};
			class worldScriptModule {
				value="";
				files[]= {
					"KeybindMod/Scripts/4_World"};
			};
			class missionScriptModule {
				value="";
				files[]= {
					"KeybindMod/Scripts/5_Mission"};
			};
		};
	};
};
