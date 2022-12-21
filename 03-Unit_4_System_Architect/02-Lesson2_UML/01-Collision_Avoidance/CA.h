#ifndef COLLISION_AVOIDANC_H_
#define COLLISION_AVOIDANC_H_

#include "state.h"

enum {
	CA_waiting,
	CA_driving
}CA_Status;

ST_STATE_define(CA_waiting);
ST_STATE_define(CA_driving);

extern void (*CA_state)();

#endif 