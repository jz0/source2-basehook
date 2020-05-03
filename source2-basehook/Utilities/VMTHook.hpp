#pragma once
#include "../Include.hpp"

class VMTHook
{
public:
	explicit VMTHook(void* ptr)
	{
		if (!ptr)
			return;

		pClass = reinterpret_cast<uintptr_t**>(ptr);
		pOriginalVMT = *pClass;

		const auto Size = Length();
		pHookedVMT = std::make_unique<uint64_t[]>(Size + 1);

		memcpy(&pHookedVMT.get()[1], pOriginalVMT, Size * sizeof uint64_t);

		pHookedVMT.get()[0] = static_cast<uintptr_t>(pOriginalVMT[-1]);

		PatchPtr(pHookedVMT.get());
	}

	~VMTHook()
	{
		PatchPtr(pOriginalVMT);
	}

	template<typename Function, typename Original>
	Function HookFunction(uint64_t Index, Original _Function)
	{
		auto Old = pOriginalVMT[Index];
		pHookedVMT.get()[Index + 1] = reinterpret_cast<uintptr_t>(_Function);
		return reinterpret_cast<Function>(Old);
	}

private:

	uint64_t Length() 
	{
		uint64_t Index = 0;
		const auto VMT = pOriginalVMT;

		for (Index = 0; VMT[Index]; Index++)
			if (IS_INTRESOURCE(VMT[Index]))
				break;

		return Index;
	}

	void PatchPtr(uintptr_t* Replacement)
	{
		if (!pClass)
			return;

		DWORD Old;

		VirtualProtect(pClass, sizeof uintptr_t, PAGE_READWRITE, &Old);
		Replacement == pOriginalVMT ? *pClass = Replacement : *pClass = &Replacement[1];
		VirtualProtect(pClass, sizeof uintptr_t, Old, &Old);
	}

	std::uintptr_t** pClass;
	std::uintptr_t* pOriginalVMT;
	std::unique_ptr<uint64_t[]> pHookedVMT;
};