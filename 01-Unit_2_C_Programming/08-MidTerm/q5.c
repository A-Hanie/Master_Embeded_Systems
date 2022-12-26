// 5)c function to count number of ones in binary number?

#include "stdio.h"

void countOnes(int);

void main(void)
{
    countOnes(5);
    countOnes(15);

}

void countOnes(int num)
{
     printf("binary of %d is ", num);
    int oneCounter = 0;
    int binary = 0;
    for (int i = 0; i < 32; i++)
    {
        if (num & 0b1 << 31)
        {
            num = num << 1;
            oneCounter++;
            printf("1");
        }
        else
        {
            num = num << 1;
            printf("0");
        }
    }
   printf(" so has %d one's \n",oneCounter);
}
