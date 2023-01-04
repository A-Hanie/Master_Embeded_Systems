/*
* Lab2.c
*
* Created: 1/4/2023 6:15:04 PM
* Author : Hanie
*/
#define F_CPU 16000000UL


#include <avr/io.h>
#include <avr/common.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define SET_BIT(REG,bit)  (REG|=(1<<bit))
#define CLR_BIT(REG,bit)  (REG&=~(1<<bit))
#define TOG_BIT(REG,bit)  (REG^=(1<<bit))

#define EN1 PC2
#define EN2 PC3




typedef volatile unsigned char  vuint8_t;

//#define MCRCR *(vuint8_t * )0x55


void GPIO_init(void)
{
	SET_BIT(DDRC,PC2);	// EN1
	SET_BIT(DDRC,PC3);	// EN2
	
	SET_BIT(DDRC,PC4);
	SET_BIT(DDRC,PC5);
	SET_BIT(DDRC,PC6);
	SET_BIT(DDRC,PC7);
}



int main(void)
{
	GPIO_init();
	unsigned char index;
	while(1){
		
		for(index =0 ; index<100 ; index++)
		{

			SET_BIT(PORTC,EN2);
			CLR_BIT(PORTC,EN1);
			PORTC &= ~(0xF<<4);
			PORTC |= (index/10)<<4;

			_delay_ms(200);
			
			PORTC &= ~(0xF<<4);
			SET_BIT(PORTC,EN1);
			CLR_BIT(PORTC,EN2);
			PORTC |= (index%10)<<4;
			
			_delay_ms(200);
		}
	}
}
