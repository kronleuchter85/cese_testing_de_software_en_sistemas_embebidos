#include "measuring_services.h"
#include "dht11_service.h"
#include "bmp280_service.h"
#include "light_service.h"
#include "joystick_service.h"
#include "display_service.h"
#include "motors_service.h"

void measuring_services_init(void){

    //
    // inicializacion de modulos
    //
    dht11_service_init();
    bmp280_service_init();
    light_service_init();
    joystick_service_init();
    display_service_init();
    motors_service_init();
}


void measuring_service_get_temperature_and_humidity(int16_t * h, int16_t * t){

    int16_t humidity = dht11_service_get_humidity();
    int16_t temperature = dht11_service_get_temperature();

    *h = humidity;
    *t = temperature;
}


int8_t measuring_service_get_light_level(){

    return light_service_get_light_level();
}

float measuring_service_get_pressure(){

    return bmp280_service_get_pressure();
}


void measuring_service_get_joystick_readings(float * x, float * y){
    
}
