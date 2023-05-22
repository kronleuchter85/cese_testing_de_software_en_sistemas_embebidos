
#ifndef JOYSTICK_SERVICE_H
#define JOYSTICK_SERVICE_H


#include "stdint.h"
#include "stdbool.h"

void joystick_service_init(void);
float joystick_service_get_reading_x(void);
float joystick_service_get_reading_y(void);

#endif