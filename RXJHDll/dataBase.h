#ifndef GAME_DATABASE_H
#define GAME_DATABASE_H

#define ROLE_BASE_ADDRES 0x02C5AE68
#define KNAPSACK_BASE_ADDRES 0x2E8213C		// ��������

// ��װ��lib �Ѿ������µ������빦�ܿ���뿪
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
	unsigned int xin;			// ��
	unsigned int qi;			// ��
	unsigned int ti;			// ��
	unsigned int hun;			// ��
	char know_4[0x8];
	unsigned int gongJi;		// ����
	unsigned int fangYu;		// ����
	unsigned int mingZhong;		// ����
	unsigned int huiBi;			// �ر�
	char know_5[4];
	unsigned int wuGongMingZhong;// �书����
	char know_6[4];
	unsigned int coin;			// ��ǰ�����еĽ��
}ROLE_BASE, *PROLE_BASE;

#define KNAPSACK_NUM 36

//Backpack items
typedef const struct  _BACKPACK_ITEMS_BASE		// ������Ʒ
{	// [[0x2E8213C]+1*4+0x53c]
	char know_00[0x54];
	unsigned int itemID;			// ��ƷID
	char know_01[0x0c];
	char itemName[0x10];			// ��Ʒ����
	char know_02[0x85];
	char itemDesc[0x10];			// ��Ʒ����
	char know_03[0xc43];
	unsigned int itenNum;			// ��Ʒ����

}BACKPACK_ITEMS_BASE, *PBACKPACK_ITEMS_BASE;


typedef const struct _KNAPSACK_BASE		// ��������
{	// [2E8213C]+1*4+053c
	char know_00[0x53c];
	const PBACKPACK_ITEMS_BASE pBackItem[KNAPSACK_NUM];
}KNAPSACK_BASE, *PKNAPSACK_BASE;


#endif
