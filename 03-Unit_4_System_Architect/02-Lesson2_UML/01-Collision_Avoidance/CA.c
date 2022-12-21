#include "CA.h"

static int CA_rpm = 0;
static int CA_distance = 0;
static int CA_threshold = 50;

void (*CA_state)();

void US_Set_distance(int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold) ? (CA_state = ST_STATE(CA_waiting)) : (CA_state = ST_STATE(CA_driving));
	printf("US ----- distance = %d ---> CA \n", CA_distance);

}

ST_STATE_define(CA_waiting)
{
	CA_Status = CA_waiting;
	printf("CA_	wating State: distance = %d, rpm = %d\n", CA_distance, CA_rpm);

	CA_rpm = 0;
	DC_Set_rpm(CA_rpm);

}

ST_STATE_define(CA_driving)
{
	CA_Status = CA_driving;
	printf("CA_driving State: distance = %d, rpm = %d\n", CA_distance, CA_rpm);

	CA_rpm = 30;
	DC_Set_rpm(CA_rpm);

}