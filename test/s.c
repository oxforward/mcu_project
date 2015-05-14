#include<reg52.h>

sbit led7=P0^7;
void main()
{
	while(1){
		led7=1;
	}		
}