/*
 * @file: 06-Size_of_Struct.c
 * @author:	Ahmed Hanie
 */

#include <stdio.h>



typedef union
{
	char name [32] ;
	float salary;
	int worker_no;

} union_t;

typedef struct 
{
	char name [32];
	float salary;
	int worker_no;

} struct_t;


int main ()
{
	printf ("Size of the int is: %d", sizeof (int));              //	4 Byte
	printf ("\nSize of the float is: %d", sizeof (float));        //	4 Byte
	printf ("\nSize of the union is: %d", sizeof (union_t));      //	32 Byte
	printf ("\nSize of the structure is: %d", sizeof (struct_t)); //	32+4+4 = 40 Byte ||

	return 0;
}
