// 7)c function to sum numbers from 1 to 100(without loop)?

#include "stdio.h"

int Sum(int);

void main(void)
{
    printf("%d",Sum(10));
}

int Sum(int n)
{
    return ( n*(n+1)/2) ;
}
