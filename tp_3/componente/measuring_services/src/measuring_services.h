
#ifndef MEASURING_SERVICE_H
#define MEASURING_SERVICE_H


#include "stdint.h"
#include "stdbool.h"

typedef enum {
    MEASURING_INITIALIZATION_ERROR = -1,
    MEASURING_INITIALIZATION_SUCCESS = 0,
    MEASURING_READING_ERROR = -1,
    MEASURING_READING_SUCCESS = 0 
} t_measuring_status;


#define BMP_SDA_GPIO 18
#define BMP_SCL_GPIO 19

t_measuring_status measuring_services_init(void);

t_measuring_status measuring_service_get_temperature_and_humidity(int16_t * h, int16_t * t);

t_measuring_status measuring_service_get_pressure(float * p ,float * h, float * t);


#endif