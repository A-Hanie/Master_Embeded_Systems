// 8)c function to take an array and revers its elements

#include "stdio.h"

void reverse(int *, int);

void main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    reverse(a, 5);
}

void reverse(int *arr, int len)
{
    int rev[10];
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        rev[len - i - 1] = arr[i];
    }
    for (i = 0; i < len; i++)
    {
        printf("%d\t",rev[i]);
    }
}