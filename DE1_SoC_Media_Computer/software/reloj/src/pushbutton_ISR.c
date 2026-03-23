/*
 * pushbutton_ISR.c
 *
 *  Created on: 22 de mar. de 2026
 *      Author: Ioanna
 */

#include "system.h"
#include "keyCode.h"
#include "sys/alt_irq.h"

extern volatile int segundos;
extern volatile int minutos;
extern volatile int horas;

extern volatile int key_pressed;

void pushbutton_ISR()
{
	volatile int *KEY_ptr = (int *)PUSHBUTTONS_BASE;
	unsigned int press;
	press = *(KEY_ptr + 3); // lee que boton se ha pulsado
	*(KEY_ptr + 3) = 0;		// borra la interrupcion

	if (press == 0) // en caso de no pulsar ningun boton.
	{
		key_pressed = -1;
	}
	else if ((press & (press - 1))) // en caso de que haya mas de un boton pulsado.
	{
		key_pressed = -1;
	}
	else if (press & (1 << KEY3))
	{
		key_pressed = KEY3;
	}
	else if (press & (1 << KEY2))
	{
		key_pressed = KEY2;
	}
	else if (press & (1 << KEY1))
	{
		key_pressed = KEY1;
	}
	else if (press & (1 << KEY0))
	{
		key_pressed = KEY0;
	}

	while (*KEY_ptr)
	{
	};

	return;
}
