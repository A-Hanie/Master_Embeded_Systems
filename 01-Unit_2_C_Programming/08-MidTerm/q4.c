// 4)c function to revers digits in number?  
#include "stdio.h"
int reverseDigit(int);
void main(void)
{
    printf("%d\n", reverseDigit(2457));
    printf("%d\n", reverseDigit(1057));
}

int reverseDigit(int num)
{
    int rev=0;
    while(num)
    {
        rev *= 10;
        rev += num%10;
        num /= 10;
    }
    return rev;
}