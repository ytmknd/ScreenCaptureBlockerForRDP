#pragma once

#include <windows.h>

#ifdef HOOKDLL_EXPORTS
#define DLLHOOKPREF __declspec(dllexport)
#else
#define DLLHOOKPREF __declspec(dllimport)
#endif

DLLHOOKPREF bool InstallHook(HWND _hWnd);
DLLHOOKPREF bool UninstallHook();

#ifndef HOOKDLL_EXPORTS
#undef DLLHOOKPREF
#endif