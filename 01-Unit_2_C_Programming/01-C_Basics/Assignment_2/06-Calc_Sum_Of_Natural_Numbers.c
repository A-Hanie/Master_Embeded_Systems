/*
 * @file: 06-Calc_Sum_Of_Natural_Numbers.c
 * @author:	Ahmed Hanie
 * @brief:
*/

#include <stdio.h>

void main(void)
{
    unsigned int num, sum=0, index;
    printf("\nEnter An integar: ");   
    scanf("%d", &num);

    for(index = 1 ;index <= num ; index++ ){
            sum += index;
    }
    printf("Sum = %d\n", sum);      
      

}