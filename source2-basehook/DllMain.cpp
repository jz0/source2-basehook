/*
	Source2 Basehook
	by: j, https://github.com/jz0

	Credits:
	Valve
	P47R!CK
	Praydog
*/

#include "Include.hpp"

void Initialize()
{
	Msg = (MsgFn)GetProcAddress(GetModuleHandleA("tier0.dll"), "?ConColorMsg@@YAXAEBVColor@@PEBDZZ");
	Msg(Color(255, 52, 25, 255), "Source2 Basehook\n");

	Base::InitInterfaces();
	Base::InitHooks();
	//Utilities::DumpNetVars();
}

BOOL APIENTRY DllMain(void* Module, DWORD Reason, void* Reserved)
{
	if (Reason == DLL_PROCESS_ATTACH)
		Initialize();

	return TRUE;
}

