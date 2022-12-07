#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	int arr[5] = {0};
	int *ptr;

	int __;

	for (__ = 1; __ <= 5; __++)
	{
		printf("\nelement - %d = ", __);
		scanf("%d", &arr[__]);
	}

	printf("\narray in reverse order are : ");
	ptr = arr + 5;
	for (__ = 1; __ <= 5; __++)
	{
		printf("\nelement - %d = %d ", __, *ptr--);
	}
}