#include<LPC17xx.h>
unsigned int seven_seg[16] = {0x3F,0x06,0x5B,0x4F,0x66,0X6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned int arr[4] = {0xF,0xF,0xF,0xF};
unsigned int arr1[4] = {0,0,0,0};
unsigned int dig_select[4] = {0<<23,1<<23,2<<23,3<<23};
unsigned int i,j;

int main()
{
	LPC_GPIO0->FIODIR |= 0xFF0;
	LPC_GPIO1->FIODIR |= 0xF<<23;
	while(1)
	{
		if(!(LPC_GPIO2->FIOPIN & 1)) //pressed-down count
		{
		for(arr[3] = 0xF;arr[3] != -1;arr[3]--)
			{
			for(arr[2] = 0xF;arr[2] != -1;arr[2]--)
				{
				for(arr[1] = 0xF;arr[1] != -1;arr[1]--)
					{
					for(arr[0] = 0xF;arr[0] != -1;arr[0]--)
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
		
		if(LPC_GPIO2->FIOPIN & 1) //not pressed- up count
		{
		for(arr1[3] = 0;arr1[3] <= 0xF;arr1[3]++)
			{
			for(arr1[2] = 0;arr1[2] <= 0xF;arr1[2]++)
				{
				for(arr1[1] = 0;arr1[1] <= 0xF;arr1[1]++)
					{
					for(arr1[0] = 0;arr1[0] <= 0xF;arr1[0]++)
						{
							for(i=0;i<4;i++)
							{
								LPC_GPIO1->FIOPIN = dig_select[i];
								LPC_GPIO0->FIOPIN = seven_seg[arr1[i]] << 4;
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
}