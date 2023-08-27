#include<LPC17xx.h>
unsigned j;
unsigned long LED;
int main() 
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;
	LPC_GPIO2->FIODIR |= 0xFFFFEFFF;
	while(1)
	{
	if(LPC_GPIO2->FIOPIN & 1<<12) //up counter if switch not pressed(sw=1)
	{
		for(LED=0;LED<255;LED++)
		{
			LPC_GPIO0->FIOPIN = LED<<4;
			for(j = 0;j<100000;j++);
		}
	}
	else //down counter if switch pressed(sw=0)
	{
		for(LED=255;LED>0;LED--)
		{
			LPC_GPIO0->FIOPIN = LED<<4;
			for(j = 0;j<100000;j++);
		}
	}
	}

}