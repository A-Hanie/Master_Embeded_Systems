/*
 * @file: 03-Add_Two_Integers.c
 * @author:	Ahmed Hanie
 * @brief:
 *
 * EX3:
 * Write C Program to Add Two Integers
 * i should see the Console as following:
 * ##########Console-output###
 * Enter two integers: 12
 * 11
 * Sum: 23
 * ###########################
*/

#include <stdio.h>

void main(void)
{
    int num_1, num_2;                      
    printf("Enter two integers: ");         
    scanf("%d %d", &num_1, &num_2);        
    printf("Sum: %d", num_1 + num_2);

}