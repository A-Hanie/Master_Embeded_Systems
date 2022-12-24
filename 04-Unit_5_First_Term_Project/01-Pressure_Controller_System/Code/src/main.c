#include "../include/driver.h"
#include "../include/state.h"
#include "../include/alarm.h"
#include "../include/alarm_monitor.h"
#include "../include/main_program.h"
#include "../include/pressure_sensor.h"

void GPIO_init(void)
{
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}

void main()
{
	GPIO_init();

	ptr_PS_state = STATE(PS_init);
	ptrAlarm_state = STATE(ALARM_INIT);
	ptrAlarm_monitor_state = STATE(ALARM_MONITOR_OFF);
	ptr_MP_State = STATE(Main_program_State);

	while (1)
	{
		ptr_PS_state();
		ptrAlarm_state();
		ptrAlarm_monitor_state();
		ptr_MP_State();
	}
}
