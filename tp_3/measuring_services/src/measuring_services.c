#include "measuring_services.h"
#include "dht11_service.h"
#include "bmp280_service.h"

void measuring_services_init(void){

    //
    // inicializacion de modulos
    //
    dht11_service_init();

    bmp280_service_init();

}