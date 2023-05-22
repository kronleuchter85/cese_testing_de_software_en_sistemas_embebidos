#include "unity.h"

#include "measuring_services.h"

#include "mock_dht11_service.h"
#include "mock_bmp280_service.h"
#include "mock_light_service.h"
#include "mock_joystick_service.h"
#include "mock_display_service.h"
#include "mock_motors_service.h"

void test_measuring_services_init(){

    //
    // checkeamos que se inicializan los diferentes sub modulos
    //
    
    dht11_service_init_Expect();
    bmp280_service_init_Expect();
    light_service_init_Expect();
    joystick_service_init_Expect();
    display_service_init_Expect();
    motors_service_init_Expect();

    measuring_services_init();
}


void test_get_measures_temperature_and_humidity(){

    int16_t temperature;
    int16_t humidity;

    int16_t expectedTemp = 22;
    int16_t expectedHumidity = 57;

    dht11_service_get_humidity_ExpectAndReturn(expectedHumidity);
    dht11_service_get_temperature_ExpectAndReturn(expectedTemp);

    measuring_service_get_temperature_and_humidity(&humidity , &temperature);

    TEST_ASSERT_EQUAL(expectedTemp , temperature);
    TEST_ASSERT_EQUAL(expectedHumidity , humidity);
    
}

void test_get_measures_light(){
    int8_t expectedLight;

    light_service_get_light_level_ExpectAndReturn(expectedLight);

    int8_t light = measuring_service_get_light_level();

    TEST_ASSERT_EQUAL(expectedLight , light);
}

void test_get_measures_pressure(){
    float expectedPressure;

    float pressure = measuring_service_get_pressure();

    TEST_ASSERT_EQUAL(expectedPressure , pressure);

}