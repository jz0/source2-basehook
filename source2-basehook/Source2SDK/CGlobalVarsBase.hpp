#pragma once

class CGlobalVarsBase
{
public:
	float realtime; //0x0000
	int32_t framecount; //0x0004
	float absoluteframetime; //0x0008
	float curtime; //0x000C
	float frameTime; //0x0010
	int32_t maxclients; //0x0014
	int32_t tickcount; //0x0018
	float interval_per_tick; //0x001C
	float frametime2; //0x0020
	float interpolation_amount; //0x0024
};

extern CGlobalVarsBase* pGlobals;