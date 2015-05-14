#include <reg52.h>
#include <intrins.h>
#include "delay_on.h"

#define yuhui 2

sbit seg_lock=P3^7;

uchar code bit_select[8] = {0,1,2,3,4,5,6,7};

uchar code seg_table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

/************************************************
*名称：main
*功能：实现数码管的扫描
*输入：无
*输出：无
************************************************/
void main()
{
//	int i;
//	int j;

	
//	while(1)
//	{
//		for(i=0;i<=15;i++)
//		{
//			P2 = bit_select[2];
//			P0 = seg_table[i];
//			delay_on(230);
//		}
//	 }


//	while(1)
//	{
//		for(j=0;j<=7;j++)
//		{
//			P2 = bit_select[i];
//			P0 = seg_table[0];
//			delay_on(230);
//		}
//	}


	while(1)
	{
		seg_lock = 1;
		P0 = seg_table[1];
		seg_lock = 0;
		P0 = 0x00;	
		P2 = bit_select[0];
		delay_on(yuhui);
		seg_lock = 1;
		P0 = seg_table[2];
		seg_lock = 0;
		P0 = 0x00;	
		P2 = bit_select[1];
		delay_on(yuhui);
	
		seg_lock = 1;
		P0 = seg_table[3];
		seg_lock = 0;
		P0 = 0x00;	
		P2 = bit_select[2];
		delay_on(yuhui);
	
		seg_lock = 1;
		P0 = seg_table[4];
		seg_lock = 0;
		P0 = 0x00;	
		P2 = bit_select[3];
		delay_on(yuhui);

		seg_lock = 1;
		P0 = seg_table[5];
		seg_lock = 0;
		P0 = 0x00;	
		P2 = bit_select[4];
		delay_on(yuhui);

		seg_lock = 1;
		P0 = seg_table[6];
		seg_lock = 0;
		P0 = 0x00;	
		P2 = bit_select[5];
		delay_on(yuhui);

		seg_lock = 1;
		P0 = seg_table[7];
		seg_lock = 0;
		P0 = 0x00;	
		P2 = bit_select[6];
		delay_on(yuhui);

		seg_lock = 1;
		P0 = seg_table[8];
		seg_lock = 0;
		P0 = 0x00;	
		P2 = bit_select[7];
		delay_on(yuhui);
	}
		
}	


