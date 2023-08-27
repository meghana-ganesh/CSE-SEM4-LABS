#include<LPC17xx.h>
unsigned int dig_count = 0x00;
unsigned int seven_seg[10] = {0x3F,0x06,0x5B,0x4F,0x66,0X6D,0x7D,0x07,0x7F,0x6F};
unsigned int dig_values[4] = {1,2,3,4};
unsigned int dig_select[4] = {3<<23,2<<23,1<<23,0<<23};
unsigned int i;

void display();


void display()
{
	LPC_GPIO1->FIOPIN = dig_select[dig_count];
	LPC_GPIO0->FIOPIN = seven_seg[dig_values[dig_count]] << 4;
}
	

int main()
{
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	LPC_GPIO1->FIODIR |= 0x07800000;
	
	while(1)
	{
		 
		for(i=0;i<100000;i++);
		display();
		dig_count +=1 ;
		if(dig_count == 0x04)
			dig_count = 0x00;
	}
}
