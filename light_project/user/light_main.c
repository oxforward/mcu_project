#include <reg52.h>
#include <intrins.h>

#define uint unsigned int

void delay_on(uint delay_time)
{
	uint i;
	uint j;
	for(i=0;i<=delay_time;i++)
		for(j=0;j<=delay_time;j++);
}

//unsigned char code table[]={
//0x3f,0x06,0x5b,0x4f,
//0x66,0x6d,0x7d,0x07,
//0x7f,0x6f,0x77,0x7c,
//0x39,0x5e,0x79,0x71};

void main()
{	
	int temp;
	int led_count;
	while(1)
	{
		P0=0xfe;	//P0^0输出低电平
		temp = P0;
		for(led_count=7;led_count>=0;led_count--)
		{
			delay_on(255);
//			temp = temp<<1;
//			temp += 1;
//			P0 = temp;
		temp = _crol_(temp, 1);		// _crol_将temp循环左移1位，无需像上面再加1
		P0 = temp;
		}
	}	
}