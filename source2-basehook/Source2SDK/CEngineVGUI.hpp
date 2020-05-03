#pragma once

class IVPanel
{
public:
    const char* GetName(void* ptr, unsigned long long vguiPanel)
    {
        typedef const char* (__thiscall* OriginalFn)(void*, unsigned long long);
        return CallVfunc<OriginalFn>(ptr, 50)(ptr, vguiPanel);
    }
};

extern IVPanel* pPanel;