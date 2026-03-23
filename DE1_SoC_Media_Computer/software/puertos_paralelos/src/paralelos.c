/* Ejemplo de uso de los puertos paralelos
 * Este programa realiza lo siguiente:
 * 1. Visualiza el valor de los interruptores SW en los LED
 * 2. Visualiza un patrón que va girando en los displays 7-segmentos HEX
 * 3. Al pulsar los KEY[3..1], el valor de los interruptores SW se toma como patrón
*/

#include "system.h"
#include <stdio.h> //Necesario para el NULL

int main(void)
{
	/* Declarar los punteros a registros de I/O como volatile (volatile significa que
 	* que tanto las instrucciones de lectura como las de escritura se pueden utilizar
 	* para acceder a estas posiciones en lugar de realizar accesos a memoria
	*/
	volatile int * red_LED_ptr = (int *) RED_LEDS_BASE; 		// dirección LED rojos
	volatile int * HEX2_HEX0_ptr = (int *) HEX2_HEX0_BASE; 	// dirección HEX2_HEX0
	volatile int * HEX5_HEX3_ptr = (int *) HEX5_HEX3_BASE; 	// dirección HEX5_HEX3
	volatile int * SW_switch_ptr = (int *) SWITCHES_BASE; 	// dirección SW
	volatile int * KEY_ptr = (int *) PUSHBUTTONS_BASE; 		// dirección pulsadores KEY

	int HEX_bits = 0x0000000F; 								// patrón para los display HEX
	int SW_value, KEY_value, delay_count;

	//todos los sw abajo y se pulsa key 3-> se apaga el patron y si subes un sw y lo vuelves a pulsar vuelve a empezar
	printf("Hola desde Nios II\n");

	while(1)
	{
		SW_value = *(SW_switch_ptr); 						// leer el valor de los interruptores SW
		*(red_LED_ptr) = SW_value; 							// encender los LED rojos
		KEY_value = *(KEY_ptr);								// leer el valor de los pulsadores KEY
		if (KEY_value != 0)									// mirar si se ha pulsado algún KEY
		{
			HEX_bits = SW_value;							// establecer el patrón con el valor de SW
			while (*KEY_ptr);								// esperar a que se suelte el pulsador KEY
		}
		*(HEX2_HEX0_ptr) = HEX_bits;						// visualizar patrón en HEX2 ... HEX0
		*(HEX5_HEX3_ptr) = HEX_bits;						// visualizar patrón en HEX5 ... HEX3

		/* girar el patrón mostrado en los displays HEX */
		if (HEX_bits & 0x800000)
			HEX_bits = (HEX_bits << 1) | 1; //desplaza a la izq y mete un 1 por la derecha
		else
			HEX_bits = HEX_bits << 1;

		for (delay_count = 200000; delay_count != 0; --delay_count); 	//retardo
	}
}
