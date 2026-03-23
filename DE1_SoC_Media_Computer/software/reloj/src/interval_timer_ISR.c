/*
 * interval_timer_ISR.c
 *
 *  Created on: 9 de mar. de 2026
 *      Author: iioanno
 */

#include "system.h"
#include "interval_timer_ISR.h"
#include "sys/alt_irq.h"
#include "keyCode.h"

extern volatile timer_t timer_100ms = {0};

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

extern volatile int flag_stopTimer;

void interval_timer_isr()
{
	volatile int *interval_timer_ptr = (int *)TIMER_BASE;
	*(interval_timer_ptr) = 0; // Borra la interrupcion
	timer_100ms.flag_tick = 1;
}

void task_timerTick(timer_t *timer)
{
	if (!flag_stopTimer)
	{
		timer->tick++;
		if (timer->tick >= tick_100ms)
		{
			timer->tick = 0;
			timer->segundos++;
			if (timer->segundos >= (max_seg + 1))
			{
				timer->segundos = 0;
				timer->minutos++;
				if (timer->minutos >= (max_min + 1))
				{
					timer->minutos = 0;
					timer->horas++;
					if (timer->horas >= (max_horas + 1))
						timer->horas = 0;
				}
			}
		}
	}
}

void task_printTime_LCD(timer_t *timer)
{
	// descomponer cada digito para visualizacion
	h_d = timer->horas / 10;
	h_u = timer->horas % 10;

	m_d = timer->minutos / 10;
	m_u = timer->minutos % 10;

	s_d = timer->segundos / 10;
	s_u = timer->segundos % 10;

	// dividir en parte alta y baja
	pattern_low = (seg7[m_u] << 16) | (seg7[s_d] << 8) | seg7[s_u];
	pattern_high = (seg7[h_d] << 16) | (seg7[h_u] << 8) | seg7[m_d];
	return;
}
