#pragma once
#include "../Include.hpp"

namespace Utilities
{
	uintptr_t FindPattern(const char* module, const char* sig);
	uintptr_t Dereference(uintptr_t address, unsigned int offset);
	void DumpNetVars();
}