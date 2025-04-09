#ifndef ACTUATOR_H
#define ACTUATOR_H
#include "defines.h"

void actuator_init();
void control_actuator(float temperature, float set_point);

#endif