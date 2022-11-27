/*
 * @file: 02-Print_a_Integer.c
 * @author:	Ahmed Hanie
 * @brief:
 *
 * EX2:
 * Write C Program to Print a Integer Entered by a User
 * i should see the Console as following:
 * ##########Console-output###
 * Enter a integer: 25
 * You entered: 25
 * ###########################
*/

#include <stdio.h>
void main(void)
{
    int num;                        
    printf("Enter a integer: ");   
    scanf("%d", &num);              
    printf("You entered: %d", num); 
}