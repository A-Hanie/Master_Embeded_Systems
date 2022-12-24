#include "../include/driver.h"
#include "../include/alarm_monitor.h"

Alarm_monitor_state_t Alarm_monitor_state_id;

STATE_DEC(ALARM_MONITOR_WAITING)
{

    // state name
    Alarm_monitor_state_id = alarm_monitor_waiting;

    // state action

    delay(500);

    // update state
    ptrAlarm_monitor_state = STATE(ALARM_MONITOR_OFF);
}

STATE_DEC(ALARM_MONITOR_ON)
{

    // state name
    Alarm_monitor_state_id = alarm_monitor_on;

    // state action
    start_Alarm();

    // update state
    ptrAlarm_monitor_state = STATE(ALARM_MONITOR_WAITING);
}

STATE_DEC(ALARM_MONITOR_OFF)
{

    // state name
    Alarm_monitor_state_id = alarm_monitor_off;

    // state action

    stop_Alarm();

    // update state
    if (1 == H_pressure_detected())
    {
        ptrAlarm_monitor_state = STATE(ALARM_MONITOR_ON);
    }
    else
    {
        ptrAlarm_monitor_state = STATE(ALARM_MONITOR_OFF);
    }
}