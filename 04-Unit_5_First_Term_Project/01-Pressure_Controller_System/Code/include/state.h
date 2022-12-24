#ifndef STATE_H_
#define STATE_H_

// #include "stdio.h"
// #include "stdlib.h"
#include "../include/Platform_Types.h"

#define STATE_DEC(_statFN_) void ST_##_statFN_()
#define STATE(_statFN_) ST_##_statFN_

// States Connections
uint32_t PS_getPressureVal(void); /* Pressure_sensor --------> Main_program */
uint32_t H_pressure_detected();   /* Main_program --------> Alarm_monitor */
void stop_Alarm(void);            /* Alarm_monitor --------> Alarm */
void start_Alarm(void);           /* Alarm_monitor --------> Alarm */

#endif
