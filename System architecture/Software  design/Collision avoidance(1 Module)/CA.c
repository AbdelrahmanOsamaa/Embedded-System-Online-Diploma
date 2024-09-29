#include<stdio.h>
#include<stdlib.h>

unsigned int distance , speed , threshold = 50 ;
enum
{
    waiting,
    driving
}state_id;

#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

// prototypes
STATE_define(waiting);
STATE_define(driving);

//global pointer to function
void (*state)() ;

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

STATE_define(waiting)
{
    state_id = waiting ;
    speed = 0 ;
    distance = generate_random(45,55,1) ;
    //check event
    if (distance <= threshold)
    {
        state = STATE(waiting);
        printf("\nWaiting state #### Distance = %d #### Speed = %d",distance,speed);
    }
    else
    {
        state = STATE(driving);
        // printf("\nDriving state #### Distance = %d #### Speed = %d",distance,speed);
    }
    
}

STATE_define(driving)
{
    state_id = driving ;
    speed = 30 ;
    distance = generate_random(45,55,1);
     if (distance <= threshold)
    {
        state = STATE(waiting);
        // printf("\nWaiting state #### Distance = %d #### Speed = %d",distance,speed);
    }
    else
    {
        state = STATE(driving);
        printf("\nDriving state #### Distance = %d #### Speed = %d",distance,speed);
    }
}

void setup()
{
    state = STATE(waiting);

}

void main()
{
    volatile int delay;
    setup();
    while(1)
    {
        state();
        for(delay = 0 ; delay <= 10000 ; delay++);
    }
}