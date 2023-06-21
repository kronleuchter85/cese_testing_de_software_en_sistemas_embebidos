#include "unity.h"

#include "measuring_services.h"
#include "mock_bmp280_service.h"
#include "mock_light_service.h"
#include "mock_joystick_service.h"
#include "mock_display_service.h"
#include "mock_motors_service.h"

#include "mock_dht.h"

void test_measuring_services_init(){

    //
    // checkeamos que se inicializan los diferentes sub modulos
    //
    bmp280_service_init_Expect();
    light_service_init_Expect();
    joystick_service_init_Expect();
    display_service_init_Expect();
    motors_service_init_Expect();
    measuring_services_init();
}


void test_get_measures_temperature_and_humidity_successfully(){

    int16_t temperature = 0;
    int16_t humidity = 0;
    gpio_num_t dht_gpio = 2;
    dht_sensor_type_t sensor_type = DHT_TYPE_DHT11;
 
    int16_t expected_temperature = 5;
    int16_t expected_humidity = 4;

    dht_read_data_ExpectAndReturn(sensor_type ,dht_gpio , &humidity , &temperature, SUCCESS_READING);
    dht_read_data_ReturnThruPtr_humidity(&expected_humidity);
    dht_read_data_ReturnThruPtr_temperature(&expected_temperature);

    measuring_service_get_temperature_and_humidity(&humidity , &temperature);
  
    TEST_ASSERT_EQUAL(expected_temperature , temperature);
    TEST_ASSERT_EQUAL(expected_humidity , humidity);
}

void test_get_measures_temperature_and_humidity_with_errors(){

    int16_t temperature = 0;
    int16_t humidity = 0;
    gpio_num_t dht_gpio = 2;
    dht_sensor_type_t sensor_type = DHT_TYPE_DHT11;
 
    int16_t read_temperature = 5;
    int16_t read_humidity = 4;

    dht_read_data_ExpectAndReturn(sensor_type ,dht_gpio , &humidity , &temperature, ERROR_READING);
    dht_read_data_ReturnThruPtr_humidity(&read_temperature);
    dht_read_data_ReturnThruPtr_temperature(&read_humidity);

    measuring_service_get_temperature_and_humidity(&humidity , &temperature);
  
    //
    // quiero ver que como la lectura es erronea no se van a recibir los valores leidos sino
    // el codigo de error esperado
    //
    TEST_ASSERT_EQUAL(-1 , temperature);
    TEST_ASSERT_EQUAL(-1 , humidity);
}


// void test_get_measures_light(){
 
//     int8_t expectedLight = 20;
//     light_service_get_light_level_ExpectAndReturn(expectedLight);
//     int8_t light = measuring_service_get_light_level();
//     TEST_ASSERT_EQUAL(expectedLight , light);
// }

void test_get_measures_pressure(){
  
    float expectedPressure = 200.5;
    bmp280_service_get_pressure_ExpectAndReturn(expectedPressure);
    float pressure = measuring_service_get_pressure();
    TEST_ASSERT_EQUAL(expectedPressure , pressure);

}

void test_get_values_joystick(){
   
    float expected_x = -100.0;
    float expected_y = 200.0;
    joystick_service_get_reading_x_ExpectAndReturn(expected_x);
    joystick_service_get_reading_y_ExpectAndReturn(expected_y);
    float value_x , value_y;
    measuring_service_get_joystick_readings(&value_x , &value_y);
    TEST_ASSERT_EQUAL(expected_x , value_x);
    TEST_ASSERT_EQUAL(expected_y , value_y);
}