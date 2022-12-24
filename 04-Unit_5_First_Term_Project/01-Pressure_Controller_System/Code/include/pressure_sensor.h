#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"

typedef enum {
	ps_init,
	ps_reading,
	ps_waiting
}PS_state_t;


// Functions declaration

STATE_DEC(PS_init);
STATE_DEC(PS_readVal);
STATE_DEC(PS_waiting);


void (*ptr_PS_state)();

#endif /*PRESSURE_SENSOR_H_*/