#include "stdint.h"
#include "unity.h"
#include "leds.h"

//
// - Al inciarlizar la biblioteca todos los leds quedan apagados.
// - Con todos los leds apagados, prendo el led 2, verifico que se el bit 1 vale 1.
// - Con el led 2 prendido, apago el led 2, verifico que se enciende el bit 1 vale 0.
// - Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7, deberían quedar el bit 4 en 1 y el resto en 0
// - Prendo un led, consulto el estado y tiene que estar prendido.
// - Apago un led, consulto el estado y tiene que estar apagado.
// - Con todos los leds apagados, prendo todos los leds y verifico que se encienden.
// - Con todos los leds prendidor, apagado todos los leds y verifico que se apagan.
// - Revisar los valores limites de los argumentos.
// - Revisar que pasa con valores erroneos en los argumento.
//


static uint16_t puerto_virtual = 0xffff;

void setUp(void){

    leds_initialize(&puerto_virtual);
}

//
// - Al inciarlizar la biblioteca todos los leds quedan apagados.
//
void test_todos_los_leds_inician_apagados(void){
    
    uint16_t puerto_virtual = 0xffff;
    leds_initialize(&puerto_virtual);

    //
    // para checkear que los leds esten apagados 
    //
    TEST_ASSERT_EQUAL(0x0000 , puerto_virtual);
}

//
// - Con todos los leds apagados, prendo el led 2, verifico que se el bit 1 vale 1.
//
void test_prender_un_led(void){

    uint8_t error;
    leds_set_on(2 , &error);
    TEST_ASSERT_EQUAL(0x0002 , puerto_virtual);
}

//
// - Con el led 2 prendido, apago el led 2, verifico que se enciende el bit 1 vale 0.
//
void test_prender_y_apagar_un_led(void){
     
    uint8_t error;
    leds_set_on(2 , &error);
    leds_set_off(2 , &error);
    TEST_ASSERT_EQUAL(0x0000 , puerto_virtual);
}

// - Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7, deberían quedar el bit 4 en 1 y el resto en 0
void test_prender_y_apagar_varios_leds(void){
    
    uint8_t error;
    leds_set_on(3 , &error);
    leds_set_on(5 , &error);
    leds_set_off(3 , &error);
    leds_set_off(7 , &error);
    TEST_ASSERT_EQUAL(0x0010 , puerto_virtual);
}

// prendemos todos los leds juntoss
void test_prender_todos_los_leds(void){
    
    leds_set_on_all();
    TEST_ASSERT_EQUAL(0xffff , puerto_virtual);
}

void test_apagar_todos_los_leds(void){
   
    leds_set_off_all();
    TEST_ASSERT_EQUAL(0x0000 , puerto_virtual);
}

// dado el numero de un led se debe devolver su estado
void test_consultar_estado_leds_apagado(void){
    uint8_t error;
    TEST_ASSERT_EQUAL(0 , leds_is_on(5 , &error));
}

// dado el numero de un led se debe devolver su estado
void test_consultar_estado_leds_encendido(void){

    uint8_t error;
    leds_set_on(5 , &error);
    TEST_ASSERT_EQUAL(1 , leds_is_on(5 , &error));
}

// checkeamos que los parametros para set_on se encuentren en los limites
void test_parametros_fuera_de_limite_set_on(void){

    uint8_t error = 0;
    leds_set_on(0 , &error);
    TEST_ASSERT_EQUAL(1 , error);
    error = 0;
    leds_set_on(17 , &error);
    TEST_ASSERT_EQUAL(1 , error);
}

// checkeamos que los parametros para set_off se encuentren en los limites
void test_parametros_fuera_de_limite_set_off(void){

    uint8_t error = 0;
    leds_set_off(0 , &error);
    TEST_ASSERT_EQUAL(1 , error);
    error = 0;
    leds_set_off(17 , &error);
    TEST_ASSERT_EQUAL(1 , error);
}

// checkeamos que los parametros para led_get se encuentren en los limites
void test_parametros_fuera_de_limite_led_get(void){

    uint8_t error = 0;
    leds_is_on(0 , &error);
    TEST_ASSERT_EQUAL(1 , error);
    error = 0;
    leds_is_on(17 , &error);
    TEST_ASSERT_EQUAL(1 , error);
}