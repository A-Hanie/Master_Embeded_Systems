/*
 * @file: 04-Insert_Element_in_an_array.c.c
 * @author:	Ahmed Hanie
 * @brief:
 */

#include <stdio.h>

void main(void)
{
    int arr[50] = {0};
    int len, ins_num, index, loc;

    printf("\nEnter number count: \n");
    scanf("%d", &len);

    printf("\nEnter the numbers : \n");
    for (index = 0; index < len; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("\nBefore insertion\n: ");

    for (index = 0; index < len; index++)
    {

        printf("%d\t", arr[index]);
    }

    printf("\nEnter the number to be inserted: ");
    scanf("%d", &ins_num);

    printf("\nEnter the location: ");
    scanf("%d", &loc);

    len++;

    for (index = len; index >= loc; index--)
    {
        arr[index] = arr[index - 1];
    }

    arr[loc - 1] = ins_num;
    printf("\nAfter insertion: \n");

    for (index = 0; index < len; index++)
    {
        printf("%d\t", arr[index]);
    }
}