/*
 * @file: 03-Reverse.c
 * @author:	Ahmed Hanie
 * @brief:
 */

#include <stdio.h>

void reverse()
{
    char c;
    scanf("%c",&c);
    if(c != '\n')
    {
        reverse();
        printf("%c",c);
    }
}

void main(void)
{
    printf(" Enter a sentence: ");
    reverse();
}