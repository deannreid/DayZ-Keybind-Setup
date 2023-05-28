modded class MissionGameplay {	
	override void OnInit() {
		Print("[LogHandler] :: [DEBUG] :: ([missionGameplay] :: OnInit - Client"); 
		//KeybindHelper.RegisterBind("OBJECT TO BIND", CustomModBinds.Press, "TITLE OF OBJECT", this);
		KeybindHelper.RegisterBind("Keybind1", CustomModBinds.Press, "Keybind 1", this);
		KeybindHelper.RegisterBind("Keybind2", CustomModBinds.Press,  "Keybind 2", this);

        super.OnInit();
	}
}