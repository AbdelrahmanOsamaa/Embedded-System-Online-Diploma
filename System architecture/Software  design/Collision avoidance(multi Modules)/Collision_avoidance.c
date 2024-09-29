#include"Collision_avoidance.h"

unsigned int distance = 0;
unsigned int speed = 0;
unsigned int threshold = 50;

void US_distance_set (int d)
{
    distance = d ;
    if(distance <= threshold)
    {
        CA_state = STATE(CA_waiting);
    }
    else
    {
        CA_state = STATE(CA_driving);
    }
    printf("\nUS ---------> CA Distance = %d",distance);
}

STATE_define(CA_waiting)
{
    CA_state_id = CA_waiting ;
    printf("\nCA waiting State: Distance = %d  Speed = %d \n",distance , speed);
    speed = 0 ;
    DC_motor(speed);
}

STATE_define(CA_driving)
{
	
	CA_state_id = CA_driving;
	printf("\nCA_driving State: Distance = %d  Speed = %d \n",distance , speed);
	speed = 30;
	DC_motor(speed);

}