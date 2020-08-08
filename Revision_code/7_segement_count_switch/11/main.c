/*
 * 7_segement.c
 *
 * Created: 4/15/2020 2:06:26 AM
 * Author : Userâ„¢
 */ 
#define F_CPU 16000000
#include <avr/io.h>

#include <util/delay.h>
int main(void)
{
	// Make the output direction ready
	DDRC=0xfc; //0b 1111 1100

    while (1) 
    {
	 static char count =0;//s0000000o important static
		
		switch(count)
		{
		case 0:
			PORTC=0x0c;
			_delay_ms(1000);
			PORTC=0x00;
			
		count++;
			break;
			
		case 1:
			PORTC=0x1c;
			_delay_ms(1000);
			PORTC=0x00;
			count =2;
			break;
			_delay_ms(2000);
		case 2:
			PORTC|=0x2c;
			_delay_ms(1000);
			PORTC=0x00;
			count =3;
			break;
		case 3:
			PORTC|=0x3c;
			_delay_ms(1000);
			PORTC=0x00;
			count =4;
			break;
		case 4:
			PORTC|=0x4c;
			_delay_ms(1000);
			PORTC=0x00;
	        count =5;
			break;
		case 5:
			PORTC|=0x5c;
			_delay_ms(1000);
			PORTC=0x00;
		    count =6;
			break;
		case 6:
			PORTC|=0x6c;
			_delay_ms(1000);
			PORTC=0x00;
			count =7;
			break;
		case 7:
			PORTC|=0x7c;
			_delay_ms(1000);
			PORTC=0x00;
			count =8;
			break;
		case 8:
			PORTC|=0x8c;
			_delay_ms(1000);
			PORTC=0x00;
			count =9;
			break;
		case 9:
			PORTC|=0x9c;
			_delay_ms(1000);
			PORTC=0x00;
			count =0;
			break;
			
		}
		
    }
}

