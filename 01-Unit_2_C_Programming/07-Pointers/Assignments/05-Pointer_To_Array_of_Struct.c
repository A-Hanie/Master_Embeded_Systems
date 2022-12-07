#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *name;
	int id;
} emp_t;

void main()
{
	emp_t emp1 = {"Zelda", 752}, emp2 = {"Link", 753}, emp3 = {"Ocarina", 756};

	emp_t *emp_arr[3] = {&emp1, &emp2, &emp3};

	emp_t *(*ptr)[3] = &emp_arr; // ptr is a pointer to array of 3 struct

	printf(" Employee Name : %s \n", (*(*ptr))->name);
	printf(" Employee ID :  %d \n", (*(*ptr))->id);
}