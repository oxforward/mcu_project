
#include "delay_on.h"

void delay_on(uint delay_time)
{
	uint i;
	uint j;
	for(i=delay_time;i>0;i--)	//i=delay_time����ʱdelay_time����
		for(j=110;j>0;j--);
}