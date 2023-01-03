/***************************
 * NAME: A.HANIE
 * DATE: 3.1.2023
***************************/


#define SET_BIT(Register_name,bit_no)          Register_name|=(1<<bit_no)
#define CLR_BIT(Register_name,bit_no)        Register_name&=~(1<<bit_no)
#define TOG_BIT(Register_name,bit_no)       Register_name^=(1<<bit_no)

typedef unsigned int  uint32_t;
#define _delay         for( volatile uint32_t i = 0 ; i<5000 ; i++ )

#define RCC            0x40021000
#define RCC_APB2ENR    *( volatile uint32_t *)( RCC + 0x18 )

#define GPIOA          0x40010800
#define GPIOA_CRL      *( volatile uint32_t *)( GPIOA + 0x00 )
#define GPIOA_CRH      *( volatile uint32_t *)( GPIOA + 0x04 )
#define GPIOA_IDR      *( volatile uint32_t *)( GPIOA + 0x08 )
#define GPIOA_ODR      *( volatile uint32_t *)( GPIOA + 0x0C )

#define GPIOB          0x40010C00
#define GPIOB_CRL      *( volatile uint32_t *)( GPIOB + 0x00 )
#define GPIOB_CRH      *( volatile uint32_t *)( GPIOB + 0x04 )
#define GPIOB_IDR      *( volatile uint32_t *)( GPIOA + 0x08 )
#define GPIOB_ODR      *( volatile uint32_t *)( GPIOB + 0x0C )

void Init_Clocks ()
{
  SET_BIT(RCC_APB2ENR, 2);
  SET_BIT(RCC_APB2ENR, 3);
}

void Init_GPIO ()
{
  GPIOA_ODR = 0;

  //MODE1 Pin Mode
  SET_BIT(GPIOB_CRL, 4);          // Port B pin1 as output mode at 10 MHZ
  CLR_BIT(GPIOB_CRL, 5);

  //CNF1 Pin Mode
  CLR_BIT(GPIOB_CRL, 6);        // push-pull
  CLR_BIT(GPIOB_CRL, 7);

  //MODE13 Pin Mode
  SET_BIT(GPIOB_CRH, 20);        // Port B pin13 as output mode at 10 MHZ
  CLR_BIT(GPIOB_CRH, 21);

  //CNF13 Pin Mode
  CLR_BIT(GPIOB_CRH, 22);       // push-pull
  CLR_BIT(GPIOB_CRH, 23);

  //MODE1 Pin Mode
  CLR_BIT(GPIOA_CRL, 4);        // Port A pin1 as input
  CLR_BIT(GPIOA_CRL, 5);
  //CNF1 Pin Mode
  SET_BIT(GPIOA_CRL, 6);          // Floating input
  CLR_BIT(GPIOA_CRL, 7);

  //MODE13 Pin Mode
  CLR_BIT(GPIOA_CRH, 20);       // Port A pin1 as input
  CLR_BIT(GPIOA_CRH, 21);
  //CNF13 Pin Mode
  SET_BIT(GPIOA_CRH, 22);         // Floating input
  CLR_BIT(GPIOA_CRH, 23);

  SET_BIT(GPIOB_ODR, 1);
  SET_BIT(GPIOB_ODR, 13);
}

int main ()
{
  Init_Clocks ();
  Init_GPIO ();

  while (1)
    {
      if ((GPIOA_IDR & (1 << 1)) != (1 << 1))
	{
	  TOG_BIT(GPIOB_ODR, 1);
	  _delay;
	  while ((GPIOA_IDR & (1 << 1)) != (1 << 1));   //Single Pressing
	}
      if ((GPIOA_IDR & (1 << 13)) == (1 << 13))         //multi pressing
	TOG_BIT(GPIOB_ODR, 13);
      _delay;
    }
}
