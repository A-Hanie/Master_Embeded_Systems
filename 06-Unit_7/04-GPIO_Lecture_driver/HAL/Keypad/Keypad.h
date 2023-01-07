#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "KeypadConfig.h"

#define INPUT_STATE		0U
#define OUTPUT_STATE	1U
#define NO_OUTPUT_STATE	1U
#define NO_VALID_INPUT	0xFF

uint8_t INPUT_IS_STILL_VALID ();

void Keypad_INIT (void);
unsigned char Keypad_Get_Character (void);

#endif
