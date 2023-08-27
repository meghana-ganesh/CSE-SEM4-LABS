#include <LPC17xx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lcdfn.h"
#define Ref_Vtg  3.3
#define Full_Scale 0xFFF
 
unsigned char str[]={"0123456789"};
unsigned long x,temp;
unsigned int channel,result1,result2,i,j, flag1;
unsigned char dval1[10],dval2[10];
unsigned char Msg3[11] = {"VALUE1:"};
unsigned char Msg4[12] = {"VALUE2:"};
unsigned int temp1;
float t1,t2;
void ADC_IRQHandler(void)
{
    x=LPC_ADC->ADSTAT&(3<<4);
    if(x>>4 &1) 
    {
        t1 = (LPC_ADC->ADDR4>>4)&0xFFF;
    } 
    if(x>>5 &1)
    {
        t2 = (LPC_ADC->ADDR5>>4)&0XFFF;
    }
    t1 = ((t1 * (float)Ref_Vtg))/((float)Full_Scale);
    t2 = ((t2 * (float)Ref_Vtg))/((float)Full_Scale);
    sprintf(dval1,"%3.2f",t1);
    sprintf(dval2,"%3.2f",t2);
    temp1 = 0x89;
    lcd_comdata(temp1,0);
    delay_lcd(800);
    lcd_puts(&dval1[0]);
    temp1 = 0xc8;
    lcd_comdata(temp1,0);
    delay_lcd(800);
    lcd_puts(&dval2[0]);
}
 
int main(void)
{
 
    lcd_init();
    LPC_PINCON->PINSEL3=(0xF)<<28; //P1.31 as AD0.5
    LPC_SC->PCONP |=(1<<12);
    lcd_comdata(0x80,0);
    delay_lcd(800);
    lcd_puts(&Msg3[0]);
    lcd_comdata(0xC0,0);
    delay_lcd(800);
    lcd_puts(&Msg4[0]);
    LPC_ADC->ADCR = (1 << 4 | 1 << 5 | 1 << 16 | 1 << 21);
    LPC_ADC->ADINTEN = (1<<4|1<<5);
    flag1 = 1;
    NVIC_EnableIRQ(ADC_IRQn);
    while(1);
}