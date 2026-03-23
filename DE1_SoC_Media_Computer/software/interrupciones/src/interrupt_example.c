/*
 * Ejemplo de uso de las interrupciones
 * Ricardo J. Colom
 * Diciembre 2024
 */
#include "key_codes.h"	// define los valores para KEY1, KEY2, KEY3
#include "system.h"
#include "sys/alt_irq.h"
#include <stdio.h> //Necesario para el NULL

void interval_timer_isr( );
void pushbutton_ISR( );

volatile int key_pressed = KEY2;
volatile int pattern = 0x0000000F;	// patrón para display HEX

int main(void)
{
	volatile int * red_LED_ptr = (int *) RED_LEDS_BASE; 	// dirección diodos LED
	volatile int * interval_timer_ptr = (int *) TIMER_BASE;	// Dirección Temporizador
	volatile int * KEY_ptr = (int *) PUSHBUTTONS_BASE;		// Dirección pulsadores KEY
	volatile int * SW_switch_ptr = (int *) SWITCHES_BASE; 	// dirección interruptores SW
	volatile int * HEX2_HEX0_ptr	= (int *) HEX2_HEX0_BASE;	// Dirección HEX2_HEX0
	volatile int * HEX5_HEX3_ptr	= (int *) HEX5_HEX3_BASE;	// Dirección HEX5_HEX3

	int counter = 0x989680;				// 1/(100 MHz) x (0x4c4b40) = 50 msec
	*(interval_timer_ptr + 0x2) = (counter & 0xFFFF);
	*(interval_timer_ptr + 0x3) = (counter >> 16) & 0xFFFF;

	/* comienza el timer y habilita las interrupciones */
	*(interval_timer_ptr + 1) = 0x7;	// STOP = 0, START = 1, CONT = 1, ITO = 1 
	alt_irq_register(TIMER_IRQ, NULL, interval_timer_isr);
	
	*(KEY_ptr + 2) = 0xE; 		/* Mascara de los pulsadores (bit 0 inhabilitado) */
	*(KEY_ptr + 3) = 0;
	alt_irq_register(PUSHBUTTONS_IRQ, NULL, pushbutton_ISR);

	int SW_value;

	printf("Interrupciones OK!\n");

	while(1){
		SW_value = *(SW_switch_ptr); 			// leer el valor de los interruptores SW
		*(red_LED_ptr) = SW_value; 				// encender los diodos LED
		*(HEX2_HEX0_ptr) = pattern;				// Visualiza el patrón en HEX2 ... HEX0
		*(HEX5_HEX3_ptr) = pattern;				// Visualiza el patrón en HEX5 ... HEX3
	}
}
