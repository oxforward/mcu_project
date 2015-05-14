#include<reg52.h>
#include"delay_on.h"

sbit seg_lock=P3^7;			//数码管段选开关

uchar code bit_select[8] = {0,1,2,3,4,5,6,7};		//送P2口位选
uchar code seg_table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

void display(uchar key)
{
	P0 = seg_table[key];
	seg_lock = 1;
	seg_lock = 0;
}

void matrixkeyscan()
{
	uchar temp, key;
	P1 = 0xfe;						//给第一行低电平
	temp = P1;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//判断高四位死否有0（列数）（是否有按键按下）
		delay_on(5);				//消除抖动
		temp = P1;
		temp &= 0xf0;
		if(temp!=0xf0){				//确定按键按下
			temp = P1;				//有按键按下
			switch(temp){			//确定按键具体是哪一个
				case 0xee:	
					key = 0;
					break;
				case 0xde:
					key = 1;
					break;
				case 0xbe:
					key = 2;
					break;
				case 0x7e:
					key = 3;
					break;
			}
			while(temp!=0xf0){				//等待按键释放
				temp = P1;
				temp &= 0xf0;
			}
			display(key);		//显示按键多对应懂得值
		}
	}

	P1 = 0xfd;						//给第二行低电平
	temp = P1;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//判断高四位死否有0（列数）（是否有按键按下）
		delay_on(5);				//消除抖动
		temp = P1;
		temp &= 0xf0;
		if(temp!=0xf0){				//确定按键按下
			temp = P1;				//有按键按下
			switch(temp){			//确定按键具体是哪一个
				case 0xed:	
					key = 4;
					break;
				case 0xdd:
					key = 5;
					break;
				case 0xbd:
					key = 6;
					break;
				case 0x7d:
					key = 7;
					break;
			}
			while(temp!=0xf0){				//等待按键释放
				temp = P1;
				temp &= 0xf0;
			}
			display(key);		//显示按键多对应懂得值
		}
	}

	P1 = 0xfb;						//给第三行低电平
	temp = P1;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//判断高四位死否有0（列数）（是否有按键按下）
		delay_on(5);				//消除抖动
		temp = P1;
		temp &= 0xf0;
		if(temp!=0xf0){				//确定按键按下
			temp = P1;				//有按键按下
			switch(temp){			//确定按键具体是哪一个
				case 0xeb:	
					key = 8;
					break;
				case 0xdb:
					key = 9;
					break;
				case 0xbb:
					key = 10;
					break;
				case 0x7b:
					key = 11;
					break;
			}
			while(temp!=0xf0){				//等待按键释放
				temp = P1;
				temp &= 0xf0;
			}
			display(key);		//显示按键多对应懂得值
		}
	}

	P1 = 0xf7;						//给第四行低电平
	temp = P1;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//判断高四位死否有0（列数）（是否有按键按下）
		delay_on(5);				//消除抖动
		temp = P1;
		temp &= 0xf0;
		if(temp!=0xf0){				//确定按键按下
			temp = P1;				//有按键按下
			switch(temp){			//确定按键具体是哪一个
				case 0xe7:	
					key = 12;
					break;
				case 0xd7:
					key = 13;
					break;
				case 0xb7:
					key = 14;
					break;
				case 0x77:
					key = 15;
					break;
			}
			while(temp!=0xf0){				//等待按键释放
				temp = P1;
				temp &= 0xf0;
			}
			display(key);		//显示按键多对应懂得值
		}
	}
}

void main()
{
	
	P0 = 0;
	seg_lock = 1;
	seg_lock = 0;
	P2 = bit_select[0];				//选中第一个数码管
	while(1){
		matrixkeyscan();
	}
}


