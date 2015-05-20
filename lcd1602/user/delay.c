#include "delay.h"

void delay(uint z)
{
	uint x,y;
    for(x=z;x>0;x--)
      for(y=114;y>0;y--);   
}

void delay_ds18b20(uint time)
{
     uint  i,j;
	 for(i=0;i<time;i++)
		for(j=0;j<1;j++);
}