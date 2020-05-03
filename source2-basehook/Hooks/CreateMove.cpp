#include "CreateMove.hpp"

oCreateMove OriginalCreateMove;
bool __fastcall hkCreateMove(IClientModeShared* ptr, CUserCmd* cmd, QAngle& angle, Vector& pos)
{
	pCmd = cmd;

	if (!cmd->command_number)
		return OriginalCreateMove(ptr, cmd, angle, pos);

	if (GetAsyncKeyState(VK_DELETE))
		cmd->viewangles.x += 1;

	return false;
}