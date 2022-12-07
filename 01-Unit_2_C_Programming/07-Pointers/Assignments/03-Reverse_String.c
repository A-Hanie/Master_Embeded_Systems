#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char str[15] = {0};
	char *ptr;
	int __;

	printf("Input a string : ");
	gets(str);

	ptr = str + strlen(str);

	printf("\nReversed string is: ");

	for (__ = strlen(str); __ >= 0; __--)
	{
		printf("%c", *ptr--);
	}
}