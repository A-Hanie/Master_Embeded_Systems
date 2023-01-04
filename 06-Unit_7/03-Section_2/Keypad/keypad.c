#include "keypad.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//columns

void Keypad_init(){
	DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	KEYPAD_PORT = 0xFF;
}

char Keypad_getkey(){
	int col_i,raw_i;
	for (col_i = 0; col_i < 4; col_i++){
		KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));
		KEYPAD_PORT &= ~(1<<Key_padCol[col_i]);
		for(raw_i = 0; raw_i < 4; raw_i++){
			if (!(keypadPIN & (1 << Key_padRow[raw_i])))
			{
				while(!(keypadPIN & (1 << Key_padRow[raw_i])));
				switch(col_i){
					case (0):
						if (raw_i == 0) return '7';
						else if (raw_i == 1) return '4';
						else if (raw_i == 2) return '1';
						else if (raw_i == 3) return '?';
						break;
					case (1):
						if (raw_i == 0) return '8';
						else if (raw_i == 1) return '5';
						else if (raw_i == 2) return '2';
						else if (raw_i == 3) return '0';
						break;
					case (2):
						if (raw_i == 0) return '9';
						else if (raw_i == 1) return '6';
						else if (raw_i == 2) return '3';
						else if (raw_i == 3) return '=';
						break;
					case (3):
						if (raw_i == 0) return '/';
						else if (raw_i == 1) return '*';
						else if (raw_i == 2) return '-';
						else if (raw_i == 3) return '+';
						break;
				}
			}
		}
	}
	return 'A';
}