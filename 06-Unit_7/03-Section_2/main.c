/*
* Section2.c
*
* Created: 1/4/2023 9:23:08 AM
* Author : Hany
*/
#define F_CPU 8000000UL

#include <avr/io.h>
#include "LCD/lcd.h"
#include "keypad/keypad.h"

int main(void)
{
	char key;

	LCD_INIT();
	
	Keypad_init();
	
	
	
	while (1)
	{
		key=   Keypad_getkey();
		
		switch(key)
		{
			case ('A'):break;
			default:LCD_WRITE_CHAR(key);break;
		}

	}
}

