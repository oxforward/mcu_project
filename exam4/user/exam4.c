/******************************
*
*60S倒计时实验
*
******************************/
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit bit1 = P2^0;
sbit bit2 = P2^1;

uchar code num[]={			//Common anode LED code table
0xc0, 0xf9, 0xa4, 0xb0,
0x99, 0x92, 0x82, 0xf8,
0x80, 0x90, 0x88, 0x83,
0xc6, 0xa1, 0x86, 0x8e};

void delay_on(uint delay_time)		//Delay function
{
	int i;
	int j;
	for(i=0; i<=delay_time; i++)
		for(j=0; j<=delay_time; j++);
}

void main()
{
	while(1){
		P1 = num[2];
		bit1 = 1;
		bit2 = 0;		
		delay_on(10);
		P1 = 0xff;
		delay_on(3);
		P1 = num[3];
		bit2 = 1;
		bit1 = 0;		
		delay_on(10);
		P1 = 0xff;
		delay_on(3);
	
	}
}


