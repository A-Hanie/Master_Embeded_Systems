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

#define Set(Register_name,bit_no)     Register_name|=(1<<bit_no)
#define Reset(Register_name,bit_no)   Register_name&=~(1<<bit_no)
#define Toggle(Register_name,bit_no)  Register_name^=(1<<bit_no)

typedef volatile unsigned int uint32_t;

#define RCC            0x40021000
#define RCC_APB2ENR    *( volatile uint32_t *)( RCC + 0x18 )

//EXTI External Interrupt Peripheral
#define EXTI           0x40010400
#define EXTI_IMR       *( volatile uint32_t *)( EXTI + 0x00 )
#define EXTI_RTSR      *( volatile uint32_t *)( EXTI + 0x08 )
#define EXTI_PR        *( volatile uint32_t *)( EXTI + 0x14 )

//Nested Vectored Interrupt Controller
#define NVIC           0xE000E100
#define NVIC_ISER0     *( volatile uint32_t *)( NVIC + 0x00 )

// Altrenate Function I/O Peripheral
#define AFIO           0x40010000
#define AFIO_EXTICR1   *( volatile uint32_t *)( AFIO + 0x08 )

//GPIO
#define GPIOA          0x40010800
#define GPIOA_CRL      *( volatile uint32_t *)( GPIOA + 0x00 )
#define GPIOA_CRH      *( volatile uint32_t *)( GPIOA + 0x04 )
#define GPIOA_ODR      *( volatile uint32_t *)( GPIOA + 0x0C )

void Init_HSI_Clock ()
{
  Set(RCC_APB2ENR, 0);    //Enable AFIO  Clock
  Set(RCC_APB2ENR, 2);    //Enable GPIOA Clock
  return;
}

void Init_EXTI0 ()
{
  //Enable rising trigger selection register
  Set(EXTI_RTSR, 0);

  //Enable Interrupt Mask Register
  Set(EXTI_IMR, 0);

  //Enable gloable Nested Vectored Interrupt Controller
  Set(NVIC_ISER0, 6);

  return;
}

void Init_GPIOA ()
{

  Set(GPIOA_CRL, 2);	//MODE0 Input mode by write 00

  Reset(GPIOA_CRH, 22); //CNF13  General purpose output push-pull by write 00

  Set(GPIOA_CRH, 21); //MODE13 Output mode, max speed 2 MHz. by write 10

  return;
}

int main ()
{
  Init_HSI_Clock ();
  Init_GPIOA ();
  Init_EXTI0 ();

  while (1)
    ;

  return 0;
}

void EXTI0_IRQHandler ()
{
  Toggle(GPIOA_ODR, 13);
  Set(EXTI_PR, 0); // Clear pending flag
}
