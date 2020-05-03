#pragma once
#include "Include.hpp"

namespace Base
{
    typedef void* (*CreateInterfaceFn)(const char* pName, int* pReturnCode);
    template<class Template>
    Template* GetInterface(const std::string ModuleName, const std::string InterfaceName);
	void InitInterfaces();
	void InitHooks();
}



