#include "inject.h"
#include "ui_inject.h"
#include "gameapp.h"
#include  <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <memory.h>
#include<Psapi.h>

#include "sockexport.h"


#define  GAME_NAME L"Client.exe"
#define  WINDOW_TITLE L"YB_OnlineClient"
#define PLAYER_USER "eVvUq4P6pHIN"
#define PLAYER_PASS "rujdUQ1gA1y8"


BOOL CALLBACK Inject::EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	// 遍历窗口获取游戏进程窗口句柄
	QTreeWidget* treeWidget = (QTreeWidget*)lParam;
	QTreeWidgetItem* pTreeItem = nullptr;
	CHAR WndTitleA[MAX_PATH] = { 0 };
	DWORD dwProcessID = 0;
	DWORD iCount = treeWidget->topLevelItemCount();

	// 通过窗口句柄取得进程ID和窗口标题
	GetWindowThreadProcessId(hwnd, &dwProcessID);
	GetWindowTextA(hwnd, WndTitleA, MAX_PATH);

	// 遍历当前编辑框中已有PID和窗口标题查找是否相等
	for (int i = 0; i < iCount; ++i)
	{
		pTreeItem = treeWidget->topLevelItem(i);
		if (dwProcessID == pTreeItem->text(1).toInt() && !QString::compare(WndTitleA, pTreeItem->text(2)))
		{
			pTreeItem->setText(3, QString::number((int)hwnd, 16));
			break;
		}
	}
	return TRUE;
}

Inject::Inject(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::Inject)
{
	ui->setupUi(this);

	WCHAR str[] = L"SVGA";



	// 遍历进程获取相关进程信息
	this->ui->treeWidget->setColumnCount(4);
	this->ui->treeWidget->setHeaderLabels(QStringList() << "应用程序" << "PID(Dec)" << "窗口标题" << "窗口句柄(Hex)");

	QString appName = QString::fromWCharArray(GAME_NAME);
	QString winTitle = QString::fromWCharArray(WINDOW_TITLE);

	this->GetProceInfo(appName, winTitle);


	this->ui->EDIT_USER->setText(PLAYER_USER);
	this->ui->EDIT_PASS->setText(PLAYER_PASS);

	// 选择DLL路径按钮被点击
	connect(this->ui->BTN_FILE, &QPushButton::clicked, [=]() {
		QString filePath = QFileDialog::getOpenFileName(this, "DLL路径", "/", "动态库(*.dll);;静态库(*.lib);;所有(*.*)");
		if (!filePath.size())
			return;
		this->ui->EDIT_DLLPATH->setText(filePath);
		return;
		});

	// 登录按钮被点击
	connect(this->ui->BTN_LOGIN, &QPushButton::clicked, [=]() {
		QTreeWidgetItem* pTreeItem = this->ui->treeWidget->currentItem();
		if (!pTreeItem)
		{
			QMessageBox::warning(this, "警告", "未选中需要自动登录的窗口");
			return;
		}
		QString UserName = this->ui->EDIT_USER->toPlainText();
		QString UserPass = this->ui->EDIT_PASS->toPlainText();
		HWND hWnd = (HWND)(pTreeItem->text(3).toInt(nullptr, 16));
		if (!hWnd)
		{
			QMessageBox::warning(this, "警告", "窗口句柄获取失败");
			return;
		}
		this->Login(hWnd, UserName, UserPass);
		return;
		});

	// 刷新按钮被点击
	connect(this->ui->BTN_REFRESH, &QPushButton::clicked, [=]() {
		int iIndex = this->ui->treeWidget->topLevelItemCount();
		while (iIndex--)
		{
			QTreeWidgetItem* pTreeItem = this->ui->treeWidget->topLevelItem(0);
			delete pTreeItem;
		}
		QString appNameP = QString::fromWCharArray(GAME_NAME);
		QString winTitleP = QString::fromWCharArray(WINDOW_TITLE);
		this->GetProceInfo(appNameP, winTitleP);
		});

	// 注入按钮被点击
	connect(this->ui->BTN_LOAD, &QPushButton::clicked, [=]() {
		QTreeWidgetItem* pTreeItem = this->ui->treeWidget->currentItem();
		QString dllPath = this->ui->EDIT_DLLPATH->toPlainText();
		DWORD dwProcID = 0;

		if (!pTreeItem)
		{
			QMessageBox::warning(this, "警告", "未选中需要注入的应用程序");
			return;
		}
		dwProcID = pTreeItem->text(1).toInt();
		if (dwProcID <= 0)
		{
			QMessageBox::warning(this, "警告", "获取需要注入应用程序PID错误");
			return;
		}
		if (dllPath.size() <= 0)
		{
			QMessageBox::warning(this, "警告", "未选择注入DLL路径");
			return;
		}
		this->InjectDll(dwProcID, dllPath);

		});

	this->update();
}

