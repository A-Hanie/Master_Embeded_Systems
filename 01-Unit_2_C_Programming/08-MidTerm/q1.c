// c function to take a number and sum all digits?
#include "stdio.h"
int digitSum(int);
void main(void)
{
    printf("%d\n", digitSum(123));
    printf("%d\n", digitSum(4565));
}

int digitSum(int num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}