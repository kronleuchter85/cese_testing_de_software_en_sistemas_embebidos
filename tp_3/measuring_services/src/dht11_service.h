
#ifndef DHT11_SERVICE_H
#define DHT11_SERVICE_H


#include "stdint.h"
#include "stdbool.h"

void dht11_service_init(void);

int16_t dht11_service_get_humidity();
int16_t dht11_service_get_temperature();

#endif 