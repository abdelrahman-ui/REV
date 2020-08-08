/*
 * GccApplication1.c
 *
 * Created: 4/17/2020 2:30:52 AM
 * Author : User™
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


unsigned char Lut[]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b11111011};//m4 3aref 2zobot m3 el keet
	
int main(void)
{
	char i=0;
	DDRA=0xff;// 7leha out 
	PORTA=Lut[0];//23red f el 2wel 0
	DDRB=0xff;// 7leha out
	PORTB=Lut[0];//23red f el 2wel 0
    // f3al el input resrstanse 2w pull up inside
	DDRC=0x00;
	PORTC=0x01;
    while (1) 
    {  i++;
		if((PORTC&0x01)==0x01)
		i=0;
		PORTA=Lut[i%10];//23red el a7aaaad
		PORTB=Lut[i/10];//23red el 34raaaat
		while((PINC&0x01)==0x00)//22fel 2wel ma 2seeeb
		{
			
		}
    }
}

