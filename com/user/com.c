#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int
uchar flag, a, i;
uchar code table[]="I get " ;

void init()
{
	TMOD = 0x20;	//设定T1定时器工作方式2
	TH1 = 0xfd;		//TI定时器装初值
	TL1 = 0xfd;		//TI定时器装初值，复位SMOD为0，所以此时波特率为9600
	TR1 = 1;		//启动TI定时器
	REN = 1;		//允许串口接收
	SM0 = 1;	   	//
	SM1 =1;		   	//SM0 SM1设定串口工作方式1
	EA = 1;			//开总中断
	ES = 1;		   	//开串口中断
}
void main()
{
	init();					//初始化
	while (1) {
		if(flag==1){
			ES = 0;					
			for (i=0; i<6; i++){
				SBUF = table[i];
				while(!TI);			//等待第一个字符发送完
				TI = 0;				//第一个字符发送完，TI清0，在发送第二个字符
			}		
			SBUF = a;
			while(!TI);
			TI = 0;
			ES = 1;
			flag = 0;
		}
	}
}

void ser() interrupt 4
{
    RI = 0;
    a = SBUF;		//把接收到的数据送给a
    flag = 1;
}
