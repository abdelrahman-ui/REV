/*
 * ADC_2.c
 *
 * Created: 7/19/2020 1:33:32 AM
 * Author : User™
 */ 

#include <avr/io.h>
#include "lcd.h"
 

#define ADC_VREF_Type 0x20
unsigned char read_adc(unsigned char adc_input)
{
	ADMUX=adc_input|(ADC_VREF_Type & 0XFF);
	_delay_us(10);
	ADCSRA|=0x40;
	while((ADCSRA&0x10)==0);
	ADCSRA|=0x10; //FLAG =1
	return ADCH; 
	
}
int main(void)
{
    float x;
	char str[4];
	ADMUX=ADC_VREF_Type & 0XFF ;
	ADCSRA=0X81;
	LCD_Init();
	 
    while (1) 
    {
		LCD_Clear();
		X=read_adc(0X00);
	   X=X*5/255;//me4
	   itoa(x,2,str);
	   LCD_String("c1 :");
	   LCD_String(str);
		 		
    }
}

