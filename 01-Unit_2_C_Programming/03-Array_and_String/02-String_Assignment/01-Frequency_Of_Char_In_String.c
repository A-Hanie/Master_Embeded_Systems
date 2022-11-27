/*
 * @file: 01-Multidimensional_Array.c
 * @author:	Ahmed Hanie
 */
#include "stdio.h"
#include "string.h"

void main(void)
{
	char str[50], index = 0, freq = 0;
	char wanted_char;

	printf("Enter a string : \n");
	gets(str);

	printf("Enter a char to find frequency : ");
	scanf("%c", &wanted_char);

	while (str[index] != 0)
	{
		if (wanted_char == str[index])
		{
			freq++;
		}
		else
		{
		}
		index++;
	}
	printf("frequency of %c = %d ", wanted_char, freq);
}