#include "uart.h"
#include "Platform_Types.h"

uint8_t string_buffer[100] = "Zelda"; 

void main(void)
{
	vUart_Send_string(string_buffer);
}
