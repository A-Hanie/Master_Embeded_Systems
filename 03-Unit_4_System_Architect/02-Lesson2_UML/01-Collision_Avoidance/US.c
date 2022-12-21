#include "US.h"

static int US_distance = 0;

void (*US_state)();

void US_init()
{
	printf("US init done \n");
}

ST_STATE_define(US_busy)
{
		US_Status = US_busy;
		US_distance = ultrasonic_get_distance_random(45, 55, 1);
		printf("US busy State---> distance = %d \n", US_distance);

		US_Set_distance(US_distance);
		US_state = ST_STATE(US_busy);

}

int ultrasonic_get_distance_random(int min, int max, int count)
{
	int _;
	for (_ = 0; _ < count; _++)
	{
		int rand_num = (rand() % (max - min + 1)) + min;
		return rand_num;
	}
	return 0;
}