Inject::~Inject()
{
	delete ui;
}


DWORD CALLBACK Inject::GetDownkeyCode(char _key)
{
    if (_key > 96)
    {
        return _key - 32;
    }
    if (_key > 40 && _key < 97)
        return _key;

    return _key;

}


void CALLBACK Inject::GetProceInfo(_In_ QString& _strProcessName, _In_ QString& _strWinTitle)
{
    HANDLE hProceessnap;		// 进程快照句柄
    PROCESSENTRY32W pe32 = { 0 };
    BOOL hProcess = 0;			// 是否获取到快照
    LONG processID = 0;
	QTreeWidgetItem* qLiItem = nullptr;

    hProceessnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProceessnap == INVALID_HANDLE_VALUE)
        return;

    pe32.dwSize = sizeof(pe32);
    hProcess = Process32FirstW(hProceessnap, &pe32);
    while (hProcess)
    {
        if (!wcscmp(pe32.szExeFile, _strProcessName.toStdWString().data()))
        {
            processID = pe32.th32ProcessID;
            processID = pe32.th32ProcessID;
            qLiItem = new QTreeWidgetItem(this->ui->treeWidget, QStringList()<<  _strProcessName << QString::number(processID) << _strWinTitle);
        }
        hProcess = Process32NextW(hProceessnap, &pe32);
    }
    QTreeWidget* treeWidget =this->ui->treeWidget;
    EnumWindows(Inject::EnumWindowsProc, (LPARAM)treeWidget);
    CloseHandle(hProceessnap);
    return;
}

HMODULE CALLBACK Inject::GetProcessModuleBaseW(HANDLE _hProcess, QString& _moduleNameW)
{
    // 遍历进程模块,
    DWORD dwRet = 0;
    WCHAR wszFuncName[50] = { 0 };
    HMODULE hModule[100] = { 0 };

    // 枚举进程中模块信息
    //if(!EnumProcessModules(hProcess, (HMODULE*)(hModule), sizeof(hModule), &dwRet)) 可以替换成32位的
    if (!K32EnumProcessModulesEx(_hProcess, (HMODULE*)hModule, sizeof(hModule), &dwRet, LIST_MODULES_32BIT))
        return 0;

    for (int i = 0; i < dwRet/sizeof(HMODULE); ++i)
    {
        //GetModuleBaseNameA(_hProcess, hModule[i], wcFuncName, 50); 可以替换成32位的
        DWORD dwDllNameSize = K32GetModuleBaseNameW(_hProcess, hModule[i], wszFuncName, sizeof(wszFuncName));
        if (!wcscmp(wszFuncName, _moduleNameW.toStdWString().data()))
            return hModule[i];
        memset(wszFuncName, 0, sizeof(WCHAR) * dwDllNameSize);
        continue;
    }
	qDebug() << "未找到 " << _moduleNameW;
    return NULL;
}

