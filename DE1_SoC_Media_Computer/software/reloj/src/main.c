/*
 * main.c
 *
 *  Created on: 9 de mar. de 2026
 *      Author: iioanno
 */

#include "system.h"
#include "keyCode.h"
#include "interval_timer_ISR.h"
#include "sys/alt_irq.h"
#include <stdio.h> //Necesario para el NULL

// INTERRUPCIONES CABECERAS
void interval_timer_isr();
void pushbutton_ISR();

// Tareas
void task_keyButtons(void);

// Parametros iniciales
volatile key_t key_pressed = KEY_NULL;

volatile timer_t timer_100ms;

volatile int pattern_low = 0;
volatile int pattern_high = 0;

volatile int flag_stopTimer = DISABLE;

int main(void)
{
	// configuramos e iniciamos timer
	volatile int *interval_timer_ptr = (int *)TIMER_BASE; // Direccion Temporizador

	volatile int *HEX2_HEX0_ptr = (int *)HEX2_HEX0_BASE; // Direccion HEX2_HEX0
	volatile int *HEX5_HEX3_ptr = (int *)HEX5_HEX3_BASE; // Direccion HEX5_HEX3

	volatile int *KEY_ptr = (int *)PUSHBUTTONS_BASE; // Direccion pulsadores KEY

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
		*(HEX2_HEX0_ptr) = pattern_low;	 // Visualiza el patron en HEX2 ... HEX0
		*(HEX5_HEX3_ptr) = pattern_high; // Visualiza el patron en HEX5 ... HEX3
		task_keyButtons();
		if (timer_100ms.flag_tick)
		{
			timer_100ms.flag_tick = 0;
			task_timerTick();
		}
		task_printTime_LCD();
	}

	return 0;
}

void task_keyButtons(void)
{
	switch (key_pressed)
	{
	case KEY0:
		/* detener o encender el temporizador*/
		flag_stopTimer = !flag_stopTimer;
		break;
	case KEY1:
		/* incrementar segundos */
		if (flag_stopTimer == ENABLE)
		{
			if (timer_100ms.segundos < max_seg)
				timer_100ms.segundos++;
			else
				timer_100ms.segundos = 0;
		}
		break;
	case KEY2:
		/* incrementar minutos*/
		if (flag_stopTimer == ENABLE)
		{
			if (timer_100ms.minutos < max_min)
				timer_100ms.minutos++;
			else
				timer_100ms.minutos = 0;
		}
		break;
	case KEY3:
		/* incrementar horas*/
		if (flag_stopTimer == ENABLE)
		{
			if (timer_100ms.horas < max_horas)
				timer_100ms.horas++;
			else
				timer_100ms.horas = 0;
		}
		break;
	default:
		break;
	}

	key_pressed = KEY_NULL;
}
