/*
 * pushbutton_ISR.c
 *
 *  Created on: 22 de mar. de 2026
 *      Author: Ioanna
 */

#include "system.h"
#include "sys/alt_irq.h"

extern volatile int segundos;
extern volatile int minutos;
extern volatile int horas;
extern volatile int modo_ajuste;

void pushbutton_ISR()
{
	volatile int *KEY_ptr = (int *)PUSHBUTTONS_BASE;
	int press;

	press = *(KEY_ptr + 3); // lee que boton se ha pulsado
	*(KEY_ptr + 3) = 0;		// borra la interrupci�n

	if (press & 0x1)
	{ // KEY0->activar/desactivar modo ajuste
		modo_ajuste = !modo_ajuste;
	}

	if (modo_ajuste)
	{
		if (press & 0x2)
		{ // KEY1->resetea segundos a 0
			segundos = 0;
		}
		if (press & 0x4)
		{ // KEY2 ->aumentar minutos
			minutos++;
			if (minutos >= 60)
				minutos = 0;
		}
		if (press & 0x8)
		{ // KEY3->aumentar horas
			horas++;
			if (horas >= 24)
				horas = 0;
		}
	}
	while (*KEY_ptr)
		; // esperar a que se suelte el pulsador KEY

	return;
}
