#include "SEV_SEG.h"

unsigned char Segment[] =
  { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO };

void SEV_SEG_INIT ()
{

  GPIO_PinConfig_t *PinConfig = NULL;
  PinConfig->GPIO_PinNumber = SEGMENT_PIN1;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (SEGMENT_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = SEGMENT_PIN2;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (SEGMENT_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = SEGMENT_PIN3;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (SEGMENT_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = SEGMENT_PIN4;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (SEGMENT_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = SEGMENT_PIN5;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (SEGMENT_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = SEGMENT_PIN6;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (SEGMENT_PORT, PinConfig);

  PinConfig->GPIO_PinNumber = SEGMENT_PIN7;
  PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
  PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
  GPIO_Init (SEGMENT_PORT, PinConfig);
}
