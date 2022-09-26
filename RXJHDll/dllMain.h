#include <windows.h>
#include "resource.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved);

class DllManage
{
	/* 不同的窗口根据业务可能要重写 DialogProc回调*/
public:
	static DWORD WINAPI InitDllContext(LPVOID lpParameter);	// 初始化DLL上下文
	static BOOL CALLBACK DialogProc(HWND hwndDlg, UINT UMsg, WPARAM wParam, LPARAM lParam);
public:

	DllManage(HMODULE _hDllMod, HANDLE _hDllThread);
	~DllManage();

	HANDLE WINAPI GetDllHandle();
	HANDLE WINAPI GetDllThread();
	HWND WINAPI GetDllDlg();
	DLGPROC WINAPI GetDlgProc();

	BOOL WINAPI SetDllDlg(HWND _hDllDlg);

private:
	HMODULE hDllMod = 0;		// 当前DLL的模块句柄
	HANDLE hDllThread = 0;		// DLL调度线程
	HWND hDllDialog = 0;		//
	//DLGPROC FuncDialogProc = nullptr;
};



