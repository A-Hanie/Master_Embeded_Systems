#include "../include/driver.h"

void delay(int nCount)
{
	for (; nCount != 0; nCount--)
		;
}

int getPressureVal()
{
	return (GPIOA_IDR & 0xFF);
}

void Set_Alarm_actuator(int i)
{
	if (i == 1)
	{
		SET_BIT(GPIOA_ODR, 13);
	}
	else if (i == 0)
	{
		RESET_BIT(GPIOA_ODR, 13);
	}
}
