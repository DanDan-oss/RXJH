#include <windows.h>
#include <iostream>
#include <string>

#define USER_NAME "eVvUq4P6pHIN"
#define USER_PASS "rujdUQ1gA1y8"

#define  WINDOW_CLASS L"D3D Window"
#define WINDOW_TITLE L"YB_OnlineClient"

//#define  WINDOW_CLASS L"Notepad"
// 
//#define WINDOW_TITLE L"Edit"

int GetDownkeyCode(char _key);
void SendUserName(HWND hWnd, std::string& _userName);
void Login(HWND hWnd, std::string& _userName, std::string& _userPass);

int main()
{
	HWND hWnd = FindWindowW(WINDOW_CLASS, WINDOW_TITLE);
	if (!hWnd)
		return 0;
	std::string user = USER_NAME;
	std::string pass = USER_PASS;
	Login(hWnd, user, pass);

	return 0;
}

void Login(HWND hWnd, std::string& _userName, std::string& _userPass)
{
	RECT r;
	//获取窗口坐标
	::GetWindowRect(hWnd, &r);
	//获取窗口坐标
	//::SetWindowPos(hWnd, HWND_TOP, r.left, r.top, r.right-r.left, r.bottom-r.top, SWP_SHOWWINDOW);
	//设置鼠标的位置
	::SetCursorPos(r.left + 350, r.top + 470);
	Sleep(200);

	//鼠标左键单击
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//点下左键 
	Sleep(50);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开左键
	Sleep(50);

	SendUserName(hWnd, _userName);

	keybd_event(VK_TAB, 0, 0, 0);
	Sleep(20);
	keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
	Sleep(20);

	SendUserName(hWnd, _userPass);
	keybd_event(VK_RETURN, 0, 0, 0);
	Sleep(20);
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
	Sleep(20);

	::SetCursorPos(r.left + 430, r.top + 330);
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
void SendUserName(HWND hWnd, std::string& _userName)
{
	const char* user = _userName.data();
	for (int i = 0; i <= _userName.size(); ++i)
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

int GetDownkeyCode(char _key)
{
	

	if (_key > 96)
	{
		return _key - 32;
	}
	if (_key > 40 && _key < 97)
		return _key;

	return _key;

	//char asccii[][2] = {
	//	// 大写 A-Z [ '\' ] ^ _
	//	65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76 ,77,78,79, 80, 81,
	//	82, 83, 84, 85,86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
	//	// 小写 a-z {|}~
	//	97,98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114,
	//	115, 116, 117, 118, 119, 120,121, 122, 123, 124,125, 126 };
}