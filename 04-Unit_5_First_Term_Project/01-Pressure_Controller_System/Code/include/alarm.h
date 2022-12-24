#ifndef ALARM_H_
#define ALARM_H_

#define TURN_ON 0 // Active low
#define TURN_OFF 1

#include "state.h"

typedef enum
{
	alarm_init,
	alarm_waiting,
	alarm_on,
	alarm_off
} Alarm_state_t;

// Functions declaration

STATE_DEC(ALARM_INIT);
STATE_DEC(ALARM_WAITING);
STATE_DEC(ALARM_ON);
STATE_DEC(ALARM_OFF);

void (*ptrAlarm_state)();

#endif /*ALARM_H_*/