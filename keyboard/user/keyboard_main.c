#include<reg52.h>
#include"delay_on.h"

sbit seg_lock = P3^7;

sbit key17 = P3^4;
sbit key18 = P3^3;
sbit key19 = P3^2;

uchar code bit_select[8] = {0,1,2,3,4,5,6,7};
uchar code seg_table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

uchar num, num_t0;

void display(uchar displayNum)
{
	uint shi, ge;
	shi = displayNum / 10;
	ge = displayNum % 10;

	seg_lock = 1;			//送十位
	P0 = seg_table[shi];	//段选
	seg_lock = 0;  			//数据入74CH573
	P0 = 0x00;				//送位选信号前关闭所有显示，避免打开位选时原来数据
	P2 = bit_select[0];
	delay_on(1);

   	seg_lock = 1;
	P0 = seg_table[ge];		//送个位
	seg_lock = 0;
	P0 = 0x00;
	P2 = bit_select[1];
	delay_on(1);
}

void init()
{
	TMOD = 0x01;					//设置定时器0的工作方式1
	TH0 = (65536-45872)	/ 256;
	TL0 = (65536-45872) % 256;
	EA = 1;							//开中断总开关				
	ET0 = 1;						//开定时器0开关
}

void keyscan()
{
	if(key17==0){					//key17对应P3.4
		delay_on(1);
		if(key17==0){
			while(!key17);			//等待按键释放
			TR0 = ~TR0;				//启动或者停止定时器0
		}
	}

	if(key18==0){					//key18对应P3.3
		delay_on(1);
		if(key18==0){
				num = 0;			
			while(!key18);
		}
	}

	if(key19==0){					//key19对应P3.2
		delay_on(10);
		if(key19==0){
			num++;
			if(num==60){	
				num = 0;		
			}
			while(!key19);
		}
	}
}


void main()
{
	init();
	while(1){
		keyscan();
		display(num);
	}
}

void T0_timer() interrupt 1
{
	TH0 = (65536-45872)	/ 256;		//重装初值
	TL0 = (65536-45872) % 256;
	num_t0++;
	if(num_t0==20){
		num_t0 = 0;
		num++;
		if(num==60){
			num = 0;
		}
	}
}