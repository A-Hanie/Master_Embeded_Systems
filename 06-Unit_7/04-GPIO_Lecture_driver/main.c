
#include "HAL/LCD/LCD.h"
#include "HAL/Keypad/Keypad.h"
#include "HAL/SEV_SEG/SEV_SEG.h"

#define NO_VALID_INPUT  0xFF

void Clock_INIT (GPIO_t *GPIOx)
{
  if (GPIOx == GPIOA)
    RCC->APB2ENR.IOPAEN = TRUE;
  else if (GPIOx == GPIOB)
    RCC->APB2ENR.IOPBEN = TRUE;
  else if (GPIOx == GPIOC)
    RCC->APB2ENR.IOPCEN = TRUE;
  else if (GPIOx == GPIOD)
    RCC->APB2ENR.IOPDEN = TRUE;
  else
    RCC->APB2ENR.IOPEEN = TRUE;
}

int main (void)
{
  unsigned char key = NO_VALID_INPUT;
  unsigned char LCD[] =
    { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
  unsigned char Segment[] =
    { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE };

  Clock_INIT (GPIOA);
  Clock_INIT (GPIOB);

  LCD_INIT ();
  Keypad_INIT ();
  SEV_SEG_INIT ();

  _delay_ms (1000);

  LCD_display_String ("Hey ");
  _delay_ms (1000);
  LCD_Clear_Screen ();

  for (unsigned char i = 0; i < 11; i++)
    {
      LCD_Display_Character (LCD[i]);

      GPIOB->ODR._ODR = ((GPIOB->ODR._ODR) & ~(((1 << 7) - 1) << 9))
	  | (Segment[i] << 7);
      _delay_ms (500);
    }
  LCD_Clear_Screen ();
  LCD_display_String ("Keypad is ready ");

  while (1)
    {

      key = Keypad_Get_Character ();

      if (key != NO_VALID_INPUT)
	{
	  LCD_Clear_Screen ();

	  if (key == 'C')
	    {
	      LCD_Clear_Screen ();
	      continue;
	    }
	  else
	    {
	      LCD_Display_Character (key);
	    }

	}
    }

}
