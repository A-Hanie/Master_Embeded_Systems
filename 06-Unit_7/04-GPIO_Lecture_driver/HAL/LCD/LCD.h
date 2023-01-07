#ifndef LCD_H_
#define LCD_H_

#include "LCD_Config.h"

#define DATA_BITS_MODE 8

void _delay_ms (uint32_t t);

#define FOUR_BITS_DATA_MODE             0x02
#define LCD_2LINE_4BIT_MODE             0x28
#define LCD_2LINE_8BIT_MODE             0x38
#define LCD_BEGIN_AT_FIRST_RAW          0x80
#define LCD_BEGIN_AT_SECOND_RAW         0xC0
#define LCD_DISP_ON_CURSOR_ON		    0x0E
#define LCD_DISP_ON_CURSOR_BLINK	    0x0F
#define LCD_DISP_ON_BLINK	            0x0D
#define LCD_DISP_ON_CURSOR_OFF          0x0C
#define LCD_DISP_OFF_CURSOR_OFF         0x08
#define LCD_MOVE_DISP_RIGHT             0x1C
#define LCD_MOVE_DISP_LEFT              0x18
#define LCD_MOVE_CURSOR_RIGHT           0x14
#define LCD_MOVE_CURSOR_LEFT            0x10
#define LCD_ENTRY_MODE      		    0x06
#define CLEAR_COMMAND			    	0x01

void LCD_INIT ();
void LCD_Clear_Screen ();
void LCD_Send_Command (uint8_t command);
void LCD_Display_Character (uint8_t data);
void LCD_display_String (const char *Str);
void LCD_Intger_Number (uint32_t Intger_Number);
void LCD_Real_Number (double Intger_Number);

#endif
