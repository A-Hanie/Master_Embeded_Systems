#include "../include/alarm.h"
#include "../include/driver.h"

Alarm_state_t alarm_state_ID;

STATE_DEC(ALARM_INIT)
{

    // state name
    alarm_state_ID = alarm_init;

    // state action

    // update state
    ptrAlarm_state = STATE(ALARM_WAITING);
}

STATE_DEC(ALARM_WAITING)
{

    // state name
    alarm_state_ID = alarm_waiting;

    // update state
    ptrAlarm_state = STATE(ALARM_WAITING);
}

STATE_DEC(ALARM_ON)
{

    // state name
    alarm_state_ID = alarm_on;

    // state action

    Set_Alarm_actuator(TURN_ON);

    // update state
    ptrAlarm_state = STATE(ALARM_WAITING);
}

STATE_DEC(ALARM_OFF)
{

    // state name
    alarm_state_ID = alarm_off;

    // state action

    Set_Alarm_actuator(TURN_OFF);

    // update state
    ptrAlarm_state = STATE(ALARM_WAITING);
}

void stop_Alarm(void)
{
    ptrAlarm_state = STATE(ALARM_OFF);
}

void start_Alarm(void)
{
    ptrAlarm_state = STATE(ALARM_ON);
}