#include "leds.h"

#define INDEX_OFFSET    1
#define FIRST_BIT       1
#define ALL_LEDS_OFF    0x0000

uint16_t indexToMask(uint8_t led){
    return (FIRST_BIT << (led - INDEX_OFFSET));
}

static uint16_t * _direccion;

void leds_initialize(uint16_t * d){
    *d = ALL_LEDS_OFF;
    _direccion = d;
}


void leds_set_on(uint8_t led){
    *_direccion |= indexToMask(led);
}



void leds_set_off(uint8_t led){
    *_direccion &= ~indexToMask(led);
}



void leds_set_on_all(void){
    *_direccion |= 0xffff;
}



void leds_set_off_all(void){
    *_direccion &= 0x0000;
}

//
// esta funcion devuelve el estado de un determinado led
// posibles valores de entrada: led [1-16]
// posibles valores de salida: status [0 , 1]
//
uint8_t leds_get(uint8_t nLed){

    // hacemos una conjuncion entre el valor de la mascara del led seleccionado y el estado de los leds, 
    // de forma tal que todos los demas leds estaran en cero y se obtendra el estado del led seleccionado.
    uint16_t leds = *_direccion & indexToMask(nLed);
 
    // si el valor es distinto de cero entonces esta encendido
    // de lo contrario esta apagado.
    if(leds){
        return 1;
    }else{
        return 0;
    }
}