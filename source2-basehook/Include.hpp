#pragma once
#define WIN32_LEAN_AND_MEAN       

#include <windows.h>
#include <string>
#include <memory>
#include <vector>
#include <cmath>

//Macros
#define Packed
#pragma pack(push,1)

#define Sig(Module, Signature)Utilities::FindPattern(Module, Signature)

template<typename Fn> inline Fn CallVfunc(const PVOID Virtual, int Index) { return (Fn) * (*(const PVOID**)Virtual + Index); }

//SDK
#include "Source2SDK/SDK.hpp"

//Base
#include "Console.hpp"
#include "Utilities/VMTHook.hpp"
#include "Utilities/Utilities.hpp"
#include "Base.hpp"

//Hooks
#include "Hooks/PaintTraverse.hpp"
#include "Hooks/CreateMove.hpp"
#include "Hooks/LevelInit.hpp"

//Engine renderer
#include "Renderer/Renderer.hpp"



