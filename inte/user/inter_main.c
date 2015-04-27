#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int
sbit led_1 = P0^0;
uchar count;


void main()
{
	TMOD = 0x01;
	TH0 = (65536-45872)	/ 256;
	TL0 = (65536-45872) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	while(1)
	{
		if(count==20)	
		{
			count=0;
			led_1 = ~led_1;
		}
	};
}

void T0_time() interrupt 1
{
	TH0 = (65536-45872)	/ 256;
	TL0 = (65536-45872) % 256;
	count++;
}
