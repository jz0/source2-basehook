#include "Base.hpp"

template< class Template >
Template* Base::GetInterface(const std::string ModuleName, const std::string InterfaceName)
{
	const auto Address = GetProcAddress(GetModuleHandleA(ModuleName.c_str()), "CreateInterface");
	const auto CreateInterface = reinterpret_cast<CreateInterfaceFn>(Address);

	Msg(Color(255, 0, 0, 255), "Module: %s : %s : 0x%x \n", ModuleName.c_str(), InterfaceName.c_str(), Address);

	return static_cast<Template*>(CreateInterface(InterfaceName.c_str(), nullptr));
}

void Base::InitInterfaces()
{
	pClient = GetInterface<CSource2Client>("client.dll", "Source2Client002");
	pEngine = GetInterface<CEngineClient>("engine2.dll", "Source2EngineToClient001");
	pPanel = GetInterface<IVPanel>("vgui2.dll", "VGUI_Panel010");
	pSurface = GetInterface<ISurface>("vguirendersurface.dll", "VGUI_Surface032");

	//CSource2Client__SetGlobals + C2     028 48 8D 05 97 6A F5 FF                                            lea     rax, sub_40DC30; #STR: "gpGlocals->curtime() called while IsInSimulation() is fals, "gpGlocals->rendertime() called while IsInSimulation() is t, "-curtimewarnings"
	//CSource2Client__SetGlobals + C9     028 F3 0F 11 05 A3 78 A5 00                                         movss   dword ptr cs : qword_F0EA44, xmm0
	//CSource2Client__SetGlobals + D1     028 48 89 41 28                                                     mov[rcx + 28h], rax
	//CSource2Client__SetGlobals + D5     028 48 89 0D 64 24 8D 00                                            mov     cs : gpGlobals, rcx //0xD89610
	pGlobals = *(CGlobalVarsBase**)Utilities::Dereference(Sig("client.dll", "48 89 0D ? ? ? ? 48 83 C4 28"), 3);
	Msg(Color(255, 255, 255, 255), "pGlobals: %p \n", (void*)pGlobals);


	//HudUpdate + B6     038 83 C9 FF or ecx, 0FFFFFFFFh
	//HudUpdate + B9     038 E8 02 81 0B 00                                                  call    GetHud; #STR: "GetHud called with NULL g_pHudGameSystem!", "GetHud", "error", "c:\\buildslave\\hlvr_rel_win64\\build\\src\\game\\client\\
	//HudUpdate + BE     038 48 8B C8                                                        mov     rcx, rax
	//HudUpdate + C1     038 E8 DA 28 0D 00                                                  call    UpdateHud; #STR: "screenshot"
	//HudUpdate + C6     038 48 8B 0D 4B 51 A0 00                                            mov     rcx, cs:ClientMode //0xEBC368
	pClientMode = *(IClientModeShared**)Utilities::Dereference(Sig("client.dll", "48 8B 0D ? ? ? ? 48 8B 01 FF 90 C0 01 00 00 85"), 3);
	Msg(Color(255, 255, 255, 255), "ClientMode: %p \n", (void*)pClientMode);
}

VMTHook* Panel = nullptr;
VMTHook* ClientMode = nullptr;

void Base::InitHooks()
{
	Msg(Color(0, 0, 0, 255), "Initializing hooks \n");

	Panel = new VMTHook(pPanel);
	OriginalPaint = Panel->HookFunction<oPaintTraverse>(55, hkPaintTraverse);

	ClientMode = new VMTHook(pClientMode);
	OriginalCreateMove = ClientMode->HookFunction<oCreateMove>(32, hkCreateMove);
	OriginalLevelInit = ClientMode->HookFunction<oLevelInit>(33, hkLevelInit);

	Msg(Color(0, 0, 0, 255), "Hooks initialized \n");
}