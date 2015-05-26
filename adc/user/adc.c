#include<reg52.h>

sbit start = P3^0;
sbit eoc = P3^1;
sbit oe = P3^2;
sbit ale = P3^3;
sbit clk = P3^4;
sbit lock = P3^5;
void chose_channel();
void delay();
void main()
{
	TMOD=0x02;      //����T0,������ʽ2
	TH0=0x216;      //TH0��ֵ
	TL0=0x216;   //TH1��ֵ
	EA=1;     //�����ж�
	ET0=1;    //��TO�ж�����λ
	TR0=1;     //��T0
	while(1){
		chose_channel();
		while(!eoc);
		lock = 1;
		oe = 1;
		delay();
		lock = 0;
		oe = 0;			
	}
}

void inter_1() interrupt 1
{
 clk = ~clk;
}


void delay()
{
	int i,j;
	for(i = 1000; i < 0; i--)
		for(j = 1000; j < 0; j--);
}

void chose_channel()
{
	ale = 0;
	
	start = 1;
	delay();
	start = 0;	
}
