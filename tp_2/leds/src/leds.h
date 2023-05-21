
#ifndef LEDS_H
#define LEDS_H

#include "stdint.h"


void leds_initialize(uint16_t * d);

void leds_set_on(uint8_t l, uint8_t * error);

void leds_set_off(uint8_t l, uint8_t * error);

void leds_set_on_all(void);

void leds_set_off_all(void);

//
// esta funcion devuelve el estado de un determinado led
// posibles valores de entrada: led [1-16]
// posibles valores de salida: status [0 , 1]
//
uint8_t leds_get(uint8_t , uint8_t * error);

#endif