/*
 * @file: 07-Factorial_Of_Number.c
 * @author:	Ahmed Hanie
 * @brief:
 *
 * EX7:
 */

#include <stdio.h>

void main(void)
{
    int num, fac = 1, index;
    printf("\nEnter An integar: ");
    scanf("%d", &num);

    if (0 == num)
    {

        printf("Factorial = %d\n", fac);
    }
    else if (0 > num)
    {
        printf("!!! Error Factorial of negative number does not exist !!!");
    }
    else
    {
        for (index = 1; index <= num; index++)
        {
            fac *= index;
        }
        printf("Factorial = %d\n", fac);
    }
}