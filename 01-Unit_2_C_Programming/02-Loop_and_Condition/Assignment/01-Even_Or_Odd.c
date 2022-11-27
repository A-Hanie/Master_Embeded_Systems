/*
 * @file: 01-Even_Or_Odd.c
 * @author:	Ahmed Hanie
 */
#include "stdio.h"

void main(void)
{
    int num;
    printf("Enter an integer you want to check: ");
    scanf("%d", &num);
    if (num % 2 == 0)
        printf("%d is even",num);
    else
        printf("%d is odd",num);
}