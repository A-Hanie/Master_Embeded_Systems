/*
 * @file: 02-Length_Of_String.c
 * @author:	Ahmed Hanie
 */

#include <stdio.h>
void main(void)
{
    char str[50];
	unsigned int index=0;

	printf("Enter a string : \n");
	gets(str);

    while (str[index] != 0)
	{
		index++;
	}

	printf("Length of string : %d", index);

}