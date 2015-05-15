/************************************
*matrixkeyboard
************************************/
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

uchar code table[]={			//Common anode LED code table
0xc0, 0xf9, 0xa4, 0xb0,
0x99, 0x92, 0x82, 0xf8,
0x80, 0x90, 0x88, 0x83,
0xc6, 0xa1, 0x86, 0x8e};

sbit sw = P3^7;

void matrixKeyScan();
void display(uchar key);
void delay_on(uint delay_time);

void main()
{
	sw = 1;
	while(1){
		matrixKeyScan();
	}
}

void display(uchar key)
{
//	P0 = 0xff;
//	delay_on(3);
	P0 = table[key];
}

void matrixKeyScan()
{
	uchar temp, key;
	P2 = 0xfe;						//����һ�е͵�ƽ
	temp = P2;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//�жϸ���λ������0�����������Ƿ��а������£�
		delay_on(3);				//��������
		temp = P2;
		temp &= 0xf0;
		if(temp!=0xf0){				//ȷ����������
			temp = P2;				//�а�������
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
				temp = P2;
				temp &= 0xf0;
			}
			display(key);		//��ʾ�������Ӧ����ֵ
		}
	}

	P2 = 0xfd;						//���ڶ��е͵�ƽ
	temp = P2;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//�жϸ���λ������0�����������Ƿ��а������£�
		delay_on(3);				//��������
		temp = P2;
		temp &= 0xf0;
		if(temp!=0xf0){				//ȷ����������
			temp = P2;				//�а�������
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
				temp = P2;
				temp &= 0xf0;
			}
			display(key);		//��ʾ�������Ӧ����ֵ
		}
	}

	P2 = 0xfb;						//�������е͵�ƽ
	temp = P2;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//�жϸ���λ������0�����������Ƿ��а������£�
		delay_on(3);				//��������
		temp = P2;
		temp &= 0xf0;
		if(temp!=0xf0){				//ȷ����������
			temp = P2;				//�а�������
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
				temp = P2;
				temp &= 0xf0;
			}
			display(key);		//��ʾ�������Ӧ����ֵ
		}
	}

	P2 = 0xf7;						//�������е͵�ƽ
	temp = P2;
	temp &= 0xf0;					//
	if(temp!=0xf0){					//�жϸ���λ������0�����������Ƿ��а������£�
		delay_on(3);				//��������
		temp = P2;
		temp &= 0xf0;
		if(temp!=0xf0){				//ȷ����������
			temp = P2;				//�а�������
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
				temp = P2;
				temp &= 0xf0;
			}
			display(key);		//��ʾ�������Ӧ����ֵ
		}
	}
}

void delay_on(uint delay_time)
{
	uint i;
	uint j;
	for(i=0;i<=delay_time;i++)
		for(j=0;j<=delay_time;j++);
}
