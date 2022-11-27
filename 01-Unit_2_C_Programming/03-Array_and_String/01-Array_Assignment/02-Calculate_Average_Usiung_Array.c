/*
 * @file: 02-Calculate_Average_Usiung_Array.c
 * @author:	Ahmed Hanie
*/

#include <stdio.h>
void main(void)
{
    int n, index ;
    float data[50] = {0};
    float avg , sum = 0;

    printf("\nEnter number of data: ");
    scanf("%d", &n);

    for(index = 0 ; index < n ; index++){
    printf("\nEnter number: ");
    scanf("%f", &data[index]);
    sum += data[index];
    }

    avg = sum/n;
    printf("\nAverage = %0.2f",avg);


}