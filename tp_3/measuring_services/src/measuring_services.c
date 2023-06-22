#include "measuring_services.h"
#include "bmp280_service.h"
#include "light_service.h"
#include "joystick_service.h"
#include "display_service.h"
#include "motors_service.h"

#include "dht.h"
#include "bmp280.h"


//
// DHT11 consts
//

static const gpio_num_t dht_gpio = 2;
static const dht_sensor_type_t sensor_type = DHT_TYPE_DHT11;

//
// BMP280
//
bmp280_params_t params;
bmp280_t dev;

int8_t measuring_services_init(void){

    //
    // inicializacion de modulos
    //

    if(bmp280_init_default_params(&params) != SUCCESS_READING){
        return -1;
    }
    if(bmp280_init_desc(&dev, BMP280_I2C_ADDRESS_0, 0, I2C_MOCKED_PORT_SDA, I2C_MOCKED_PORT_SCL) != SUCCESS_READING ){
        return -1;
    }
    if(bmp280_init(&dev, &params)!= SUCCESS_READING){
        return -1;
    }

    return 0;
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

void measuring_service_get_pressure( float * p,float * t,float * h){

    float pressure =0, temperature =0, humidity =0;

    if(bmp280_read_float(&dev, &temperature, &pressure, &humidity) == SUCCESS_READING){
        *h = humidity;
        *t = temperature;
        *p = pressure;
    }else{
        *h = -1;
        *t = -1;
        *p = -1;
    }
}

