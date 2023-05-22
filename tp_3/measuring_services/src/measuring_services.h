
#ifndef MEASURING_SERVICE_H
#define MEASURING_SERVICE_H


#include "stdint.h"
#include "stdbool.h"


void measuring_services_init(void);

void measuring_service_get_temperature_and_humidity(int16_t * h, int16_t * t);

#endif