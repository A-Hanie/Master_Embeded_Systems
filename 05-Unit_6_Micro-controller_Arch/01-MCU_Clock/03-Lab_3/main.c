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

#define RCC_CFGR     *(volatile uint32_t *)( RCC_BASE_ADDRESS + 0x04 )
#define RCC_APB2ENR  *(volatile uint32_t *)( RCC_BASE_ADDRESS + 0x18)
#define RCC_CR       *(volatile uint32_t *)( RCC_BASE_ADDRESS + 0x00 )

#define IOPAEN 2

int main ()
{

  // MCO[3:0]: Microcontroller clock output
  //  00xx: No clock
  //  0100: System clock (SYSCLK) selected
  //  0101: HSI clock selected
  //  0110: HSE clock selected
  //  0111: PLL clock divided by 2 selected
  // use HSI_RC for MCO Microcontroller clock output
  SET(RCC_CFGR, 24);
  CLR(RCC_CFGR, 25);
  SET(RCC_CFGR, 26);
  CLR(RCC_CFGR, 27);

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



  CLR(RCC_CFGR, 0);  //Select PLL as a system clock
  SET(RCC_CFGR, 1);  //Select PLL as a system clock

  //divide by 2
  SET(RCC_CFGR, 10);  // PPRE1 APB1 Prescaler to 4MHZ

  //divide by 4
  SET(RCC_CFGR, 11); //SET PPRE2 APB2 Prescaler  2MHZ
  SET(RCC_CFGR, 13); //SET PPRE2 APB2 Prescaler  2MHZ

  SET(RCC_CFGR,20); //Muliple by 8 by write 0110 on PLLMUL
  SET(RCC_CFGR,19); //Muliple by 8 by write 0110 on PLLMUL

  SET(GPIOA_CRH, 21);  //( Output mode, max speed 10 MHz)
  SET(RCC_CR,24); 	//PLL Enable


  while (1)
    {
      SET(GPIOA_ODR, 13);
      Delay;
      CLR(GPIOA_ODR, 13);
      Delay;
    }
  return 0;
}
