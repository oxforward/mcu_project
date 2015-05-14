#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int
uchar flag, a, i;
uchar code table[]="I get " ;

void init()
{
	TMOD = 0x20;	//�趨T1��ʱ��������ʽ2
	TH1 = 0xfd;		//TI��ʱ��װ��ֵ
	TL1 = 0xfd;		//TI��ʱ��װ��ֵ����λSMODΪ0�����Դ�ʱ������Ϊ9600
	TR1 = 1;		//����TI��ʱ��
	REN = 1;		//�����ڽ���
	SM0 = 1;	   	//
	SM1 =1;		   	//SM0 SM1�趨���ڹ�����ʽ1
	EA = 1;			//�����ж�
	ES = 1;		   	//�������ж�
}
void main()
{
	init();					//��ʼ��
	while (1) {
		if(flag==1){
			ES = 0;					
			for (i=0; i<6; i++){
				SBUF = table[i];
				while(!TI);			//�ȴ���һ���ַ�������
				TI = 0;				//��һ���ַ������꣬TI��0���ڷ��͵ڶ����ַ�
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
    a = SBUF;		//�ѽ��յ��������͸�a
    flag = 1;
}
