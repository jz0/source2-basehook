#pragma once
#include "Schema.hpp"
//Greets to Praydog

class ClientClass
{
public:
	char* m_pNetworkName; //0x0000
	char* m_pClassName; //0x0008 
	ClientClass* m_pNext; //0x0010
	void* m_pCreateFn; //0x0018
	void* m_pCreateEventFn; //0x0020
	void* m_pDestroyFn; //0x0028
	char pad_0030[8]; //0x0030
	char* m_pLibNameAndClassName; //0x0038 
	SchemaRecvTable* RecvTable; //0x0040
	char pad_0048[20]; //0x0048
	int m_ClassID; //0x005C
	void* N00000046; //0x0060
	void* N00000047; //0x0068
};