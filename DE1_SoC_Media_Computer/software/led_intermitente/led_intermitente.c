/*
 * led_intermitente.c
 *
 *  Created on: 2 de mar. de 2026
 *      Author: iioanno
 */
#include <stdio.h>
#include "system.h"
#include <io.h>
int main()
{
printf("Hola desde Nios II!\n");
int count = 0;
int delay;
while(1)
{
IOWR(RED_LEDS_BASE, 0x0, count & 0x01);
delay = 0;
while(delay<2000000)
{
delay++;
}
count++;
}
return 0;
}

 /*MODIFICACION PREGUNTA
#include <stdio.h>
#include "system.h"

int main()
{
volatile int *leds =(volatile int*) RED_LEDS_BASE;

printf("Hola desde Nios II!\n");
int count = 0;
int delay;

while(1)
{
*leds = count&0x01;
delay = 0;
while(delay<2000000)
{
delay++;
}
count++;
}
return 0;
}

*/

