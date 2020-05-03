#include "Utilities.hpp"

uintptr_t Utilities::FindPattern(const char* Module, const char* Sig)
{
#define IN_RANGE(x, a, b) (x >= a && x <= b)
#define GET_BITS(x) (IN_RANGE((x & (~0x20)), 'A', 'F') ? ((x & (~0x20)) - 'A' + 0xA): (IN_RANGE(x, '0', '9') ? x - '0': 0))
#define GET_BYTE(x) (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))

	const auto ModuleHandle = GetModuleHandleA(Module);
	const auto DOSHeader = PIMAGE_DOS_HEADER(ModuleHandle);
	const auto NTHeaders = PIMAGE_NT_HEADERS(reinterpret_cast<std::uint8_t*>(ModuleHandle) + DOSHeader->e_lfanew);

	uintptr_t StartAddress = (uintptr_t)GetModuleHandleA(Module);
	uintptr_t Size = (StartAddress + (uintptr_t)NTHeaders->OptionalHeader.SizeOfImage);

	const char* Pat = Sig;
	uintptr_t FirstMatch = 0;
	for (uintptr_t pCur = StartAddress; pCur < Size; pCur++)
	{
		if (!*Pat) return FirstMatch;
		if (*(PBYTE)Pat == ('\?') || *(BYTE*)pCur == GET_BYTE(Pat))
		{
			if (!FirstMatch) FirstMatch = pCur;
			if (!Pat[2]) return FirstMatch;
			if (*(PWORD)Pat == ('\?\?') || *(PBYTE)Pat != ('\?')) Pat += 3;
			else Pat += 2;
		}
		else
		{
			Pat = Sig;
			FirstMatch = 0;
		}
	}
	return NULL;
}

uintptr_t Utilities::Dereference(uintptr_t Address, unsigned int Offset)
{
	if (Address == 0)
		return 0;

	if (sizeof(uintptr_t) == 8)
		return Address + (int)((*(int*)(Address + Offset) + Offset) + sizeof(int));

	return (uintptr_t) * (unsigned long*)(Address + Offset);
}

void Utilities::DumpNetVars()
{
	FILE* FileHandle;
	FileHandle = fopen("G:\\NetVar_Dump.txt", "w");

	for (ClientClass* ClientClasses = pClient->GetAllClasses(); ClientClasses; ClientClasses = ClientClasses->m_pNext)
	{
		if (!ClientClasses->RecvTable || !ClientClasses->RecvTable->NetvarsArray || !ClientClasses->m_pClassName)
			continue;

		Msg(Color(151, 173, 209, 255), "%s : [%d] \n", ClientClasses->m_pClassName, ClientClasses->RecvTable->NumOfNetvars);
		fprintf(FileHandle, "%s : [%d] \n", ClientClasses->m_pClassName, ClientClasses->RecvTable->NumOfNetvars);

		for (int i = 0; i < ClientClasses->RecvTable->NumOfNetvars; i++)
		{
			Netvar* Var = ClientClasses->RecvTable->NetvarsArray[i].Netvar;

			if (!Var || !Var->NetvarName || !Var->TypeName || !Var->Offset)
				break;

			Msg(Color(91, 141, 222, 255), "\t[%d] %s -> 0x%x  [%s] \n", i + 1, Var->NetvarName, Var->Offset, Var->TypeName);
			fprintf(FileHandle, "\t[%d] %s -> 0x%x  [%s] \n", i + 1, Var->NetvarName, Var->Offset, Var->TypeName);
		}
	}

	fclose(FileHandle);
}