#include <stdio.h>
#include <stdlib.h>

void print_alpha();

void main()
{
	print_alpha();
}

void print_alpha()
{

	char a = 'A';
	char *ptr = &a;
	while (a != 'Z' + 1)
	{
		printf("%c,\t", *ptr);
		a++;
	}
}
