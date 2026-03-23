/*
 * interval_timer_ISR.c
 *
 *  Created on: 9 de mar. de 2026
 *      Author: iioanno
 */

// #include "key_codes.h" 	// define los valores de KEY1, KEY2, KEY3
#include "system.h"
#include "keyCode.h"
#include "sys/alt_irq.h"

// extern variables
extern volatile int ticks;
extern volatile int segundos;
extern volatile int minutos;
extern volatile int horas;

volatile int h_d = 0;
volatile int h_u = 0;
volatile int m_d = 0;
volatile int m_u = 0;
volatile int s_d = 0;
volatile int s_u = 0;

extern volatile int pattern_low;
extern volatile int pattern_high;

static const unsigned char seg7[10] = {
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F  // 9
};

extern int flag_stopTimer;

void interval_timer_isr()
{
	volatile int *interval_timer_ptr = (int *)TIMER_BASE;
	*(interval_timer_ptr) = 0; // Borra la interrupcion

	ticks++;
	if (flag_stopTimer == DISABLE)
	{
		if (ticks >= tick_1s)
		{
			ticks = 0;
			segundos++;
			if (segundos >= 60)
			{
				segundos = 0;
				minutos++;
				if (minutos >= 60)
				{
					minutos = 0;
					horas++;
					if (horas >= 24)
					{
						horas = 0;
					}
				}
			}
		}
	}
	// descomponer cada digito para visualizacion
	h_d = horas / 10;
	h_u = horas % 10;

	m_d = minutos / 10;
	m_u = minutos % 10;

	s_d = segundos / 10;
	s_u = segundos % 10;

	// dividir en parte alta y baja
	pattern_low = (seg7[m_u] << 16) | (seg7[s_d] << 8) | seg7[s_u];
	pattern_high = (seg7[h_d] << 16) | (seg7[h_u] << 8) | seg7[m_d];
	return;
}
