#ifndef MAIN_PROGRAM_H_
#define MAIN_PROGRAM_H_

#include "state.h"

static uint32_t pressure_threshold = 20;

// Functions declaration
STATE_DEC(Main_program_State);

void (*ptr_MP_State)();

#endif /* MAIN_PROGRAM_H_ */
