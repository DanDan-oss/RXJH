#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <windows.h>
#include "dataBase.h"

#ifdef _DEBUG
#define WinPrintA OutputDebugStringFA
#define WinPrintW OutputDebugStringFW
#else
#define WinPrintA
#define WinPrintW
#endif

void  __stdcall OutputDebugStringFA(const char* format, ...);
void __stdcall OutputDebugStringFW(const wchar_t* format, ...);


class GAME_KNAPSACK		// ��������
{
public:
	GAME_KNAPSACK(PKNAPSACK_BASE _m_pSack = (PKNAPSACK_BASE)KNAPSACK_BASE_ADDRES);
	PBACKPACK_ITEMS_BASE GetKnapGoods(int _index);		// ��ȡ��Ʒ����
	BOOL UseKnapGoods(int _index);

private:
	PKNAPSACK_BASE m_pSack = nullptr;
};


class GAME_ROLE		// �������
{
public:
	GAME_ROLE(PROLE_BASE _pRole = (PROLE_BASE)ROLE_BASE_ADDRES);
private:
	PROLE_BASE m_role = nullptr;
};


#endif