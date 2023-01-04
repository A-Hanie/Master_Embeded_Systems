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

typedef volatile unsigned char  vuint8_t;

//#define MCRCR *(vuint8_t * )0x55


void GPIO_init(void)
{
	SET_BIT(DDRD,PD5);
	SET_BIT(DDRD,PD6);
	SET_BIT(DDRD,PD7);
}

 

int main(void)
{

	GPIO_init();
    while (1) 
    {
		SET_BIT(PORTD,PD5);
		_delay_ms(500);
		SET_BIT(PORTD,PD6);
		_delay_ms(500);
		SET_BIT(PORTD,PD7);
		_delay_ms(500);
		CLR_BIT(PORTD,PD7);
		_delay_ms(500);
		CLR_BIT(PORTD,PD6);
		_delay_ms(500);
		CLR_BIT(PORTD,PD5);
		_delay_ms(500);		

    }
}