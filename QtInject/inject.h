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
    VOID CALLBACK GetProceInfo(_In_ QString& _strProcessName, _In_ QString& _strWinTitle);      // ������ȡPID
    VOID CALLBACK SendKeyBoard(_In_ HWND _hWnd, _In_ QString& _userName);                       // ���ͼ�����Ϣ
    HMODULE CALLBACK GetProcessModuleBaseW(_In_ HANDLE _hProcess, _In_ QString& _moduleNameW);      // ����ָ������ģ���ַ
    UINT64 CALLBACK GetFunAddrByName32(_In_ HANDLE _hProcess, _In_ QString& _strModName, _In_ QString& _strFunName);   // ��ȡָ��32λ����ָ��ģ�鵼������

    VOID CALLBACK Login(_In_ HWND _hwnd, _In_ QString& _userName, _In_ QString& _userPass);
    VOID CALLBACK InjectDll(_In_ DWORD _procID, _In_ QString& _dllPath);


private:
    Ui::Inject *ui;
};



#endif // INJECT_H
