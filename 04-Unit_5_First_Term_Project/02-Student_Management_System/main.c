#include <stdio.h>
#include <strings.h>

#include "Platform_Types.h"
#include "FIFO.h"
#include "SMS.h"


void main() {

	uint32_t option_num , Flag = 1;
    FIFO_Status_t fifo_state;

    FIFO_t *student_queue= FIFO_CreateQueue(MAX_STUDENT, &fifo_state);

    	while(Flag) {
		//print the available options
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Choose an Option from list to do:        \n");
		printf("______________________________________________________\n");
		printf("1 : Add the student details from file    \n");
		printf("2 : Add the student details Manually     \n");
		printf("3 : Find the Student by given Roll number\n");
		printf("4 : Find the Student by given First name \n");
		printf("5 : Find the Student by registered course\n");
		printf("6 : Find the length                      \n");
		printf("7 : Update student                       \n");
		printf("8 : View students                        \n");
		printf("9: Save the list and Exit               \n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		printf("Select an option: ");
		scanf( "%d" , &option_num );

		//switching an option
		switch (option_num){
		case 1:
			SMS_Add_Student_From_File(student_queue);
			break;
		case 2:
			SMS_Add_Student_Manually(student_queue);
			break;
		case 3:
			SMS_Find_Student_Using_RollNumber(student_queue);
			break;
		case 4:
			SMS_Find_Student_Using_FirstName(student_queue);
			break;
		case 5:
			SMS_Find_Student_Using_CourseCRN(student_queue);
			break;
		case 6:
			SMS_Find_Length(student_queue);
			break;
		case 7:
			SMS_Update_Student(student_queue);
			break;
		case 8:
			SMS_View_Students(student_queue);
			break;
		case 9:
			SMS_Save_to_File(student_queue);
			Flag = 0;
			break;
		default:
			printf("Wrong Option\n");
			break;
		}
	}
}