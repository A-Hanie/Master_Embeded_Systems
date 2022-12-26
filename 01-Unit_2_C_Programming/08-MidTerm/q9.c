// c function to reverse words in string


#include "stdio.h"
#include "string.h"
void reverse(char *, int);

void main(void)
{
    char str[10] ;
    printf("enther string to be reversed: ");
    gets(str);

    reverse(str, strlen(str));
}

void reverse(char *arr, int len)
{
    char rev[10];
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        rev[len - i - 1] = arr[i];
    }
    printf("\n");

    for (i = 0; i < len; i++)
    {
        printf("%c",rev[i]);
    }
}