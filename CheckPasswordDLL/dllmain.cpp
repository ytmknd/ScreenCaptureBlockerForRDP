// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "stdafx.h"

#include <windows.h>
#include <msi.h>
#include <msiquery.h>

extern "C" UINT __declspec(dllexport) __stdcall CheckPassword(MSIHANDLE hInstall) {
	TCHAR Password[MAX_PATH];
	DWORD PasswordLen = MAX_PATH;

	MsiGetPropertyW(hInstall, L"PASSWORD", Password, &PasswordLen);
	MsiSetPropertyW(hInstall, L"PASSWORDACCEPTED", Password[0] == L'1' ? L"1" : L"0");
	return ERROR_SUCCESS;
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
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

