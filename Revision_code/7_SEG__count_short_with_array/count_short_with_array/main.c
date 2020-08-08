/*
 * count_short_with_array.c
 *
 * Created: 4/17/2020 3:39:52 AM
 * Author : User™
 */ 


#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#define GIT_BIT(var,bit) ((var>>bit)&1)
#define CLEAR_BIT(var,bit) var&=~(1<<bit)
unsigned char Lut []={0x0c,0x1c,0x2c,0x3c,0x4c,0x5c,0x6c,0x7c,0x8c,0x9c};

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
			PORTC=Lut[count];
			
			count++;
			
		}
		else if (count==10)
		{
			count=0;
		}
		
	}
}


