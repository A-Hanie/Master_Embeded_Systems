/*
 * @file: 05-Find_ASCII_Value.c
 * @author:	Ahmed Hanie
 * @brief:
 * 
 * EX5:
 * 
 * Write C Program to Find ASCII Value of a Character
 * 
 * #########Console_output######
 * Enter a character: G
 * ASCII value of G = 71
 * #############################
*/

#include <stdio.h>

void main(void)
{
    char character;
    printf("Enter a character: ");   
    scanf("%c", &character); 
    printf("ASCII value of %c = %d", character,character);      

}