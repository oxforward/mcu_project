#include<reg52.h>
#include<intrins.h>
#include "boardinit.h"

#define uchar unsigned char
#define uint  unsigned int
void boardinit();
sbit E=P2^4;		//1602ʹ������
sbit RW=P2^6;		//1602��д����	
sbit RS=P2^5;		//1602����/����ѡ������ 

void delay()
{
	int i,j;
	for(i=0; i<=10; i++)
	for(j=0; j<=2; j++)
;
}



void enable(uchar del)
{
	P0 = del;
	RS = 0;
	RW = 0;
	E = 0;
	delay();
	E = 1;
	delay();
}



void L1602_init(void)
{

	enable(0x38);	//0011 1000	ϵͳ�������ã����ݳ���8bits,˫����ʾ   
	enable(0x0c);	//0000 1100	��ʾ���ؿ���:��ʾ����겻��ʾ����ֹ��˸  
	enable(0x06);	//0000 0110	ģʽ����:�������,��ֹ���� 
	enable(0x01);	//0000 0001	����
	//enable(0xc0);	//1100 0000	��ʼ��ʾ���ݵ�λ��Ϊ:000
}


void write(uchar del)
{
	P0 = del;
	RS = 1;
	RW = 0;
	E = 0;
	delay();
	E = 1;
	delay();
}



void L1602_char(uchar hang,uchar lie,char sign)
{
	uchar a;
	if(hang == 1) a = 0x80;
	if(hang == 2) a = 0xc0;
	a = a + lie - 1;
	enable(a);
	delay();
	write(sign);
}


void main()
{
	char al = '!' - 1;
	int i;
	boardinit();	

	L1602_init();
	L1602_char(1,1,al);
	for(i = 0 ; i <= 16; i++, al++){
		L1602_char(1,i,al);
	}
	for(i = 0 ; i <= 16; i++, al++){
		L1602_char(2,i,al);
	}
	while(1);
}
