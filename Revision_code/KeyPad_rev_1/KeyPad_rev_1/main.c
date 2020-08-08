/*
 * KeyPad_rev_1.c
 *
 * Created: 7/9/2020 10:54:04 AM
 * Author : User™
 */ 

#include <avr/io.h>
#include "KeyPad.h"

int main(void)
{   KeyPad_DDR=0xf0;
	DDRA=0xff;
    /* Replace with your application code */
    while (1) 
    {
		Check_1();
		Check_2();
		Check_3();
		Check_4();
    }
}

