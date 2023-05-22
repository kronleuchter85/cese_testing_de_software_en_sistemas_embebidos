#include "unity.h"

#include "measuring_services.h"
#include "mock_dht11_service.h"


void test_measuring_services_init(){

    //
    // checkeamos que se inicializan los diferentes sub modulos
    //
    
    dht11_service_init_Expect();
    bmp280_service_init_Expect();

    measuring_services_init();


}
