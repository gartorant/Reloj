/*
 * main.c
 *
 *  Created on: 9 de mar. de 2026
 *      Author: iioanno
 */

#include "system.h"
#include "keyCode.h"
#include "sys/alt_irq.h"
#include <stdio.h> //Necesario para el NULL

// INTERRUPCIONES CABECERAS
void interval_timer_isr();
void pushbutton_ISR();

// Parametros iniciales
volatile int key_pressed = KEY2;

volatile int ticks = 0;
volatile int segundos = 0;
volatile int minutos = 0;
volatile int horas = 0;

volatile int pattern_low = 0;
volatile int pattern_high = 0;

int main(void)
{
	// configuramos e iniciamos timer
	volatile int *interval_timer_ptr = (int *)TIMER_BASE; // Direcci�n Temporizador

	volatile int *HEX2_HEX0_ptr = (int *)HEX2_HEX0_BASE; // Direcci�n HEX2_HEX0
	volatile int *HEX5_HEX3_ptr = (int *)HEX5_HEX3_BASE; // Direcci�n HEX5_HEX3

	volatile int *KEY_ptr = (int *)PUSHBUTTONS_BASE; // Direcci�n pulsadores KEY

	int counter = 0x989680; // interrupt cada 100ms
	*(interval_timer_ptr + 0x2) = (counter & 0xFFFF);
	*(interval_timer_ptr + 0x3) = (counter >> 16) & 0xFFFF;

	/* comienza el timer y habilita las interrupciones */
	*(interval_timer_ptr + 1) = 0x7; // STOP = 0, START = 1, CONT = 1, ITO = 1
	alt_irq_register(TIMER_IRQ, NULL, interval_timer_isr);

	*(KEY_ptr + 2) = 0xF; /* Mascara de los pulsadores (KEY3, KEY2, KEY1, KEY0 ACTIVOS) */
	*(KEY_ptr + 3) = 0;
	alt_irq_register(PUSHBUTTONS_IRQ, NULL, pushbutton_ISR);

	while (1)
	{
		*(HEX2_HEX0_ptr) = pattern_low;	 // Visualiza el patr�n en HEX2 ... HEX0
		*(HEX5_HEX3_ptr) = pattern_high; // Visualiza el patr�n en HEX5 ... HEX3
	}

	return 0;
}
