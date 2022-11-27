/*
 * @file: 03-Largest_Number_Among_Three.c
 * @author:	Ahmed Hanie
 * @brief:
*/

#include <stdio.h>

void main(void)
{
    double num1, num2, num3;

    printf("Enter three different numbers: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3)
        printf("%.2f is the largest number.", num1);

    else if (num2 >= num1 && num2 >= num3)
        printf("%.2f is the largest number.", num2);

    else 
        printf("%.2f is the largest number.", num3);

}