 /*
 * LCD.h
 *
 * Created: 7/14/2020 2:15:52 PM
 *  Author: User™
 */ 
 #define F_CPU 16000000UL
 #include <util/delay.h>
 #include "dio_cfg.h"

#ifndef LCD_H_
#define LCD_H_

#define LCD_Control_Port  PORTB_REG
#define LCD_Control_Dir   DDRB_REG

#define LCD_Data_Port     PORTA_REG
#define LCD_Data_Dir      DDRA_REG 


 #define LCD_RS  Dio_Channel_B1
 #define LCD_RW  Dio_Channel_B2
 #define LCD_EN  Dio_Channel_B3
 
 void LCD_Init(void);
 void LCD_Char (uint8 data);
 void LCD_Command (uint8 cmd);			//frist one
 void LCD_String(char *str);
 void LCD_String_xy (char row, char pos, char *str);


#endif /* LCD_H_ */