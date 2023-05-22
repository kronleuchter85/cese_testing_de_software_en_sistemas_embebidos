
#ifndef LIGHT_SERVICE_H
#define LIGHT_SERVICE_H


#include "stdint.h"
#include "stdbool.h"

void light_service_init(void);

int8_t light_service_get_light_level(void);

#endif