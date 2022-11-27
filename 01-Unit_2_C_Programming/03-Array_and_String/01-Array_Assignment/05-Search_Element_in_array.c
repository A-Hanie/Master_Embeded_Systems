/*
 * @file: 05-Search_Element_in_array.c
 * @author:	Ahmed Hanie
 * @brief:
 *
 */

#include <stdio.h>

void main(void)
{
    int arr[50];
    int len, index, des_number;
    
    printf("Enter number of elements: \n");
    scanf("%i", &len);

    printf("\nEnter the numbers : \n");
    for (index = 0; index < len; index++)
    {
        scanf("%d", &arr[index]);
    }

    printf("Enter element to be searched : \n");
    scanf("%i", &des_number);

    for (index = 0; index < len; index++)
    {
        if (des_number == arr[index])
        {
            printf("\nNumber found at the location = %d \n", (index + 1));
            break;
        }
        else
        {
            continue;
        }
    }
}