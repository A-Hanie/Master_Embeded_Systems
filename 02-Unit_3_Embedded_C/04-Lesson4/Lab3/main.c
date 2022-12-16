
#include "Bit_Math.h"


#define Delay            for(_delay=0 ; _delay < 2000 ; _delay++)   //delay time

//enable GPIOF
#define SYSCTL_BASE       0X400FE000
#define SYSCTL_RCGC2_R    *((volatile unsigned long *)(SYSCTL_BASE+0x108)) 

//define port f Register
#define GPIO_PORTF_BASE   0X40025000
#define GPIO_PORTF_DIR_R  *((volatile unsigned long *)(GPIO_PORTF_BASE+0X400)) 
#define GPIO_PORTF_DATA_R *((volatile unsigned long *)(GPIO_PORTF_BASE+0X3FC)) 
#define GPIO_PORTF_DEN_R  *((volatile unsigned long *)(GPIO_PORTF_BASE+0X51C)) 

int main()
{
  volatile unsigned long _delay; 
  
  SYSCTL_RCGC2_R = 0x20;       //Enable GPIO port
  Delay;


  SET_BIT(GPIO_PORTF_DIR_R,3); 
  SET_BIT(GPIO_PORTF_DEN_R,3);  
    
  while(1)
  {
    SET_BIT(GPIO_PORTF_DATA_R,3);    // OFF
    Delay;
    CLR_BIT(GPIO_PORTF_DATA_R,3);   //  ON
    Delay;

  }
  return 0;
}