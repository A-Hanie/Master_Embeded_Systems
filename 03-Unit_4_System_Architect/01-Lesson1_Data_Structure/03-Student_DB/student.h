#ifndef STUDENT_H_
#define STUDENT_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"

typedef struct 
{
	int ID;
	char Name[20];
	float Height;
}data_t;

typedef struct Student_Node
{
	data_t data;
	struct Student_Node *ptr_next_student;
}Student_Node_t;

typedef enum {
	DONE,
	ERROR,
	NO_ERROR,
	EMPTY
}e_Status;

extern Student_Node_t *ptr_FirstStudent ;


int Get_length( Student_Node_t* ptr);
e_Status Get_Student( Student_Node_t* ptr);

e_Status Add_Student();
e_Status Delete_Student();
e_Status Display_Students();
e_Status Delete_All();
e_Status Get_nth_Node_first();
e_Status Get_nth_Node_end();
e_Status Find_Length_iterative();
unsigned int Find_Length_recursive(Student_Node_t *ptr_idxStudent);
e_Status Find_Middle();
void list_reverse(void);

#endif
