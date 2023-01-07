#include "LCD.h"

void _delay_ms (uint32_t t)
{
  uint32_t i, j;
  for (i = 0; i < t; i++)
    for (j = 0; j < 256; j++)
      ;
}

void LCD_Clear_Screen ()
{
  LCD_Send_Command (CLEAR_COMMAND);
}

void LCD_INIT ()
{
  _delay_ms (20);

  GPIO_PinConfig_t PinConfig;
  PinConfig.GPIO_PinNumber = RS;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_CONTROL_PORT, &PinConfig);

  PinConfig.GPIO_PinNumber = RW;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_CONTROL_PORT, &PinConfig);

  PinConfig.GPIO_PinNumber = E;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_CONTROL_PORT, &PinConfig);

#if (DATA_BITS_MODE == 4)

		PinConfig->GPIO_PinNumber = LCD_DATA_4;
		PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
		PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
		GPIO_Init(LCD_DATA_PORT, PinConfig);

		PinConfig->GPIO_PinNumber = LCD_DATA_5;
		PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
		PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
		GPIO_Init(LCD_DATA_PORT, PinConfig);

		PinConfig->GPIO_PinNumber = LCD_DATA_6;
		PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
		PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
		GPIO_Init(LCD_DATA_PORT, PinConfig);

		PinConfig->GPIO_PinNumber = LCD_DATA_7;
		PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
		PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
		GPIO_Init(LCD_DATA_PORT, PinConfig);

		delay_ms(15);


		LCD_Send_Command(FOUR_BITS_DATA_MODE);


		LCD_Send_Command(LCD_2LINE_4BIT_MODE);

	#elif (DATA_BITS_MODE == 8)

  PinConfig.GPIO_PinNumber = LCD_DATA_0;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_DATA_PORT, &PinConfig);

  PinConfig.GPIO_PinNumber = LCD_DATA_1;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_DATA_PORT, &PinConfig);

  PinConfig.GPIO_PinNumber = LCD_DATA_2;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_DATA_PORT, &PinConfig);

  PinConfig.GPIO_PinNumber = LCD_DATA_3;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_DATA_PORT, &PinConfig);

  PinConfig.GPIO_PinNumber = LCD_DATA_4;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_DATA_PORT, &PinConfig);

  PinConfig.GPIO_PinNumber = LCD_DATA_5;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_DATA_PORT, &PinConfig);

  PinConfig.GPIO_PinNumber = LCD_DATA_6;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_DATA_PORT, &PinConfig);

  PinConfig.GPIO_PinNumber = LCD_DATA_7;
  PinConfig.GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (LCD_DATA_PORT, &PinConfig);

  _delay_ms (15);

  LCD_Send_Command (CLEAR_COMMAND);

  LCD_Send_Command (LCD_2LINE_8BIT_MODE);

#endif

  LCD_Send_Command (LCD_ENTRY_MODE);
  LCD_Send_Command (LCD_BEGIN_AT_FIRST_RAW);
  LCD_Send_Command (LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_Send_Command (uint8_t command)
{
  GPIO_WritePin (LCD_CONTROL_PORT, RS, FALSE);
  GPIO_WritePin (LCD_CONTROL_PORT, RW, FALSE);

  _delay_ms (1);
  GPIO_WritePin (LCD_CONTROL_PORT, E, TRUE);
  _delay_ms (1);

#if (DATA_BITS_MODE == 4)

		GPIO_WritePort(LCD_DATA_PORT, ((GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | (command & 0xF0)));

		_delay_ms(1);
		GPIO_WritePin(LCD_CONTROL_PORT, E, FALSE);
		_delay_ms(1);
		GPIO_WritePin(LCD_CONTROL_PORT, E, TRUE);
		_delay_ms(1);


		GPIO_WritePort(LCD_DATA_PORT, ((GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | ((command & 0x0F) << 4)));

	#elif (DATA_BITS_MODE == 8)

  GPIO_WritePort (LCD_DATA_PORT,
		  ((GPIO_ReadPort (LCD_DATA_PORT) & 0xFF00) | command));
#endif

  _delay_ms (1);
  GPIO_WritePin (LCD_CONTROL_PORT, E, FALSE);
  _delay_ms (1);
}

void LCD_Display_Character (uint8_t data)
{
  GPIO_WritePin (LCD_CONTROL_PORT, RS, TRUE);
  GPIO_WritePin (LCD_CONTROL_PORT, RW, FALSE);

  _delay_ms (1);
  GPIO_WritePin (LCD_CONTROL_PORT, E, TRUE);
  _delay_ms (1);

#if (DATA_BITS_MODE == 4)

		GPIO_WritePort(LCD_DATA_PORT, ((GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | (data & 0xF0)));

		_delay_ms(1);
		GPIO_WritePin(LCD_CONTROL_PORT, E, FALSE);
		_delay_ms(1);
		GPIO_WritePin(LCD_CONTROL_PORT, E, TRUE);
		_delay_ms(1);


		GPIO_WritePort(LCD_DATA_PORT, ((GPIO_ReadPort(LCD_DATA_PORT) & 0xFF0F) | ((data & 0x0F) << 4)));

	#elif (DATA_BITS_MODE == 8)

  GPIO_WritePort (LCD_DATA_PORT,
		  ((GPIO_ReadPort (LCD_DATA_PORT) & 0xFF00) | data));
#endif

  _delay_ms (1);
  GPIO_WritePin (LCD_CONTROL_PORT, E, FALSE);
  _delay_ms (1);
}

void LCD_display_String (const char *Str)
{
  uint16_t count = 0;

  while (*Str != '\0')
    {
      LCD_Display_Character (*Str++);
      count++;
      if (count == 16)
	{
	  LCD_Send_Command (LCD_BEGIN_AT_SECOND_RAW);
	}
      else if (count == 32)
	{
	  _delay_ms (1000);
	  LCD_Send_Command (CLEAR_COMMAND);
	  LCD_Send_Command (LCD_BEGIN_AT_FIRST_RAW);
	  count = 0;
	}
    }
}

void LCD_Intger_Number (uint32_t Intger_Number)
{
  char str[7];

  sprintf (str, "%ld", Intger_Number);
  LCD_display_String (str);
}

void LCD_Real_Number (double Real_Number)
{
  char str[16];

  char *temp_sign = (Real_Number < 0) ? "-" : "";
  float temp_val = (Real_Number < 0) ? -Real_Number : Real_Number;

  int temp_Integer1 = temp_val;
  float temp_fraction = temp_val - temp_Integer1;
  int temp_Integer2 = temp_fraction * 100;

  sprintf (str, "%s%d.%02d", temp_sign, temp_Integer1, temp_Integer2);

  LCD_display_String (str);
}
