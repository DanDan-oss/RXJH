#include "gameData.h"
#include <iostream>


GAME_KNAPSACK::GAME_KNAPSACK(PKNAPSACK_BASE _m_pSack)
	:m_pSack(_m_pSack)
{
	for (int i = 0; i < KNAPSACK_NUM; ++i)
	{
		if (this->m_pSack->pBackItem[i])
		{
			PBACKPACK_ITEMS_BASE kPack = this->m_pSack->pBackItem[i];
			WinPrintA("[dbg]:背包[%d]:%s 数量%d ", i, kPack->itemName, kPack->itenNum);
		}
	}
}

PBACKPACK_ITEMS_BASE GAME_KNAPSACK::GetKnapGoods(int _index)
{
	return this->m_pSack->pBackItem[_index];
}

BOOL GAME_KNAPSACK::UseKnapGoods(int _index)
{
	
}


GAME_ROLE::GAME_ROLE(PROLE_BASE _pRole)
	:m_role(_pRole)
{
	WinPrintA("[dbg]:人物: %s 当前血量%d/%d 当前魔法%d/%d 拥有金币%d", this->m_role->name, this->m_role->hp, this->m_role->hp_max,
		this->m_role->mp, this->m_role->mp_max, this->m_role->coin);
	return;
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



