#ifndef GAME_DATABASE_H
#define GAME_DATABASE_H

#define ROLE_BASE_ADDRES 0x02C5AE68
#define KNAPSACK_BASE_ADDRES 0x2E8213C		// 背包对象

// 封装成lib 把经常更新的数据与功能块隔离开
typedef const struct _ROLE_BASE		
{	// 02C5AE68
	char name[0x10];
	char know_00[0x24];
	unsigned char lv;
	char know_0[0x4b];
	unsigned int hp;
	unsigned int mp;
	unsigned char know_1[0x4];
	unsigned int hp_max;
	unsigned int mp_max;
	unsigned int fengLu;
	char know_3[0x14];
	unsigned int  liLiang;
	unsigned int xin;			// 心
	unsigned int qi;			// 气
	unsigned int ti;			// 体
	unsigned int hun;			// 魂
	char know_4[0x8];
	unsigned int gongJi;		// 攻击
	unsigned int fangYu;		// 防御
	unsigned int mingZhong;		// 命中
	unsigned int huiBi;			// 回避
	char know_5[4];
	unsigned int wuGongMingZhong;// 武功命中
	char know_6[4];
	unsigned int coin;			// 当前背包中的金币
}ROLE_BASE, *PROLE_BASE;

#define KNAPSACK_NUM 36

//Backpack items
typedef const struct  _BACKPACK_ITEMS_BASE		// 背包物品
{	// [[0x2E8213C]+1*4+0x53c]
	char know_00[0x54];
	unsigned int itemID;			// 物品ID
	char know_01[0x0c];
	char itemName[0x10];			// 物品名字
	char know_02[0x85];
	char itemDesc[0x10];			// 物品描述
	char know_03[0xc43];
	unsigned int itenNum;			// 物品数量

}BACKPACK_ITEMS_BASE, *PBACKPACK_ITEMS_BASE;


typedef const struct _KNAPSACK_BASE		// 背包数组
{	// [2E8213C]+1*4+053c
	char know_00[0x53c];
	const PBACKPACK_ITEMS_BASE pBackItem[KNAPSACK_NUM];
}KNAPSACK_BASE, *PKNAPSACK_BASE;


#endif
