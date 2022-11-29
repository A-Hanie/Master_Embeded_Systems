/*
 * @file: 01-Prime_Numbers.c
 * @author:	Ahmed Hanie
 */
#include "stdio.h"
#include "string.h"

void printPrime(unsigned int num1, unsigned int num2);

void main(void)
{
	printf("Enter two numbers(intervals) : \t");

	unsigned int first_num, second_num;
	scanf("%d", &first_num);
	scanf("%d", &second_num);

	printPrime(first_num, second_num);
}

void printPrime(unsigned int num1, unsigned int num2)
{
	int flag = 0;
	int local_index1, local_index2, start_index;
	if (num1 > num2)
	{
		printf("First number must be greater than second number");
	}
	else
	{
		printf(" Prime numbers between %d and %d :\t", num1 , num2);

		for (local_index1 = num1; local_index1 < num2; local_index1++)
		{
			for (local_index2 = 2; local_index2 < local_index1; local_index2++)
			{
				if ((local_index1 % local_index2) == 0)
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				printf(" %d\t", local_index1);
			}
			flag = 0;
		}
	}
}
