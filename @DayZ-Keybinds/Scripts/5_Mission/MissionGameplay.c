/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: missionGameplay.c
 *  
 * Class Information:
 *
 * Class handles Userside Mission.
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

modded class MissionGameplay {	
	override void OnInit() {
		Print("[PNS - LogHandler] :: [DEBUG] :: ([missionGameplay] :: OnInit - Client"); 
		//PNSKeybindHelper.RegisterBind("OBJECT TO BIND", PNSBinds.Press, "TITLE OF OBJECT", this);
		PNSKeybindHelper.RegisterBind("PNSSettings", PNSBinds.Press, "STR_PNS_SETTINGS", this);
		PNSKeybindHelper.RegisterBind("PNSPiss", PNSBinds.Press,  "STR_PNS_PISS", this);
		PNSKeybindHelper.RegisterBind("PNSShit", PNSBinds.Press,  "STR_PNS_SHIT", this);
		PNSKeybindHelper.RegisterBind("PNSVomit", PNSBinds.Press,  "STR_PNS_VOMIT", this);

        super.OnInit();
	}
}