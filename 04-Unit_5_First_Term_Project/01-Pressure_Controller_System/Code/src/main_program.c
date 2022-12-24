#include "../include/main_program.h"
#include "../include/Platform_Types.h"
#include "../include/state.h"

static uint32_t pressure_val;

STATE_DEC(Main_program_State)
{

    pressure_val = PS_getPressureVal();

    ptr_MP_State = STATE(Main_program_State);
}

uint32_t H_pressure_detected()
{

    if (pressure_val < pressure_threshold)
    {

        return 0;
    }
    else
    {
        return 1;
    }
}