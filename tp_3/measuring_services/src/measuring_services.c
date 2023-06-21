#include "measuring_services.h"
#include "bmp280_service.h"
#include "light_service.h"
#include "joystick_service.h"
#include "display_service.h"
#include "motors_service.h"

#include "dht.h"


//
// DHT11 consts
//

static const gpio_num_t dht_gpio = 2;
static const dht_sensor_type_t sensor_type = DHT_TYPE_DHT11;

void measuring_services_init(void){

    //
    // inicializacion de modulos
    //
    bmp280_service_init();
    light_service_init();
    joystick_service_init();
    display_service_init();
    motors_service_init();
}


void measuring_service_get_temperature_and_humidity(int16_t * h, int16_t * t){

    int16_t temperature = 0;
    int16_t humidity = 0;

    if(dht_read_data(sensor_type, dht_gpio, &humidity, &temperature) == SUCCESS_READING){
        *h = humidity;
        *t = temperature;
    }else{
        *h = -1;
        *t = -1;
    }

}


int8_t measuring_service_get_light_level(){

    return light_service_get_light_level();
}

float measuring_service_get_pressure(){

    return bmp280_service_get_pressure();
}


void measuring_service_get_joystick_readings(float * x, float * y){
    *x = joystick_service_get_reading_x();
    *y = joystick_service_get_reading_y();
}
