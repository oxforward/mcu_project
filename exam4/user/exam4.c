/******************************
*
*60S倒计时实验
*时间与实际时间有点出入
******************************/
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit bit1 = P2^0;
sbit bit2 = P2^1;
int countTime = 59;
int ten = 5,unit = 9, count = 0;

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

void init()
{
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	TMOD = 0x01;
	ET0 = 1;
	EA = 1;
}

void main()
{
	init();
	TR0 = 1;
	while(1){
		P1 = num[ten];
		bit1 = 1;
		bit2 = 0;		
		delay_on(3);
		P1 = 0xff;		//消影
		delay_on(3);
		P1 = num[unit];
		bit2 = 1;
		bit1 = 0;		
		delay_on(3);
		P1 = 0xff;
		delay_on(3);	
	}
}

void timer_0() interrupt 1
{
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	count++;
	if(count==20){
		count = 0;
		countTime--;
		if(countTime == -1){
			countTime = 59;			
		}
		ten = countTime / 10;
		unit = countTime % 10;
	}	
}


