#include "Keypad.h"

static const unsigned char g_Keypad_Mapping[4][4] =
  {
    { '1', '2', '3', '/' },
    { '4', '5', '6', '*' },
    { '7', '8', '9', '-' },
    { 'C', '0', '=', '+' } };

uint8_t INPUT_IS_STILL_VALID ()
{
  return (GPIO_ReadPin (KEYPAD_PORT, COLUM0)
      && GPIO_ReadPin (KEYPAD_PORT, COLUM1)
      && GPIO_ReadPin (KEYPAD_PORT, COLUM2)
      && GPIO_ReadPin (KEYPAD_PORT, COLUM3));
}

void Keypad_INIT (void)
{

  GPIO_PinConfig_t *PinConfig = NULL;
  PinConfig->GPIO_PinNumber = ROW0;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (KEYPAD_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = ROW1;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (KEYPAD_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = ROW2;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (KEYPAD_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = ROW3;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (KEYPAD_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = COLUM0;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (KEYPAD_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = COLUM1;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (KEYPAD_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = COLUM2;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (KEYPAD_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = COLUM3;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (KEYPAD_PORT, PinConfig);

  GPIO_WritePort (KEYPAD_PORT,
		  ((KEYPAD_PORT->ODR._ODR & 0xFF) | (NO_VALID_INPUT << 8)));
}

unsigned char Keypad_Get_Character (void)
{
  uint8_t row;
  uint8_t colum = NO_VALID_INPUT;
  unsigned char result = NO_VALID_INPUT;

  for (row = 0; row < 4; row++)
    {

      GPIO_WritePin (KEYPAD_PORT, ROW0, TRUE);
      GPIO_WritePin (KEYPAD_PORT, ROW1, TRUE);
      GPIO_WritePin (KEYPAD_PORT, ROW2, TRUE);
      GPIO_WritePin (KEYPAD_PORT, ROW3, TRUE);

      switch (row)
	{
	case 0:
	  GPIO_WritePin (KEYPAD_PORT, ROW0, FALSE);
	  break;
	case 1:
	  GPIO_WritePin (KEYPAD_PORT, ROW1, FALSE);
	  break;
	case 2:
	  GPIO_WritePin (KEYPAD_PORT, ROW2, FALSE);
	  break;
	case 3:
	  GPIO_WritePin (KEYPAD_PORT, ROW3, FALSE);
	  break;
	default:
	  break;
	}

      if (GPIO_ReadPin (KEYPAD_PORT, COLUM0) == INPUT_STATE)
	{
	  colum = 0;
	}
      else if (GPIO_ReadPin (KEYPAD_PORT, COLUM1) == INPUT_STATE)
	{
	  colum = 1;
	}
      else if (GPIO_ReadPin (KEYPAD_PORT, COLUM2) == INPUT_STATE)
	{
	  colum = 2;
	}
      else if (GPIO_ReadPin (KEYPAD_PORT, COLUM3) == INPUT_STATE)
	{
	  colum = 3;
	}
      else
	{
	  ;
	}

      if (colum != NO_VALID_INPUT)
	{

	  while (INPUT_IS_STILL_VALID () == INPUT_STATE)
	    ;

	  result = g_Keypad_Mapping[row][colum];
	  break;
	}

    }
  return result;
}
