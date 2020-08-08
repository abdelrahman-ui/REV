/*
 * ADC.c
 *
 * Created: 7/16/2020 3:22:46 PM
 *  Author: User™
 */ 
#include "ADC.h"
#include "lcd.h"
void ADC_Init(){
	//select A1 as input
	DDRA &=~(1<<1);
	//select A0 as input
	DDRA &=~(0<<1);
	//ADC1 as input | Internal reference
	ADMUX=(1<<REFS1)|(1<<REFS0); //00001=ADC1 |reference 1100 =C
	ADCSRA=(1<<ADATE)|(1<<ADPS0)|(ADPS1)|(ADPS2)|(1<<ADEN);
	
}
unsigned int ADC_Read_2(unsigned channel){
	short data =0;
	char string[100];
	ADMUX |=(channel&0x1f);
	//start conversion
	ADCSRA|=(1<<ADSC);
	
	//check flag -
	while(!(ADCSRA&(1<<ADIF))); //infinite loop --POLLING 100%
	//clear flag
	ADCSRA|=(1<<ADIF);
	//ADCL
	data = ADCL;
	//ADCH
	data|=ADCH<<8;
	/*//temp equation
	data = data / 4 ;
	data = data - 55 ;
	*/
	itoa(data,string,10);
	LCD_String(string);
	return data;
}
unsigned int ADC_Read(unsigned channel){
	short data =0;
	char string[100];
	ADMUX |=(channel&0x1f);
	//start conversion
	ADCSRA|=(1<<ADSC);
	
	//check flag -
	while(!(ADCSRA&(1<<ADIF))); //infinite loop --POLLING 100%
	//clear flag
	ADCSRA|=(1<<ADIF);
	//ADCL
	data = ADCL;
	//ADCH
	data|=ADCH<<8;
	/*//temp equation
	data = data / 4 ;
	data = data - 55 ;
	*/
	itoa(data,string,10);
	LCD_String(string);
	return data;
}