/*
 * @file: 02-Factorial.c
 * @author:	Ahmed Hanie
 */

#include <stdio.h>

int factorial(unsigned int num);

void main(void)
{

    unsigned int number;

    printf("Enter an positive integer : ");
    scanf("%d", &number);

    printf("Factorial of %d = %d", number, factorial(number));
}

int factorial(unsigned int num)
{
    if (0 == num)
    {
        return 1;
    }
    else

        return num * factorial(num - 1);
}
