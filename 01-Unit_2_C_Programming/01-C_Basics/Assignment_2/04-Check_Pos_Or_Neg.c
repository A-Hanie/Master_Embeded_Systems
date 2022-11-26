/*
 * @file: 04-Check_Pos_Or_Neg.c
 * @author:	Ahmed Hanie
 * @brief:
*/

#include <stdio.h>

void main(void)
{
   float num;       
    printf("Enter a number: ");   
    scanf("%f", &num);
    if(0 == num)
        printf("You entered zero."); 
    else if(num < 0)
        printf("%.2f is Negative", num);
    else
        printf("%.2f is Posative", num);      
    

}