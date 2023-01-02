/*
 * Lab2.c
 *
 * Created: 1/2/2023 6:15:04 PM
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
	CLR_BIT(DDRB,PB2);
	CLR_BIT(DDRD,PD3);
	SET_BIT(DDRD,PD5);
	SET_BIT(DDRD,PD6);
	SET_BIT(DDRD,PD7);
}
void EXTI_init(void)
{
	/*
	External Interrupt 0 (INT0) - PD2. >> irq occur when “any logical change”
	External Interrupt 1 (INT1) - PD3. >> irq occur when “rising edge”
	External Interrupt 2 (INT2) - PB2. >> irq occur when “Falling edge”
	*/
	// INT0
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	// INT1
	SET_BIT(MCUCR,ISC11);
	SET_BIT(MCUCR,ISC10);	
	// INT2
	CLR_BIT(MCUCSR,ISC2);
	
	// Enable External Interrupt
	SET_BIT(GICR,INT1);
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT2);
	// Enable Global Interrupt
	sei();
}
 

int main(void)
{

	GPIO_init();
	EXTI_init();
    while (1) 
    {
		CLR_BIT(PORTD,PINA7);
		CLR_BIT(PORTD,PINA6);
		CLR_BIT(PORTD,PINA5);
    }
}

ISR(INT0_vect)
{
	SET_BIT(PORTD,PD5);
	_delay_ms(1000);
	CLR_BIT(PORTD,PD5);
}

ISR(INT1_vect)
{
	SET_BIT(PORTD,PD6);
	_delay_ms(1000);
	CLR_BIT(PORTD,PD6);
}

ISR(INT2_vect)
{
	SET_BIT(PORTD,PD7);
	_delay_ms(1000);
	CLR_BIT(PORTD,PD7);
}


