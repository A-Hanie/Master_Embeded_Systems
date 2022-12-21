#include "state.h"
#include "DC.h"

static int DC_rpm = 0;

void (*DC_state)();

void DC_init()
{
	printf("DC_init\n");
}

void DC_Set_rpm(int rpm)
{
	DC_rpm = rpm;
	DC_state = ST_STATE(DC_busy);
	printf("CA ------- rpm = %d -----> DC \n", DC_rpm);
}

ST_STATE_define(DC_idle)
{
	DC_Status = DC_idle;

	printf("CA_idle State: rpm = %d\n", DC_rpm);

}

ST_STATE_define(DC_busy)
{
	DC_Status = DC_busy;

	printf("DC_busy State: rpm = %d\n", DC_rpm);
	DC_state = ST_STATE(DC_idle);


}