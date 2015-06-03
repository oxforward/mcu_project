/************************************
*name:		MatrixKeyBoard
*function:	4×4MatrixKeyBoardKeyboard encoding rules define themselves
*			correspond to the number keys 0-9, key2_value-F, 
*			press the corresponding button to display 
*			in the digital tube display the corresponding data.
*
************************************/
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

uchar code table[]={			//Common anode LED code table
0xc0, 0xf9, 0xa4, 0xb0,
0x99, 0x92, 0x82, 0xf8,
0x80, 0x90, 0x88, 0x83,
0xc6, 0xa1, 0x86, 0x8e};


sbit S1 = P1^0;
sbit S2 = P1^1;
sbit S3 = P1^2;
sbit S4 = P1^3;

uint matrixKeyScan();
void display(uint key2_value);
void delay_on(uint delay_time);
void result();


uint key;
uint key2 = 0;
uint key3 = 0;
uint symble;

int thousand,hundred,ten, unit;
	
void main()
{
	while(1){
		display(matrixKeyScan());
	}
}



uint matrixKeyScan()
{
	/*********************************************************
	1111111111111111111111111111111111111111111111111111111111
	*********************************************************/
	uchar temp;
	P2 = 0xfe;					
	temp = P2;					
	temp &= 0xf0;				
	if(temp!=0xf0){				
		delay_on(3);			
		temp = P2;
		temp &= 0xf0;
		if(temp!=0xf0){			
			temp = P2;				
			switch(temp){
				case 0xee:	
					key = 7;
					break;
				case 0xde:
					key = 8;
					break;
				case 0xbe:
					key = 9;
					break;
				case 0x7e:
					symble = 1;
					key3 = key2;
					key2 = 0;		//除法;
					break;
				default:
					break;
			}
			while(temp!=0xf0){	
				temp = P2;
				temp &= 0xf0;
			} 
			key2 = key2 * 10 + key ;
		}
	}
	/********************************************************
	222222222222222222222222222222222222222222222222222222222
	********************************************************/
	P2 = 0xfd;					
	temp = P2;
	temp &= 0xf0;				
	if(temp!=0xf0){				
		delay_on(3);			
		temp = P2;
		temp &= 0xf0;
		if(temp!=0xf0){			
			temp = P2;			
			switch(temp){		
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
					symble = 2;
					key3 = key2;
					key2 = 0;	//乘法
					break;
				default:
					break;
			}
			while(temp!=0xf0){			
				temp = P2;
				temp &= 0xf0;
			}
			key2 = key2 * 10 + key ;
		}
	}
	/********************************************************
	333333333333333333333333333333333333333333333333333333333
	********************************************************/
	P2 = 0xfb;						
	temp = P2;
	temp &= 0xf0;				
	if(temp!=0xf0){				
		delay_on(3);			
		temp = P2;
		temp &= 0xf0;
		if(temp!=0xf0){				
			temp = P2;			
			switch(temp){			
				case 0xeb:	
					key = 1;
					break;
				case 0xdb:
					key = 2;
					break;
				case 0xbb:
					key = 3;
					break;
				case 0x7b:
					symble = 3;			//decrese
					key3 = key2;
					key2 = 0;
					break;
				default:
					break;
			}
			while(temp!=0xf0){				
				temp = P2;
				temp &= 0xf0;
			}
					
			key2 = key2 * 10 + key ;
		}
	}
	/********************************************************
	444444444444444444444444444444444444444444444444444444444
	*********************************************************/
	P2 = 0xf7;						
	temp = P2;
	temp &= 0xf0;					
	if(temp!=0xf0){					
		delay_on(3);				
		temp = P2;
		temp &= 0xf0;
		if(temp!=0xf0){				
			temp = P2;				
			switch(temp){			
				case 0xe7:	
					key2 = 0;			//on/c
					key3 = 0;
					break;
				case 0xd7:
					key = 0;			//0
					break;
				case 0xb7:
					result();			//等号
					
					break;
				case 0x77:
					symble = 4;
					key3 = key2;
					key2 = 0;					//加法						
					break;
				default:
					break;
			}
			while(temp!=0xf0){				
				temp = P2;
				temp &= 0xf0;
			}
			//display(key);	
			if(key == 0){
				key2 = key2 * 10 + key;
			}
			
		}
	}
	return (key2);
}


void result()
{
	switch(symble){
		case 1:
			key2 = key3 / key2;
			break;
		case 2:
			key2 = key3 * key2;
			break;
		case 3:
			key2 = key3  - key2;
			break;
		case 4:
			key2 = key3 + key2;
			break;
		default:
			break;
		
			
	}
}


void delay_on(uint delay_time)
{
	uint i;
	uint j;
	for(i=0;i<=delay_time;i++)
		for(j=0;j<=delay_time;j++);
}

void display(uint key2_value)
{
	unsigned int thousand = 0, hundred = 0, ten = 0, unit = 0;
	thousand=key2_value / 1000;
	hundred=(key2_value % 1000) / 100;
	ten=((key2_value % 1000) % 100) / 10;
	unit=((key2_value % 1000) % 100) % 10;
		
	  
	S1=1;
	S2=1;
	S3=1;
	S4=1;
	P0=table[unit];
	S4=0;
	delay_on(5);
	
	if(key2_value>= 10){
		S4=1;
		P0=table[ten];
		S3=0;
		delay_on(5);
	  }
	if(key2_value>= 100){
		S3=1;
		P0=table[hundred];
		S2=0;
		delay_on(5);
	  }
	if(key2_value>= 1000){	
		S2=1;
		P0=table[thousand];
		S1=0;
		delay_on(5);
	}
		
}

