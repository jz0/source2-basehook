#pragma once
#include "ClientClass.hpp"

class CSource2Client
{
public:
	virtual void Unknown1() = 0;
	virtual void Disconnect(void) = 0;
	virtual void Unknown3() = 0;
	virtual void Unknown4() = 0;
	virtual void Shutdown(void) = 0;
	virtual void Unknown6() = 0;
	virtual void Unknown7() = 0;
	virtual void Unknown8() = 0;
	virtual void Unknown9() = 0;
	virtual void Unknown10() = 0;
	virtual void Unknown11() = 0;
	virtual void SetGlobals(void* CGlobalVarsBase) = 0;
	virtual void Unknown13() = 0;
	virtual void Unknown14() = 0;
	virtual void Unknown15() = 0;
	virtual void Unknown16() = 0;
	virtual void Unknown17() = 0;
	virtual void Unknown18() = 0;
	virtual void Unknown19() = 0;
	virtual void Unknown20() = 0;
	virtual void Unknown21() = 0;
	virtual void Unknown22() = 0;
	virtual void Unknown23() = 0;
	virtual void Unknown24() = 0;
	virtual void Unknown25() = 0;
	virtual void Unknown26() = 0;
	virtual void Unknown27() = 0;
	virtual ClientClass* GetAllClasses(void) = 0;
	virtual void Unknown28() = 0;
	virtual void Unknown29() = 0;
	virtual void Unknown30() = 0;
	virtual void HudUpdate(bool bActive) = 0;
};

extern CSource2Client* pClient;