
#ifndef BMP280_SERVICE_H
#define BMP280_SERVICE_H


#include "stdint.h"
#include "stdbool.h"

void bmp280_service_init(void);
float bmp280_service_get_pressure(void);

#endif