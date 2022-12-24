#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "state.h"


typedef enum {
	alarm_monitor_waiting,
	alarm_monitor_on,
	alarm_monitor_off
}Alarm_monitor_state_t;


// Functions declaration
STATE_DEC(ALARM_MONITOR_WAITING);
STATE_DEC(ALARM_MONITOR_ON);
STATE_DEC(ALARM_MONITOR_OFF);

void (*ptrAlarm_monitor_state)();


#endif /* ALARM_MONITOR_H_ */