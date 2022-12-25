#ifndef SMS_H_
#define SMS_H_

#include "FIFO.h"
#include <stdio.h>

#define NUMBER_OF_COURSES 4
#define MAX_STUDENT  5

typedef struct {
	float GPA;
	uint8_t F_name[20];
	uint8_t L_name[20];
	uint32_t Roll_Num;
	uint32_t Course_CRN[NUMBER_OF_COURSES];
} Student_t;

typedef enum {
    OK,
    NOK
}Status_t;

void SMS_Add_Student_From_File(FIFO_t *FIFO_obj);

Status_t SMS_Add_Student_Manually(FIFO_t *FIFO_obj);

void SMS_Find_Student_Using_RollNumber(FIFO_t *FIFO_obj);

void SMS_Find_Student_Using_FirstName(FIFO_t *FIFO_obj);

void SMS_Find_Student_Using_CourseCRN(FIFO_t *FIFO_obj);

void SMS_Find_Length(FIFO_t *FIFO_obj);

sint32_t Roll_Number_Searcher(FIFO_t *FIFO_obj , uint32_t ID);

void SMS_Detete_Student(FIFO_t *FIFO_obj);

void SMS_Update_Student(FIFO_t *FIFO_obj);

void SMS_View_Students(FIFO_t *FIFO_obj);

void SMS_Save_to_File(FIFO_t *FIFO_obj);

void View_Student(Student_t* FIFO_buf, uint32_t index);



#endif /* SMS_H_ */