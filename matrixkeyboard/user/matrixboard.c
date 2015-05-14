#include<reg52.h>
#include"delay_on.h"

sbit seg_lock=P3^7;			//����ܶ�ѡ����

uchar code bit_select[8] = {0,1,2,3,4,5,6,7};		//��P2��λѡ
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
	P1 = 0xfe;						//����һ�е͵�ƽ
	temp = P1;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//�жϸ���λ������0�����������Ƿ��а������£�
		delay_on(5);				//��������
		temp = P1;
		temp &= 0xf0;
		if(temp!=0xf0){				//ȷ����������
			temp = P1;				//�а�������
			switch(temp){			//ȷ��������������һ��
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
			while(temp!=0xf0){				//�ȴ������ͷ�
				temp = P1;
				temp &= 0xf0;
			}
			display(key);		//��ʾ�������Ӧ����ֵ
		}
	}

	P1 = 0xfd;						//���ڶ��е͵�ƽ
	temp = P1;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//�жϸ���λ������0�����������Ƿ��а������£�
		delay_on(5);				//��������
		temp = P1;
		temp &= 0xf0;
		if(temp!=0xf0){				//ȷ����������
			temp = P1;				//�а�������
			switch(temp){			//ȷ��������������һ��
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
			while(temp!=0xf0){				//�ȴ������ͷ�
				temp = P1;
				temp &= 0xf0;
			}
			display(key);		//��ʾ�������Ӧ����ֵ
		}
	}

	P1 = 0xfb;						//�������е͵�ƽ
	temp = P1;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//�жϸ���λ������0�����������Ƿ��а������£�
		delay_on(5);				//��������
		temp = P1;
		temp &= 0xf0;
		if(temp!=0xf0){				//ȷ����������
			temp = P1;				//�а�������
			switch(temp){			//ȷ��������������һ��
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
			while(temp!=0xf0){				//�ȴ������ͷ�
				temp = P1;
				temp &= 0xf0;
			}
			display(key);		//��ʾ�������Ӧ����ֵ
		}
	}

	P1 = 0xf7;						//�������е͵�ƽ
	temp = P1;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//�жϸ���λ������0�����������Ƿ��а������£�
		delay_on(5);				//��������
		temp = P1;
		temp &= 0xf0;
		if(temp!=0xf0){				//ȷ����������
			temp = P1;				//�а�������
			switch(temp){			//ȷ��������������һ��
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
			while(temp!=0xf0){				//�ȴ������ͷ�
				temp = P1;
				temp &= 0xf0;
			}
			display(key);		//��ʾ�������Ӧ����ֵ
		}
	}
}

void main()
{
	
	P0 = 0;
	seg_lock = 1;
	seg_lock = 0;
	P2 = bit_select[0];				//ѡ�е�һ�������
	while(1){
		matrixkeyscan();
	}
}


