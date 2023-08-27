#include<LPC17xx.h>
unsigned int seven_seg[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int arr[4] = {9,9,9,9};
unsigned int dig_select[4] = {0<<23,1<<23,2<<23,3<<23};
unsigned int i,j;

int main()
{
	LPC_GPIO0->FIODIR |= 0xFF0;
	LPC_GPIO1->FIODIR |= 0xF<<23;
	while(1)
	{
		for(arr[3] = 9;arr[3] != -1;arr[3]--)
			{
			for(arr[2] = 9;arr[2] != -1;arr[2]--)
				{
				for(arr[1] = 9;arr[1] != -1;arr[1]--)
					{
					for(arr[0] = 9;arr[0] != -1;arr[0]--)
						{
							for(i=0;i<4;i++)
							{
								LPC_GPIO1->FIOPIN = dig_select[i];
								LPC_GPIO0->FIOPIN = seven_seg[arr[i]] << 4;
								for(j=0;j<1000;j++);
							}
							for(j=0;j<1000;j++);
							LPC_GPIO0->FIOCLR |= 0x00000FF0;
						}
					}
				}
			}
							
	}
}