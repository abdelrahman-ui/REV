/*
 * many_led_by_one_button_layer_arch.c
 *
 * Created: 7/12/2020 2:03:26 PM
 * Author : User™
 */ 
#define F_CPU	16000000
#include <util/delay.h>
#include "dio.h"
#include "dio_cfg.h"

#define LED_0 1
#define LED_1 2
#define LED_2 3
#define LED_3 4


int main(void)
{
    uint8 value,count=1;
	Dio_init();
    while (1) 
    {
		DIO_Read(Dio_Channel_D0,&value);
		if(value==1)
		{
			_delay_ms(20);
			switch(count)
			{
				case LED_0:
					
					while(Dio_ReadChannel(Dio_Channel_D0)==1)
					{
						Dio_WriteChannel(Dio_Channel_A0,STD_high);
						_delay_ms(60);
					}
					Dio_WriteChannel(Dio_Channel_A0,STD_low);
					
				 count++;
				break;
				
				case LED_1:
				    while(Dio_ReadChannel(Dio_Channel_D0)==1)
				    {
					    Dio_WriteChannel(Dio_Channel_A1,STD_high);
						_delay_ms(60);
				    }
				    Dio_WriteChannel(Dio_Channel_A1,STD_low);
				    
				count++;
				break;
				
				case LED_2:
				while(Dio_ReadChannel(Dio_Channel_D0)==1)
				{
					Dio_WriteChannel(Dio_Channel_A2,STD_high);
					_delay_ms(60);
				}
				Dio_WriteChannel(Dio_Channel_A2,STD_low);
				
				count++;
				break;
				
				case LED_3:
				while(Dio_ReadChannel(Dio_Channel_D0)==1)
				{
					Dio_WriteChannel(Dio_Channel_A3,STD_high);
					_delay_ms(60);
				}
				Dio_WriteChannel(Dio_Channel_A3,STD_low);
				
				count=1;
				break;
				
			}
		}
    }
}

