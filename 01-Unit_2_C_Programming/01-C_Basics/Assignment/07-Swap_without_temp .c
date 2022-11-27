/*
 * @file: 07-Swap_without_temp .c
 * @author:	Ahmed Hanie
 * @brief:
 * 
 * EX7:
 * Write Source Code to Swap Two Numbers without temp variable.
*/

#include <stdio.h>

void main(void)
{
    int a, b;
    printf("Enter value of a: ");   
    scanf("%d", &a);
    printf("Enter value of b: ");   
    scanf("%d", &b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("After swapping, value of a = %d", a);
    printf("\nAfter swapping, value of b = %d", b);      
      

}