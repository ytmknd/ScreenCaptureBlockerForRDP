// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "stdafx.h"

#include <wchar.h>
#include "HookDLL.h"

using namespace std;

#pragma data_seg("hookdll")
HWND hWnd = nullptr;
DWORD pid = 0;
#pragma data_seg()

HINSTANCE hInst = nullptr;
HHOOK hHook = nullptr;

LRESULT CALLBACK cbtProc(int code, WPARAM wParam, LPARAM lParam) {
	if (code > 0) {
		if (code == HCBT_ACTIVATE) {
			TCHAR buf[128];
			if (GetClassName((HWND)wParam, (LPWSTR)buf, 128)) {
				if (!wcscmp(L"TscShellContainerClass", buf) // Remote Desktop Window class
					|| !wcscmp(L"RAIL_WINDOW", buf)) {		// RemoteApp Window class
					SetWindowDisplayAffinity((HWND)wParam, WDA_MONITOR);
				}
			}
		}
	}
	return CallNextHookEx(hHook, code, wParam, lParam);
}

DLLHOOKPREF bool InstallHook(HWND _hWnd) {
	if (hHook) return false;
	hWnd = _hWnd;
	GetWindowThreadProcessId(hWnd, &pid);
	return (hHook = SetWindowsHookEx(WH_CBT, cbtProc, hInst, 0)) != NULL;
}

DLLHOOKPREF bool UninstallHook() {
	if (!hHook) return false;
	bool res = UnhookWindowsHookEx(hHook) != NULL;
	if (res) hHook = NULL;
	return res;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		hInst = reinterpret_cast<HINSTANCE>(hModule);
		break;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		hInst = nullptr;
		break;
	}
	return TRUE;
}
