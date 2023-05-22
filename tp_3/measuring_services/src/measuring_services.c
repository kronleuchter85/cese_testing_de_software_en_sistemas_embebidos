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