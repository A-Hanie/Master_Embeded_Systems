#include "CA.h"
#include "DC.h"
#include "US.h"

void setup(void)
{

	US_init();
	DC_init();

	CA_state = ST_STATE(CA_waiting);
	US_state = ST_STATE(US_busy);
	DC_state = ST_STATE(DC_idle);
}

int main(void)
{
	volatile int i;
	setup();

	while(1)
	{
		printf("========================\n");
		US_state();
		CA_state();
		DC_state();
		printf("========================\n");

		for(i = 0 ; i <= 500000000 ; i++);
	}
	return 0;
}