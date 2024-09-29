#include"DC_motor.h"

unsigned int speed ;

void DC_init()
{
    // initializing Dc motor
    printf("\n########### DC motor init ###########");
}

void DC_motor(int s)
{
    speed = s ;
    DC_state = STATE(DC_busy) ;

    printf("\nCA------->DC");
}

STATE_define(DC_idle)
{
    DC_state_id = DC_idle ;
    DC_state = STATE(DC_idle) ;

    printf("\nDC idle state -------> Speed = %d",speed);

}
STATE_define(DC_busy)
{
    DC_state_id = DC_busy ;
    DC_state = STATE(DC_busy) ;
    printf("\nDC busy state -------> Speed = %d",speed);
}