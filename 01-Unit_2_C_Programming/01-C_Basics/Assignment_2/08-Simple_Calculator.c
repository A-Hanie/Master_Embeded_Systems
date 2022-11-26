/*
 * @file: 08-Simple_Calculator.c
 * @author:	Ahmed Hanie
 * @brief:
 * 
 * EX7:
*/

#include <stdio.h>

void main(void)
{
    float num1, num2, result;
    char op;
    printf("\nEnter operator either + or * or divide : ");
    scanf("%c", &op);
    printf("\nEnter two operands: ");
    scanf("%f", &num1);
    scanf("%f", &num2);

    switch(op){
        case '+': result = num1 + num2;break;
        case '-': result = num1 - num2;break;
        case '*': result = num1 * num2;break;
        case '/': result = num1 / num2;break;
        default: printf("Wrong operation");break;
    }
    printf("\n%f %c %f = %f", num1, op, num2, result);      

    }
      
