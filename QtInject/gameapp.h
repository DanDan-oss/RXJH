#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <QString>

void  __stdcall OutputDebugStringFA(const char* format, ...);
void __stdcall OutputDebugStringFW(const wchar_t* format, ...);

#ifdef _DEBUG
#define WinPrintA OutputDebugStringFA
#define WinPrintW OutputDebugStringFW
#else
#define WinPrintA
#define WinPrintW
#endif

class GameApp
{
public:

    static DWORD GetProcessID(WCHAR* szProcessName);

    GameApp(DWORD dwProcId, HWND hWind);

private:
    static void Login(HWND hWnd, std::string& _userName, std::string& _userPass);
    static int GetDownkeyCode(char _key);
    static void SendUserName(HWND hWnd, std::string& _userName);

private:
    HWND hwnd=NULL;
    DWORD procID = NULL;


};




#endif // GAMEAPP_H
