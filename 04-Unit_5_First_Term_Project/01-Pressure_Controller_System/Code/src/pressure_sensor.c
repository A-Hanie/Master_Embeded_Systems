#include "../include/pressure_sensor.h"
#include "../include/driver.h"

PS_state_t PS_state_ID;
uint32_t pressure_val;

STATE_DEC(PS_init)
{
    // state name
    PS_state_ID = ps_init;

    // update state
    ptr_PS_state = STATE(PS_readVal);
}
STATE_DEC(PS_readVal)
{

    // state name
    PS_state_ID = ps_reading;

    // state action
    pressure_val = getPressureVal();
    // update state
    ptr_PS_state = STATE(PS_waiting);
}

STATE_DEC(PS_waiting)
{

    // state name
    PS_state_ID = ps_waiting;

    // state action
    delay(1000);

    // update state
    ptr_PS_state = STATE(PS_readVal);
}

uint32_t PS_getPressureVal(void)
{
    return pressure_val;
}
