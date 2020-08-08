/*
 * ADC_LCD.c
 *
 * Created: 7/16/2020 3:01:03 PM
 * Author : User™
 */ 

#include "ADC.h"
#include <util/delay.h>			/* Include Delay header file */
#define  Led_0 5
#define  Led_1 6
#define  Led_2 7
#include "bit_math.h"
#include <avr/io.h>		
int main(void)
{
    LCD_Init();
	ADC_Init();
	DDRD|=(1<<Led_1)|(1<<Led_2)|(1<<Led_0);
    while (1) 
    {
		
		LCD_Clear();
		LCD_Command(0x80);
		LCD_String("Sensor 1 = ");
		unsigned char data =ADC_Read(1);
		_delay_ms(2000);
		/*LCD_Command(0xc0);
		LCD_String("Sensor 2 = ");
		ADC_Read_2(0);*/
		if(data<=10)
		{
			
			SET_BIT(PORTD,Led_0);
			_delay_ms(20000);
			CLR_BIT(PORTD,Led_0);
			
		}
		else if((data>=10)&&(data<=499))
		{
			
			SET_BIT(PORTD,Led_1);
			_delay_ms(20000);
			CLR_BIT(PORTD,Led_1);
		}
		else if(data>=500)
		{
			
			SET_BIT(PORTD,Led_2);
			_delay_ms(20000);
			CLR_BIT(PORTD,Led_2);
		}
		
		
	

    }

}

//mo4klaa lma b2raa kazaaa sensor bye2raa wa7ed bs 