#include<LPC17xx.h>
unsigned int j;
unsigned long LED;
int main()
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	while(1)
	{
			for(LED = 0;LED<255;LED++)
			{
				LPC_GPIO0->FIOPIN = LED<<4;
				for(j=0;j<100000;j++);
			}
	}
}