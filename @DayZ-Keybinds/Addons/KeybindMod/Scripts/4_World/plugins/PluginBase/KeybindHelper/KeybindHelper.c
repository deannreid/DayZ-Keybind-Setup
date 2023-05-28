typedef Param4<int, UAIDWrapper, Class, string > KeybindParam; // Mode, Wrapper, Class > Method

enum CustomModBinds
{
	Press = 2,
	Release = 4, 
	Hold = 8,
	HoldBegin = 16,
	DoubleClick = 32,
	Click = 64,
};

class KeybindHelper: PluginBase {
	protected static ref KeybindHelper instance;
	protected ref map < int, ref KeybindParam> m_KeyWrappers;
	protected ref ScriptInvoker m_KeyInvokers;
	
	void KeybindHelper() {
		instance = this;
		m_KeyWrappers = new map < int, ref KeybindParam>;
		m_KeyInvokers = new ScriptInvoker();
	}
	
	override void OnInit() {
		Print("[LogHandler] :: [DEBUG] :: ([KeybindHelper] :: Initializing Keybind Helper.");
	}
	
	override void OnUpdate(float time) {
		if (m_KeyWrappers.Count() <= 0) {
			return;
		}
	
		foreach(int id, KeybindParam params: m_KeyWrappers) {
			if (!params) 
				continue;
			
			typename e = CustomModBinds;
			
			for (int bit = 1, i = 0; i < e.GetVariableCount(); i++) {
				bit <<= 1; 
				if (params.param1 & bit) {
					bool paramBuild;
					g_Script.CallFunction(params.param2.InputP(), string.Format("Local%1", typename.EnumToString(CustomModBinds, bit)), paramBuild, NULL);
					
					if (paramBuild) {
						g_Script.CallFunction(params.param3, params.param4, NULL, NULL,);
					}
				}
			}
		}
	}
	
	map <int, ref KeybindParam> Binds() {
		return m_KeyWrappers;
	}
	
	/*
		Register Bind to call function.
		=======
		@Param0: inputName - Name of the UA input defined in inputsSortingHatmaster
		@Param1: mode - Bind Behavior - see enum
		@Param2: callBackFunction - Method to be called on event
		@Param3: endPoint - Instance of callback, Null = Global Call
	*/
	static void RegisterBind(string inputName, CustomModBinds mode, string callBackFunc, Class endPoint = NULL)
	{
		UAInput input = GetUApi().GetInputByName(inputName);
		if (input == NULL)
		{
			Print(string.Format("[Dean KeybindHelper] RegisterBind() :: Failed to bind ["+ inputName +"] is an invalid input! check spelling on input name."));
			return;
		}
	
		KeybindParam params = new KeybindParam(mode, input.GetPersistentWrapper(), endPoint, callBackFunc);
		KeybindHelper.GetInstance().Binds().Insert(input.ID(), params);
		Print(string.Format("[Dean KeybindHelper] RegisterBind() :: Registered bind: [%1] mode: [%2] callback function: [%3]", inputName, typename.EnumToString(CustomModBinds, mode), callBackFunc));
	}
	
	static KeybindHelper GetInstance()
	{
		return instance;
	}
}