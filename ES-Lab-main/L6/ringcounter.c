#include<LPC17xx.h>
unsigned int i,j,c=1;
int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;
	LPC_GPIO2->FIODIR |= 0xFFFFEFFF;
	while(1)
	{
		if(!(LPC_GPIO2->FIODIR & 1<<12)) //pressed
		{
			for(i=0;i<8;i++)
			{
				LPC_GPIO0->FIOPIN = c << 4;
				for(j=0;j<100000;j++);
				c = c << 1;
			}
			c = 1;
		}
	}
	
}