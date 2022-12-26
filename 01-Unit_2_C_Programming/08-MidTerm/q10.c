//c function to count the max number of ones between two zeros?   




#include "stdio.h"

void countOnes(char);

void main(void)
{
    countOnes(14);
    countOnes(110);

}

void countOnes(char num)
{
     printf("binary of %d is ", num);
    int oneCounter = 0;
    int maxOneCounter = 0;
    int maxOne=0;
    int binary = 0;
    for (int i = 0; i < 7; i++)
    {
        if (num & 0b1 << 7)
        {
            num = num << 1;
            oneCounter++;
            maxOneCounter++;
            printf("1");
        }
        else
        {

            num = num << 1;
            maxOneCounter=0;
            printf("0");
        }
        if(maxOne < maxOneCounter){
            maxOne = maxOneCounter;
        }
    }
   printf(" has max number of ones between two zeros is %d \n", maxOne);
}
