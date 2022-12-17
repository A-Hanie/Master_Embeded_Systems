#include "LIFO.h"
#include "stdio.h"
#include "stdlib.h"


#define LIFO_buffer_length 5


unsigned int buf[LIFO_buffer_length] , temp ;
LIFO_t LIFO_UART;                     

int main()
{
	LIFO_INIT( &LIFO_UART , buf , LIFO_buffer_length );

	for( int i=0 ; i<5 ; i++ )
	{
		LIFO_PUSH( &LIFO_UART , i );
		printf ("LIFO_PUSH: %d\n",i);
	}

	printf ("LIFO Uart Buffer: \n");
	for( int i=0 ; i<5 ; i++ )
	{
		LIFO_POP( &LIFO_UART , &temp );

		printf ("LIFO_POP: %d\n",temp);
	}
}
