#include "LevelInit.hpp"

oLevelInit OriginalLevelInit;
void __fastcall hkLevelInit(IClientModeShared* thisptr, const char* newmap)
{
	pGlobals = *(CGlobalVarsBase**)Utilities::Dereference(Sig("client.dll", "48 89 0D ? ? ? ? 48 83 C4 28"), 3);
	Msg(Color(255, 0, 0, 255), "NewMap %s \n", newmap);
	Msg(Color(255, 0, 0, 255), "pGlobals %p \n", pGlobals);
	Msg(Color(255, 0, 0, 255), "pGlobals->MaxClients %i \n", pGlobals->maxclients);

	OriginalLevelInit(thisptr, newmap);
}

