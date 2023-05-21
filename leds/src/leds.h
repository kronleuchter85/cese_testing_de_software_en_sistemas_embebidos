
#ifndef LEDS_H
#define LEDS_H

#include "stdint.h"


void leds_initialize(uint16_t * d);

void leds_set_on(uint8_t l);

void leds_set_off(uint8_t l);

void leds_set_on_all(void);

void leds_set_off_all(void);

#endif