#include<reg52.h>
unsigned char num,num1,i,j;
unsigned char code table[]={0xc0,0xf9,0xa4,0xb0, 0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83, 0xc6,0xa1,0x86,0x8e}; 
void delayms( int xms);
void main()
{
	TMOD=0x01;
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;//定时器0定时50ms
	IT0=1;//外部中断0下降沿触发
	IT1=1;	
	EX0=1;
	EX1=1;
	ET1=1;
	EA=1;//开总中断	
	TR1=1;//开定时器1

	
	while(1)
	{
   P0=table[num1];
	}
}


void T1_time() interrupt 3
{
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	num++;
	if(num==20)
	{
		num=0;
		num1++;
		if(num1>8)
		 num1=0;
	}

}

void EX0_interrupt()interrupt 0
{
	P2=table[j];
	for(i=0;i>=8;i++)
	{
		P2=table[i];
		delayms(1000);
	}
}

void EX1_interrupt()interrupt 2
{
	for(j=0;j>=8;j++)
	{
		P1=table[j];
		delayms(1000);
	}
	P1 = table[15];
}

void delayms(int xms)
{
	int x,y;
	for(x=xms;x>0;x--)
	 for(y=110;y>0;y--);
}