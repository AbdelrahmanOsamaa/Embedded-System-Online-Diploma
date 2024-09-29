#ifndef COLLISION_AVOIDANCE_H
#define COLLISION_AVOIDANCE_H

#include"state.h"

enum
{
    CA_waiting,
    CA_driving
}CA_state_id ;

STATE_define(CA_waiting);
STATE_define(CA_driving);

void(*CA_state)();


#endif