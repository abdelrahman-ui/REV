/*
 * LCD_layer.c
 *
 * Created: 7/14/2020 2:08:31 PM
 * Author : Abdelrahman_Magdy™
 */ 
#include "LCD.h"
char heart[8] = {
	0b00000,
	0b01010,
	0b11111,
	0b11111,
	0b11111,
	0b01110,
	0b00100,
	0b00000
};
char smileyFace[8] = {
	0x00,//0B00000
	0x00,
	0x0A,
	0x00,
	0x11,
	0x0E,
	0x00,
	0x00
};
int main(void)
{
	int i=0;
	Dio_init();
	LCD_Init();
	LCD_Char('m');
	LCD_Custom_Char(0,smileyFace); //
	

	 
    while (1) 
    {
    }
}

