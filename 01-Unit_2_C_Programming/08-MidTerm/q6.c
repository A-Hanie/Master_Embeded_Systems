// 6)c function to return unique number in array with one loop?

#include "stdio.h"

int unique(int *, int len);

void main(void)
{
    int arr1[7] = {4,2,5,2,5,7,4}; // output:7
    int arr2[3] = {4,2,4}; // output:7

    unique(arr1, 7);
    unique(arr2, 3);

}

int unique(int *arr, int len)
{
    int freq[10] = {0};
    int i,j;
    for (i = 0; i < len; i++)
    {
        j =  arr[i];
        freq[j]++;
    }
    printf("\nthe unique number is: ");
    for (i = 0; i < 10; i++)
    {
        if (freq[i] == 1){
            printf("%d ", i);
        }
    }
}
