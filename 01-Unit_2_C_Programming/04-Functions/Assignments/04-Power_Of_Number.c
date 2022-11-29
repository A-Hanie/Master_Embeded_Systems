/*
 * @file: 03-Power_Of_Number.c
 * @author:	Ahmed Hanie
 * @brief:
 */

#include <stdio.h>
#include "string.h"

int n_power(int num, int power);

void main(void)
{
    int num, power;
    printf("Enter base Number : ");
    scanf("%d", &num);
    printf("Enter Power Number (Positive integer) : ");
    scanf("%d", &power);

    printf("%d^%d = %d", num, power, n_power( num, power) );
}
int n_power(int num, int power)
{
    if(0 == power){
        return 1;
    }
    else{
        return num* n_power( num, --power);
    }
}