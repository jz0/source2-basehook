#pragma once
#include "../Include.hpp"
#include "../Source2SDK/CEngineClient.hpp"

typedef void(__fastcall* oLevelInit)(IClientModeShared*, const char*);
extern oLevelInit OriginalLevelInit;

void __fastcall hkLevelInit(IClientModeShared* thisptr, const char* newmap);
