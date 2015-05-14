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

	seg_lock = 1;			//��ʮλ
	P0 = seg_table[shi];	//��ѡ
	seg_lock = 0;  			//������74CH573
	P0 = 0x00;				//��λѡ�ź�ǰ�ر�������ʾ�������λѡʱԭ������
	P2 = bit_select[0];
	delay_on(1);

   	seg_lock = 1;
	P0 = seg_table[ge];		//�͸�λ
	seg_lock = 0;
	P0 = 0x00;
	P2 = bit_select[1];
	delay_on(1);
}

void init()
{
	TMOD = 0x01;					//���ö�ʱ��0�Ĺ�����ʽ1
	TH0 = (65536-45872)	/ 256;
	TL0 = (65536-45872) % 256;
	EA = 1;							//���ж��ܿ���				
	ET0 = 1;						//����ʱ��0����
}

void keyscan()
{
	if(key17==0){					//key17��ӦP3.4
		delay_on(1);
		if(key17==0){
			while(!key17);			//�ȴ������ͷ�
			TR0 = ~TR0;				//��������ֹͣ��ʱ��0
		}
	}

	if(key18==0){					//key18��ӦP3.3
		delay_on(1);
		if(key18==0){
				num = 0;			
			while(!key18);
		}
	}

	if(key19==0){					//key19��ӦP3.2
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
	TH0 = (65536-45872)	/ 256;		//��װ��ֵ
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