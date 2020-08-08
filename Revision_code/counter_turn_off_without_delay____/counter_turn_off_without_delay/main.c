/*
 * counter_turn_off_without_delay.c
 *
 * Created: 4/17/2020 3:19:07 AM
 * Author : User™
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#define GIT_BIT(var,bit) ((var>>bit)&1)
#define CLEAR_BIT(var,bit) var&=~(1<<bit)
int main(void)
{
	// Make the output direction ready
	DDRC=0xfc; //0b 1111 1100

	// The diriction of button
	CLEAR_BIT(DDRD,0);
	/* Replace with your application code */
	while (1)
	{
		static char count=0;
		if(GIT_BIT(PIND,1)==1)
		{
			_delay_ms(30);
			switch(count)
			{
				case 0:
				PORTC=0x0c;
				_delay_ms(1000);
				PORTC=0x00;
				break;
				
				case 1:
				PORTC=0x1c;
				_delay_ms(1000);
				PORTC=0x00;
				break;
				case 2:
				PORTC|=0x2c;
				_delay_ms(1000);
				PORTC=0x00;
				break;
				case 3:
				PORTC|=0x3c;
				_delay_ms(1000);
				PORTC=0x00;
				break;
				case 4:
				PORTC|=0x4c;
				_delay_ms(1000);
				PORTC=0x00;
				break;
				case 5:
				PORTC|=0x5c;
				_delay_ms(1000);
				PORTC=0x00;
				break;
				case 6:
				PORTC|=0x6c;
				_delay_ms(1000);
				PORTC=0x00;
				break;
				case 7:
				PORTC|=0x7c;
				_delay_ms(1000);
				PORTC=0x00;
				break;
				case 8:
				PORTC|=0x8c;
				_delay_ms(1000);
				PORTC=0x00;
				break;
				case 9:
				PORTC|=0x9c;
				_delay_ms(1000);
				PORTC=0x00;
				count =-1;
				break;
				
			}
			count++;
			

		}
		while((PIND&0x01)==0x00)// lma b700t da w 24el el delay 
		{
			
		}
	}
}

