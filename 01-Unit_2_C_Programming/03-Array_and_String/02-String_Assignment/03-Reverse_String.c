/*
 * @file: 03-Reverse_String.c
 * @author:	Ahmed Hanie
 * @brief:
 */

#include <stdio.h>
#include "string.h"

void main(void)
{
	char str[50];
	int index, len;

	printf("Enter a string : ");
	gets(str);

    len =  strlen(str);
	for (index = 0; index < len/2 ; index++)
	{
        /* Swap str[index] and str[len-index]*/
        str[index] = str[index] ^ str[len-index-1] ;
        str[len-index-1] = str[index] ^ str[len-index-1] ;
        str[index] = str[index] ^ str[len-index-1] ;
	}

	printf("Reverse string is : %s", str);
}