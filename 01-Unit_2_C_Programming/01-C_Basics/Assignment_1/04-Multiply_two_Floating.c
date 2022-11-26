/*
 * @file: 04-Multiply_two_Floating.c
 * @author:	Ahmed Hanie
 * @brief:
 *
 * EX4:

 * Write C Program to Multiply two Floating Point Numbers
 * i should see the Console as following:
 * ##########Console-output###
 * 
 * ###########################
 * Enter two numbers: 2.4
 * 1.1
 * Product: 2.640000
 * ########################################################################

*/

#include <stdio.h>

void main(void)
{
   float num_1, num_2, res;        
    printf("Enter two numbers: ");   
    scanf("%f %f", &num_1, &num_2);  
	res = num_1 * num_2;           
    printf("Product: %.6f", res);      

}