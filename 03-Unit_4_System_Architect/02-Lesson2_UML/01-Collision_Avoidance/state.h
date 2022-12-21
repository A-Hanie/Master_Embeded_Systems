#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

#define ST_STATE_define(_statFUN_) void ST_##_statFUN_()
#define ST_STATE(_statFUN_) ST_##_statFUN_

void US_Set_distance(int distance);
void DC_Set_rpm(int rpm);



#endif
