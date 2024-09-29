#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include"state.h"
#include<stdio.h>
#include<stdlib.h>


enum
{
    DC_idle,
    DC_busy
}DC_state_id ;

void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);

void(*DC_state)();




#endif