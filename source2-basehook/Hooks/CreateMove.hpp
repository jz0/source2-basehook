#pragma once
#include "../Include.hpp"
#include "../Source2SDK/IClientModeShared.hpp"
#include "../Source2SDK/CUserCmd.hpp"

typedef bool(__fastcall* oCreateMove)(IClientModeShared*, CUserCmd*, QAngle&, Vector&);
extern oCreateMove OriginalCreateMove;

bool __fastcall hkCreateMove(IClientModeShared* ptr, CUserCmd* Cmd, QAngle& Angle, Vector& Pos);