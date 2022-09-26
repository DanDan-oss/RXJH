#include "gameapp.h"


GameApp::GameApp(DWORD dwProcId, HWND hWind)
    :procID(dwProcId),hwnd(hWind)
{

}


int GameApp::GetDownkeyCode(char _key)
{
    return 0;
}

DWORD GameApp::GetProcessID(WCHAR* szProcessName)
{
    HANDLE hProceessnap;		// 进程快照句柄
    PROCESSENTRY32 pe32 = { 0 };
    BOOL hProcess = 0;			// 是否获取到快照
    LONG processID = 0;

    hProceessnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProceessnap == INVALID_HANDLE_VALUE)
        return 0;

    pe32.dwSize = sizeof(pe32);
    hProcess = Process32First(hProceessnap, &pe32);
    while (hProcess)
    {
        if (!wcscmp(pe32.szExeFile, szProcessName))
        {
            processID = pe32.th32ProcessID;
            break;
        }
        hProcess = Process32Next(hProceessnap, &pe32);
    }

    CloseHandle(hProceessnap);
    return processID;
}

void __cdecl OutputDebugStringFA(const char* format, ...)
{
	va_list v1Args;
	char* strBuffer = (char*)GlobalAlloc(GPTR, 4009);

	va_start(v1Args, format);
	_vsnprintf(strBuffer, 4096 - 1, format, v1Args);
	va_end(v1Args);
	strcat(strBuffer, "\n");
	OutputDebugStringA(strBuffer);
	GlobalFree(strBuffer);
	return;
}

void __cdecl OutputDebugStringFW(const wchar_t* format, ...)
{
	va_list v1Args;
	wchar_t* strBuffer = (wchar_t*)GlobalAlloc(GPTR, 4009);

	va_start(v1Args, format);
	_vswprintf_c(strBuffer, 4096 - 1, format, v1Args);
	va_end(v1Args);
	wcscat(strBuffer, L"\n");
	OutputDebugStringW(strBuffer);
	GlobalFree(strBuffer);
	return;
}

