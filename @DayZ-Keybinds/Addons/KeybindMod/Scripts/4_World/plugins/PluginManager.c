modded class PluginManager {
	override void Init() {
		super.Init();
			Print("[ModPluginManager] :: [DEBUG] :: Loading Plugin Classes");
			//Register Modules
			//              Module Class :           Client  |  Server
			/*Server Only Plugins*/
			//RegisterPlugin("", 			 		 false, 		true);		


			/*Client Only Plugins*/
			//RegisterPlugin("", 					 true, 		false);		
			RegisterPlugin("KeybindHelper", 		 true, 		false);	

			/*Clnt & Srvr Plugins*/
			//RegisterPlugin("", 					 true, 		true);
	}
}