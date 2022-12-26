// c function to take an integer number and calculate it's square root?
#include "stdio.h"

void findPrimes(int, int);

void main(void)
{
    findPrimes(1, 20);
}

void findPrimes(int num1, int num2)
{
    int flag = 0;
    for (int i = num1; i <= num2; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i == (i / j) * j)
            {
                flag = 1;
                break;
            }
        }
        if ((flag == 0) && (i != 1))
        {

            printf("%d\t", i);
        }
        flag = 0;
    }
}
