#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit seg_lock=P3^7;

uchar code bit_select[8] = {0,1,2,3,4,5,6,7};
uchar code seg_table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
uchar num,num1,num2,shi=0x00,ge=0x00;

void display(uchar, uchar);
void delay_on(uint delay_time);		//延时函数


void main()
{
	TMOD = 0x11;
	TH0 = (65536-45872)	/ 256;
	TL0 = (65536-45872) % 256;
	TH1 = (65536-45872)	/ 256;
	TL1 = (65536-45872) % 256;
	EA = 1;
	ET0 = 1;
	ET1 = 1;
	TR0 = 1;
	TR1 = 1;
	while(1)	
	{
		display(shi,ge);
	}
}

void display(uchar shi, uchar ge)
{
	seg_lock = 1;			//送
	P0 = seg_table[shi];	//段选
	seg_lock = 0;  			//数据入74CH573
	P0 = 0x00;				//送位选信号前关闭所有显示，避免打开位选时原来数据
	P2 = bit_select[0];
	delay_on(5);

   	seg_lock = 1;
	P0 = seg_table[ge];
	seg_lock = 0;
	P0 = 0x00;
	P2 = bit_select[1];
	delay_on(5);
} 

void delay_on(uint delay_time)
{
	uint i;
	uint j;
	for(i=0;i<=delay_time;i++)
		for(j=0;j<=delay_time;j++);
}