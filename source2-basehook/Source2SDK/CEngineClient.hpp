#pragma once

class CEngineClient
{
public:
	virtual void Unknown1() = 0;
	virtual void Unknown2() = 0;
	virtual void Unknown3() = 0;
	virtual void Unknown4() = 0;
	virtual void Unknown5() = 0;
	virtual void Unknown6() = 0;
	virtual void Unknown7() = 0;
	virtual void Unknown8() = 0;
	virtual void Unknown9() = 0;
	virtual void Unknown10() = 0;
	virtual void Unknown11() = 0;
	virtual void Unknown12() = 0;
	virtual void Unknown13() = 0;
	virtual void Unknown14() = 0;
	virtual void Unknown15() = 0;
	virtual void Unknown16() = 0;
	virtual void Unknown17() = 0;
	virtual void Unknown18() = 0;
	virtual void Unknown19() = 0;
	virtual void Unknown20();
	virtual void Unknown21() = 0;
	virtual int GetLocalPlayer(int) = 0; 
	virtual void Unknown23() = 0;
	virtual void Unknown24() = 0;
	virtual void Unknown25() = 0;
	virtual void Unknown26() = 0;
	virtual int GetMaxClients(void) = 0;
	virtual bool IsInGame(void) = 0;
	virtual bool IsConnected(void) = 0;
	virtual void Unknown31() = 0;
	virtual void Unknown32() = 0;
	virtual void Unknown33() = 0;
	virtual void Unknown34() = 0;
	virtual void Unknown35() = 0;
	virtual void Unknown36() = 0;
	virtual void Unknown37() = 0;
	virtual void ClientCmd_Unrestricted(const char* szCmdString) = 0;
	virtual void Unknown39() = 0;

	int GetLocalPlayer()
	{
		int Out = 0;
		using oFn = int* (__thiscall*)(CEngineClient*, int&, int);
		(CallVfunc<oFn>(this, 22))(this, Out, 0);
		return Out;
	}
};

extern CEngineClient* pEngine;