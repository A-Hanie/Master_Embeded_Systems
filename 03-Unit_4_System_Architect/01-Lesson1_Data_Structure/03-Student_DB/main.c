#include "student.h"

int len=0;
int main()
{
	//print the available options
	printf("Choose an Option from list to do:  \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
	printf("1 : Add student                   \n");
	printf("2 : Delete student                \n");
	printf("3 : view students                 \n");
	printf("4 : Delete all                    \n");
	printf("5 : Get Nth of node from the first\n");
	printf("6 : Get Nth of node from the end  \n");
	printf("7 : Find the length               \n");
	printf("8 : Find the middle               \n");
	printf("9: Reverse                       \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");

	uint8_t option_num[10];

	while (1)
	{
		printf("Select an option: ");
		gets(option_num);

		switch (atoi(option_num)) {
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			Display_Students();
			break;
		case 4:
			Delete_All();
			break;
		case 5:
			Get_nth_Node_first();
			break;
		case 6:
			Get_nth_Node_end();
			break;
		case 7:
			Find_Length_iterative();
			len = Find_Length_recursive(ptr_FirstStudent);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
			printf("\nThe number of student in the list using recursive function :%d\n", len);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
			break;
		case 8:
			Find_Middle();
			break;
		case 9:
			list_reverse();
			break;
		default:
			printf("Wrong Option\n");
			break;
		}
	}
}

