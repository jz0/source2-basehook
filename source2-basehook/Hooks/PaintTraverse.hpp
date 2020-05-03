#pragma once
#include "../Include.hpp"
#include "../Source2SDK/ISurface.hpp"
#include "../Source2SDK/CEngineVGUI.hpp"

typedef void(__fastcall* oPaintTraverse)(void*, IVGuiPaintSurface*, unsigned long long, bool, bool);
extern oPaintTraverse OriginalPaint;

void __fastcall hkPaintTraverse(void* Panel, IVGuiPaintSurface* Surface, unsigned long long VGuiPanel, bool ForceRepaint, bool AllowForce);

