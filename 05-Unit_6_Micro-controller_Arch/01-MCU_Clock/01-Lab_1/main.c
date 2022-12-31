/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Hanie
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 ******************************************************************************
 */

#define Delay        for(uint32_t __=0 ; __ < 2000 ; __++)

#define SET(Register_name,bit_no)     Register_name|=(1<<bit_no)
#define CLR(Register_name,bit_no)   Register_name&=~(1<<bit_no)

typedef unsigned int uint32_t;

//GPIOA base addresses
#define GPIOA_BASE_ADDRESS        0x40010800

#define GPIOA_CRH    *(volatile uint32_t *)(GPIOA_BASE_ADDRESS + 0x04)
#define GPIOA_ODR    *(volatile uint32_t *)(GPIOA_BASE_ADDRESS + 0x0C)

#define RCC_BASE_ADDRESS          0x40021000

#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE_ADDRESS + 0x18)

#define IOPAEN 2

int main ()
{

  //Enable GPIOA peripheral clock
  /*
   * Bit 2 IOPAEN: IO port A clock enable
   * =====================================
   *    0: IO port A clock disabled
   *    1: IO port A clock enabled
   *
   * */
  SET(RCC_APB2ENR, IOPAEN);

  //Init GPIOA
  /*
  00: General purpose output push-pull
  01: General purpose output Open-drain
  10: Alternate function output Push-pull
  11: Alternate function output Open-drain
  */
  CLR(GPIOA_CRH, 22);	// 00: General purpose output push-pull

  SET(GPIOA_CRH, 21);  //( Output mode, max speed 10 MHz)

  while (1)
    {
      SET(GPIOA_ODR, 13);
      Delay;
      CLR(GPIOA_ODR, 13);
      Delay;
    }
  return 0;
}
