#include "dllMain.h"
#include "gameData.h"

DllManage* pDll = nullptr;

GAME_ROLE role;
// ccccccccccccccccccaaaaaaaaaaaaaaaa
HMODULE hMod = NULL;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{

	// asdsadasdasdsa
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		hMod = hMod;
		CreateThread(NULL, 0, DllManage::InitDllContext, hModule, 0, NULL);
		break;
	}
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		if (pDll)
		{
			DestroyWindow(pDll->GetDllDlg());
			Sleep(1000);
			delete pDll;
		}

		break;
	}
	return TRUE;
}

DWORD WINAPI DllManage::InitDllContext(LPVOID lpParameter)
{
	pDll = new DllManage((HMODULE)lpParameter, GetCurrentThread());
	DialogBox((HINSTANCE)(lpParameter), MAKEINTRESOURCE(IDD_DIALOG_MAIN), NULL, DllManage::DialogProc);
	delete pDll;
	pDll = nullptr;
	FreeLibraryAndExitThread(hMod, 0);
	return 0;
}

BOOL CALLBACK  DllManage::DialogProc(HWND hwndDlg, UINT UMsg, WPARAM wParam, LPARAM lParam)
{
	switch (UMsg)
	{
	case WM_CREATE:

		break;
	case WM_CLOSE:
		DestroyWindow(hwndDlg);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		break;
	}

	return DefWindowProc(hwndDlg, UMsg, wParam, lParam);
}


DllManage::DllManage(HMODULE _hDllMod, HANDLE _hDllThread)
	:hDllMod(_hDllMod), hDllThread(_hDllThread)
{

}

DllManage::~DllManage()
{
}


HANDLE WINAPI DllManage::GetDllThread()
{
	return this->hDllMod;
}

HWND WINAPI DllManage::GetDllDlg()
{
	return this->hDllDialog;
}

DLGPROC WINAPI DllManage::GetDlgProc()
{
	return this->DialogProc;
}

BOOL WINAPI DllManage::SetDllDlg(HWND _hDllDlg)
{
	this->hDllDialog = _hDllDlg;
	return TRUE;
}

HANDLE WINAPI DllManage::GetDllHandle()
{
	return this->hDllMod;
}

