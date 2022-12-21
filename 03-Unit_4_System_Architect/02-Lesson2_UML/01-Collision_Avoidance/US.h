#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_


#include "state.h"

enum {
	US_busy
}US_Status;

ST_STATE_define(US_busy);

extern void (*US_state)();

void US_init();
int ultrasonic_get_distance_random(int start, int end, int count);


#endif 