UINT64 CALLBACK Inject::GetFunAddrByName32(HANDLE _hProcess, QString& _strModName, QString& _strFnName)
{

	HANDLE hMod;
	PVOID BaseAddress = NULL;
	USHORT index = 0;
	ULONG addr, i;
	CHAR pFuncName[30] = { 0 };

	IMAGE_DOS_HEADER dosheader;
	IMAGE_OPTIONAL_HEADER32 opthdr;//IMAGE_OPTIONAL_HEADER64
	IMAGE_EXPORT_DIRECTORY exports;

	PULONG pAddressOfFunctions;	
	PULONG pAddressOfNames;
	PUSHORT pAddressOfNameOrdinals;

	//获取模块基址
	BaseAddress = this->GetProcessModuleBaseW(_hProcess, _strModName);
	if (!BaseAddress)
        return 0;

	//获取PE头
	hMod = BaseAddress;
	ReadProcessMemory(_hProcess, hMod, &dosheader, sizeof(IMAGE_DOS_HEADER), 0);
	ReadProcessMemory(_hProcess, (BYTE*)hMod + dosheader.e_lfanew + 24, &opthdr, sizeof(IMAGE_OPTIONAL_HEADER32), 0);
	//ReadProcessMemory(hProcess, (BYTE*)hMod + dosheader.e_lfanew + 24, &opthdr, sizeof(IMAGE_OPTIONAL_HEADER64), 0);

	//查找导出表 
	ReadProcessMemory(_hProcess, ((BYTE*)hMod + opthdr.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress), &exports, sizeof(IMAGE_EXPORT_DIRECTORY), 0);


	pAddressOfFunctions = (ULONG*)((BYTE*)hMod + exports.AddressOfFunctions);
	pAddressOfNames = (ULONG*)((BYTE*)hMod + exports.AddressOfNames);
	pAddressOfNameOrdinals = (USHORT*)((BYTE*)hMod + exports.AddressOfNameOrdinals);

	//对比函数名 
	for (i = 0; i < exports.NumberOfNames; ++i)
	{
		ReadProcessMemory(_hProcess, pAddressOfNameOrdinals + i, &index, sizeof(USHORT), 0);
		//ReadProcessMemory(_hProcess, pAddressOfFunctions + index, &addr, sizeof(ULONG), 0);

		ULONG a = 0;
		ReadProcessMemory(_hProcess, pAddressOfNames + i, &a, sizeof(ULONG), 0);
		ReadProcessMemory(_hProcess, (BYTE*)hMod + a, pFuncName, 30, 0);
		ReadProcessMemory(_hProcess, pAddressOfFunctions + index, &addr, sizeof(ULONG), 0);

        qDebug() << "pAddressOfNames: " << a << "  pFuncName:" << pFuncName << " pAddressOfFunctions:"<< (UINT64)BaseAddress + addr;
		if (!_stricmp(pFuncName, _strFnName.toStdString().data()))
		{
			UINT64 funAddr = (UINT64)BaseAddress + addr;
			return funAddr;
		}
	}
	return 0;
}


void CALLBACK Inject::SendKeyBoard(HWND _hWnd, QString& _userName)
{
    std::string strInfo =_userName.toStdString();
    const char* user =strInfo.data();

    for (int i = 0; i <= strInfo.size(); ++i)
    {
        if (user[i] > 59 && user[i] < 91)
        {
            keybd_event(VK_LSHIFT, 0, 0, 0);
            Sleep(20);
            keybd_event(GetDownkeyCode(user[i]), 0, 0, 0);
            Sleep(20);

            keybd_event(GetDownkeyCode(user[i]), 0, KEYEVENTF_KEYUP, 0);
            Sleep(20);
            keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0);
            Sleep(20);
            continue;
        }
        keybd_event(GetDownkeyCode(user[i]), 0, 0, 0);
        Sleep(20);
        keybd_event(GetDownkeyCode(user[i]), 0, KEYEVENTF_KEYUP, 0);
        Sleep(20);
    }
}

