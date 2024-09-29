#include"Ultrasonic.h"

extern void(*us_state)();
unsigned int distance;
//generate random values to test the code
int generate_random(int l , int r , int count)
{
    int i ;
    int rand_num ;
    for(i = 0 ; i < count ; i++)
    {
        rand_num = (rand() % (r - l + 1)) + l ;
        return rand_num ;
    }
}

void US_init()
{
    //initializing ultrasonic sensor
    //call ultrasonic driver or function
    printf("\n######### Ultrasonic init #########");
}

STATE_define(us_busy)
{
    US_state_id = us_busy ;
    //reading from ultrasonic sensor
    distance = generate_random(45,55,1) ;
    printf("\nUS_busy State ------> Distance = %d",distance);

    US_distance_set(distance);
    us_state = STATE(us_busy) ;
}