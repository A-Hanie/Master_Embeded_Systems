/*
 * @file: 05-Check_Alpha_Or_Not.c
 * @author:	Ahmed Hanie
 * @brief:
 * 
*/

#include <stdio.h>

void main(void)
{
    char character;
    printf("Enter a character: ");   
    scanf("%c", &character);

    if(((character >='a') && (character <='z') ) ||
        ((character >='A') && (character <='Z') ) ) 

        printf("%c is an alphabet", character);      
    else
        printf("%c is not an alphabet", character);      


}