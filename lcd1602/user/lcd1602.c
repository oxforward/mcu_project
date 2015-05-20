#include<reg52.h>
#include<intrins.h>
#include "boardinit.h"

#define uchar unsigned char
#define uint  unsigned int
void boardinit();
sbit E=P2^4;		//1602使能引脚
sbit RW=P2^6;		//1602读写引脚	
sbit RS=P2^5;		//1602数据/命令选择引脚 

void delay()
{
	int i,j;
	for(i=0; i<=10; i++)
	for(j=0; j<=2; j++)
;
}



void enable(uchar del)
{
	P0 = del;
	RS = 0;
	RW = 0;
	E = 0;
	delay();
	E = 1;
	delay();
}



void L1602_init(void)
{

	enable(0x38);	//0011 1000	系统功能设置：数据长度8bits,双行显示   
	enable(0x0c);	//0000 1100	显示开关控制:显示，光标不显示，禁止闪烁  
	enable(0x06);	//0000 0110	模式设置:光标右移,禁止滚动 
	enable(0x01);	//0000 0001	清屏
	//enable(0xc0);	//1100 0000	初始显示数据的位置为:000
}


void write(uchar del)
{
	P0 = del;
	RS = 1;
	RW = 0;
	E = 0;
	delay();
	E = 1;
	delay();
}



void L1602_char(uchar hang,uchar lie,char sign)
{
	uchar a;
	if(hang == 1) a = 0x80;
	if(hang == 2) a = 0xc0;
	a = a + lie - 1;
	enable(a);
	delay();
	write(sign);
}


void main()
{
	char al = '!' - 1;
	int i;
	boardinit();	

	L1602_init();
	L1602_char(1,1,al);
	for(i = 0 ; i <= 16; i++, al++){
		L1602_char(1,i,al);
	}
	for(i = 0 ; i <= 16; i++, al++){
		L1602_char(2,i,al);
	}
	while(1);
}
