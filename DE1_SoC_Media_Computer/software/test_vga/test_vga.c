/* Ejemplo de uso de los puertos paralelos y VGA
 * Este programa realiza lo siguiente:
 * 1. Visualiza el valor de los interruptores SW en los LEDs
 * 2. Visualiza un patrón que va girando en los displays 7-segmentos HEX
 * 3. Al pulsar los KEY[3..1], el valor de los interruptores SW se toma como patrón
 * 4. Escribe un mensaje en el centro de la pantalla VGA
*/

#include "system.h"
#include <stdio.h>

#define VIDEO_SDRAM_BASE 0x03e00000

/* funciones */
void VGA_text (int, int, char *);
void VGA_box (int, int, int, int, short);

enum color{
	Negro,
	Azul,
	Verde,
	Cian,
	Rojo,
	Magenta,
	Amarillo,
	Blanco
};


int main(void)
{
	/* Declarar los punteros a registros de I/O como volatile (volatile significa que
 	* que tanto las instrucciones de lectura como las de escritura se pueden utilizar
 	* para acceder a estas posiciones en lugar de realizar accesos a memoria
	*/
	volatile int * red_LED_ptr = (int *) RED_LEDS_BASE; 	// dirección LED
	volatile int * HEX2_HEX0_ptr = (int *) HEX2_HEX0_BASE; 	// dirección HEX2_HEX0
	volatile int * HEX5_HEX3_ptr = (int *) HEX5_HEX3_BASE; 	// dirección HEX5_HEX3
	volatile int * SW_switch_ptr = (int *) SWITCHES_BASE; 	// dirección SW
	volatile int * KEY_ptr = (int *) PUSHBUTTONS_BASE; 		// dirección pulsadores KEY

	int HEX_bits = 0x0000000F; 								// patrón para los display HEX
	int SW_value, KEY_value, delay_count;
	int SW_sel = 0;

	printf("Hola desde Nios II!\n");

	/* mensaje a visualizar en la VGA */
	char text_top_row[40] = "Altera DE1-SoC\0";
	char text_bottom_row[40] = "Media Computer\0";

	/* crea el texto en medio del monitor VGA */
	VGA_text (32, 28, text_top_row);
	VGA_text (32, 29, text_bottom_row);
	VGA_box (0, 0, 80*4-1, 60*4-1, 0x0000); // Pinta de Negro toda la pantalla
	VGA_box (31*4, 27*4, 47*4, 31*4, 0x001F); //Dibuja un cuadro azul en el centro

	while(1)
	{
		SW_value = *(SW_switch_ptr); 						// leer el valor de los interruptores SW
		SW_sel = 0x07 & SW_value;
		*(red_LED_ptr) = SW_value; 							// encender los LED
		KEY_value = *(KEY_ptr); 							// leer el valor de los pulsadores KEY
		if (KEY_value != 0)									// mirar si se ha pulsado algún KEY
		{
			HEX_bits = SW_value;							// establecer el patrón con el valor de SW
			while (*KEY_ptr);								// esperar a que se suelte el pulsador KEY
		}
		*(HEX2_HEX0_ptr) = HEX_bits;						// visualizar patrón en HEX2 ... HEX0
		*(HEX5_HEX3_ptr) = HEX_bits;						// visualizar patrón en HEX5 ... HEX3

		/* girar el patrón mostrado en los displays HEX */
		if (HEX_bits & 0x800000)
			HEX_bits = (HEX_bits << 1) | 1;
		else
			HEX_bits = HEX_bits << 1;
		switch (SW_sel){
		case Negro:
			VGA_box (31*4, 27*4, 47*4, 31*4, 0x0000);
					break;
		case Azul:
			VGA_box (31*4, 27*4, 47*4, 31*4, 0x001F);
					break;
		case Verde:
			VGA_box (31*4, 27*4, 47*4, 31*4, 0x07E0); //Dibuja un cuadro azul en el centro
					break;
		case Cian:
			VGA_box (31*4, 27*4, 47*4, 31*4, 0x07FF); //Dibuja un cuadro azul en el centro
					break;
		case Rojo:
			VGA_box (31*4, 27*4, 47*4, 31*4, 0xF800); //Dibuja un cuadro azul en el centro
					break;
		case Magenta:
			VGA_box (31*4, 27*4, 47*4, 31*4, 0xF81F); //Dibuja un cuadro azul en el centro
					break;
		case Amarillo:
			VGA_box (31*4, 27*4, 47*4, 31*4, 0xFFE0); //Dibuja un cuadro azul en el centro
					break;
		case Blanco:
			VGA_box (31*4, 27*4, 47*4, 31*4, 0xFFFF); //Dibuja un cuadro azul en el centro
					break;
		default: VGA_box (31*4, 27*4, 47*4, 31*4, 0x001F); //azul
		}

		for (delay_count = 200000; delay_count != 0; --delay_count); 	//retardo
	}
}


/****************************************************************************************
 * Subrutina para enviar una cadena de texto a la pantalla VGA
****************************************************************************************/
void VGA_text(int x, int y, char * text_ptr)
{
	int offset;
  	volatile char * character_buffer = (char *)  VIDEO_CHAR_BUFFER_AVALON_CHAR_BUFFER_SLAVE_BASE;	// VGA character buffer

  	/* asume que la cadena de texto comienza en la primera fila */
	offset = (y << 7) + x;
	while ( *(text_ptr) )
	{
		*(character_buffer + offset) = *(text_ptr);	// escribe en el buffer
		++text_ptr;
		++offset;
	}
}

/****************************************************************************************
 * Dibujar un rectangulo en la pantalla VGA
****************************************************************************************/
void VGA_box(int x1, int y1, int x2, int y2, short pixel_color)
{
	int offset, row, col;
	int SDRAM_BASE_SIN_CACHE = (SDRAM_BASE + VIDEO_SDRAM_BASE + NIOS2_DCACHE_BYPASS_MASK);
  	volatile short * pixel_buffer = (short *) SDRAM_BASE_SIN_CACHE;	// VGA pixel buffer

  	/* se asume que las coordenadas del rectangulo son correctas */
	for (row = y1; row <= y2; row++)
	{
		col = x1;
		while (col <= x2)
		{
			offset = (row << 9) + col;
			*(pixel_buffer + offset) = pixel_color;	//procesa mitad direcciones
			++col;
		}
	}
}




