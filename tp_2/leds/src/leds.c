#include "leds.h"

#define INDEX_OFFSET            1
#define FIRST_BIT               1
#define ALL_LEDS_OFF            0x0000
#define ALL_LEDS_ON             0xffff
#define OUTPUT_ERROR_STATUS     1

uint16_t indexToMask(uint8_t led){
    return (FIRST_BIT << (led - INDEX_OFFSET));
}

static uint16_t * direccion ;

int validate_range(uint8_t led , uint8_t * error){
    if(led >16 || led <1){
        *error = OUTPUT_ERROR_STATUS;
        return OUTPUT_ERROR_STATUS;
    }
    return 0;
}


void leds_initialize(uint16_t * d){
    *d = ALL_LEDS_OFF;
    direccion = d;
}

void leds_set_on(uint8_t led , uint8_t * error){
    if( validate_range(led,error))
        return;
    *direccion |= indexToMask(led);
}

void leds_set_off(uint8_t led , uint8_t * error){
    if( validate_range(led,error))
        return;
    *direccion &= ~indexToMask(led);
}

void leds_set_on_all(void){
    *direccion = ALL_LEDS_ON;
}

void leds_set_off_all(void){
    *direccion = ALL_LEDS_OFF;
}

//
// esta funcion devuelve el estado de un determinado led
// posibles valores de entrada: led [1-16]
// posibles valores de salida: status [0 , 1]
//
uint8_t leds_is_on(uint8_t nLed , uint8_t * error ){
    
   if( validate_range(nLed,error))
        return;

    // hacemos una conjuncion entre el valor de la mascara del led seleccionado y el estado de los leds, 
    // de forma tal que todos los demas leds estaran en cero y se obtendra el estado del led seleccionado.
    uint16_t leds = *direccion & indexToMask(nLed);
    
    // si el valor es distinto de cero entonces esta encendido
    // de lo contrario esta apagado.
    if(leds){
        return 1;
    }else{
        return 0;
    }
}