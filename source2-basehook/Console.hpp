#pragma once
#include "Include.hpp"

#include "Source2SDK/Color.hpp"

typedef void(_cdecl* MsgFn)(const Color& color, const char* msg, ...);
extern MsgFn Msg;