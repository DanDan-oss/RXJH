#ifndef INJECT_H
#define INJECT_H
#include <windows.h>
#include <QWidget>

namespace Ui {
class Inject;
}

class Inject : public QWidget
{
    Q_OBJECT

public:
    static BOOL CALLBACK EnumWindowsProc(_In_ HWND hwnd, _In_ LPARAM lParam);
    static DWORD CALLBACK GetDownkeyCode(_In_ char _key);

    explicit Inject(QWidget *parent = nullptr);
    ~Inject();

private:
    VOID CALLBACK GetProceInfo(_In_ QString& _strProcessName, _In_ QString& _strWinTitle);      // 遍历获取PID
    VOID CALLBACK SendKeyBoard(_In_ HWND _hWnd, _In_ QString& _userName);                       // 发送键盘消息
    HMODULE CALLBACK GetProcessModuleBaseW(_In_ HANDLE _hProcess, _In_ QString& _moduleNameW);      // 遍历指定进程模块基址
    UINT64 CALLBACK GetFunAddrByName32(_In_ HANDLE _hProcess, _In_ QString& _strModName, _In_ QString& _strFunName);   // 获取指定32位进程指定模块导出函数

    VOID CALLBACK Login(_In_ HWND _hwnd, _In_ QString& _userName, _In_ QString& _userPass);
    VOID CALLBACK InjectDll(_In_ DWORD _procID, _In_ QString& _dllPath);


private:
    Ui::Inject *ui;
};



#endif // INJECT_H
