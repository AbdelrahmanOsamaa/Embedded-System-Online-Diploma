#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include"state.h"

enum
{
    us_busy
} US_state_id;

//functions prototybes
void US_init();
STATE_define(us_busy);
//globlal pointer to function
void(*us_state)();


#endif