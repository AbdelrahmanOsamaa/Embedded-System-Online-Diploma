#include "Collision_avoidance.h"
#include "Ultrasonic.h"
#include "DC_motor.h"

void Setup()
{
	/* init all drivers */
	/* inti IRQ */
	/* init HAL Drivers */
	/* init Block */
	US_init();
	DC_init();
	/* Set State pointer for each block */
	CA_state = STATE(CA_waiting);
	us_state = STATE(us_busy);
	DC_state = STATE(DC_idle);
}
int main()
{
	Setup();

	while(1)
	{
		/* Call state for each block */
		us_state();
		CA_state();
		DC_state();

	}
	return 0;
}