void CALLBACK Inject::Login(HWND _hwnd, QString& _userName, QString& _userPass)
{
    RECT r;
    //获取窗口坐标
    ::GetWindowRect(_hwnd, &r);
    //获取窗口坐标
    //::SetWindowPos(hWnd, HWND_TOP, r.left, r.top, r.right-r.left, r.bottom-r.top, SWP_SHOWWINDOW);
    //设置鼠标的位置
    ::SetCursorPos(r.left + 350, r.top + 470);
    Sleep(200);

    //鼠标左键单击 使窗口获取焦点
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//点下左键
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开左键
    Sleep(50);

    // 发送键盘输入消息 账号
    this->SendKeyBoard(_hwnd, _userName);
    keybd_event(VK_TAB, 0, 0, 0);
    Sleep(20);
    keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
    Sleep(20);
    // 密码
    this->SendKeyBoard(_hwnd, _userPass);
    keybd_event(VK_RETURN, 0, 0, 0);
    Sleep(20);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
    Sleep(20);

    //选频道
    ::SetCursorPos(r.left + 440, r.top + 315);
    Sleep(100);

    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//点下左键
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开左键
    Sleep(100);

    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//点下左键
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开左键
    Sleep(100);

    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//点下左键
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开左键
    Sleep(100);

}

void CALLBACK Inject::InjectDll(_In_ DWORD _procID, _In_ QString& _dllPath)
{
	HANDLE hnProc = 0;		// 游戏进程句柄
	LPVOID pVirAdree = 0;	// 指向申请的远程空间
	HANDLE hnThre = NULL;	// 远线程句柄
    char dllPath[MAX_PATH];

    memset(dllPath, 0, MAX_PATH);
    memcpy(dllPath, _dllPath.toStdString().data(),_dllPath.size());

    if (_procID <= 0)
    {
        QMessageBox::warning(this, "警告\0", "错误的进程ID\0");
        return;
    }
    if (_dllPath.size() <= 0)
    {
        QMessageBox::warning(this, "警告\0", "错误的DLL路径\0");
        return;
    }

    do 
    {
		hnProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, _procID);
		if (!hnProc)
		{
            QMessageBox::critical(this, "错误\0", "打开目标进程失败\0");
            break;
		}
		QString dllName("KERNEL32.DLL");
		QString funcName("LoadLibraryA");
		//PTHREAD_START_ROUTINE pfnStartAddr = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32"), "LoadLibraryA");
		PTHREAD_START_ROUTINE pfnStartAddr = (PTHREAD_START_ROUTINE)this->GetFunAddrByName32(hnProc, dllName, funcName);
		if (!pfnStartAddr)
		{
			QMessageBox::critical(this, "错误\0", "获取载入地址失败\0");
			break;
		}
        pVirAdree = VirtualAllocEx(hnProc, NULL, MAX_PATH, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (!pVirAdree)
		{
            QMessageBox::critical(this, "错误\0", "远线程内存申请失败\0");
			break;
		}
        if (!WriteProcessMemory(hnProc, pVirAdree, dllPath, strlen(dllPath)+1, NULL))
		{
            QMessageBox::critical(this, "错误\0", "远线程内存写入失败\0");
			break;
		}
        hnThre = CreateRemoteThread(hnProc, NULL, 0, pfnStartAddr, pVirAdree, 0, NULL);
		if (!hnThre)
		{
            QMessageBox::critical(this, "错误\0", "远线程载入DLL失败\0");
            break;
		}

        DWORD dwStatus = WaitForSingleObject(hnThre, 1000 * 10);
        qDebug() << "线程执行状态:" << dwStatus;
        BOOL blStatus = GetExitCodeThread(hnThre, &dwStatus);
        qDebug() << "获取的线程状态:" << dwStatus << blStatus;
        QMessageBox::information(this, "注入成功", _dllPath);
        Sleep(1000);

    } while (0);

	if (hnThre)
		CloseHandle(hnThre);
	if (pVirAdree)
		VirtualFreeEx(hnProc, pVirAdree, NULL, MEM_RELEASE);
	if (hnProc)
		CloseHandle(hnProc);
}


