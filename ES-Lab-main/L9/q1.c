
#include<LPC17xx.h>
#define Ref_Vtg 3.3000
#define Full_Scale 4096
unsigned long x, temp, t1 = 0, t2 = 0;
unsigned int channel, result, i, temp1, j;
unsigned char Msg1[15] ={"ADC Value"};
#include "lcdfn.h"




int main(void){
    unsigned long adc_temp;
    unsigned int i;
    float in_vtg;
    unsigned char vtg[7], dval[7];
    unsigned char Msg3[11] = {"ANALOG:"};
    unsigned char Msg4[12] = {"ADC:"};
    SystemInit();
    SystemCoreClockUpdate();
    LPC_SC->PCONP |= (1<<15); //Power for GPIO block
    lcd_init();
    LPC_PINCON->PINSEL3 |= 0xC0000000; //P1.31 as AD0.5
    LPC_SC->PCONP |= (1<<12); //enable the peripheral ADC
    SystemCoreClockUpdate();
    lcd_comdata(0x80, 0);
    delay_lcd(800);
    lcd_puts(&Msg3[0]);
    lcd_comdata(0xC0, 0);
    delay_lcd(800);
    lcd_puts(&Msg4[0]);
    while(1){
        LPC_ADC->ADCR = (1<<5)|(1<<21)|(1<<24); 
        while(!(LPC_ADC->ADGDR >>31 & 1)); //waiting till done bit = 1
         
        adc_temp = LPC_ADC->ADDR5;
        adc_temp >>= 4; //extracting result
        adc_temp &= 0x00000FFF; 
        in_vtg = (((float)adc_temp * (float)Ref_Vtg))/((float)Full_Scale);
        //calculating input analog voltage
        sprintf(vtg, "%3.2fV", in_vtg);
        //convert the readings into string to display on LCD
        sprintf(dval, "%x", adc_temp);
        for(i=0; i<2000; i++);
        lcd_comdata(0x89, 0);
        delay_lcd(800);
        lcd_puts(&vtg[0]);
        lcd_comdata(0xC8, 0);
        delay_lcd(800);
        lcd_puts(&dval[0]);
        for(i=0;i<200000;i++);
        for(i=0;i<7;i++)
            vtg[i] = dval[i] = 0x00;
        adc_temp = 0;
        in_vtg = 0;
    }
}


