#include <windows.h>
#include "resource.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved);

class DllManage
{
	/* ��ͬ�Ĵ��ڸ���ҵ�����Ҫ��д DialogProc�ص�*/
public:
	static DWORD WINAPI InitDllContext(LPVOID lpParameter);	// ��ʼ��DLL������
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
	HMODULE hDllMod = 0;		// ��ǰDLL��ģ����
	HANDLE hDllThread = 0;		// DLL�����߳�
	HWND hDllDialog = 0;		//
	//DLGPROC FuncDialogProc = nullptr;
};



