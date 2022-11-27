/*
 * @file: 01-Multidimensional_Array.c
 * @author:	Ahmed Hanie
 */
#include "stdio.h"

void main(void)
{
    float a[2][2];
    float b[2][2];
    int i, j;

    printf("Enter the element of 1st matrix\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter a%d%d : ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the element of 2ed matrix\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter b%d%d : ", i + 1, j + 1);
            scanf("%f", &b[i][j]);
        }
    }

    printf("\nSum Of Matrix\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            a[i][j] += b[i][j];
            printf("%0.1f ", a[i][j]);
        }
        printf("\n");
    }
}