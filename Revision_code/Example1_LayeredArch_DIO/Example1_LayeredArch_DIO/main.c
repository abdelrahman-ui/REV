/*
 * Example1_LayeredArch_DIO.c
 *
 * Created: 6/12/2020:57:24 PM
 * Author : abdelrahman_magdy
 */ 
#define F_CPU	16000000
#include <util/delay.h>
#include "dio.h"
#include "dio_cfg.h"
int check=0;
int main(void)	
{		uint8 value;
	Dio_init();
    while (1) 
    {
		DIO_Read(Dio_Channel_D0,&value);
		if (value==1)
		{
			while(1)
			{
		_delay_ms(10);
		 Dio_WriteChannel(Dio_Channel_A1,STD_high);
		_delay_ms(50);
		Dio_WriteChannel(Dio_Channel_A1,STD_low);
		_delay_ms(50);
			}
		}
    }
}

