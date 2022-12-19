#include "student.h"
#include "string.h"
Student_Node_t *ptr_NewStudent = NULL;
Student_Node_t *ptr_FirstStudent = NULL;
Student_Node_t *ptr_LastStudent = NULL;
Student_Node_t *ptr_PrevStudent = NULL;
Student_Node_t *ptr_CurrentStudent = NULL;
Student_Node_t *ptr_NextStudent = NULL;

uint8_t temp_data[20];
uint32_t length;

e_Status Get_Student(Student_Node_t *ptr)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");

	printf("Enter Student Data: ");

	printf("\n\t Student ID: ");
	gets(temp_data);
	ptr_NewStudent->data.ID = atoi(temp_data);

	printf("\t Student Name: ");
	gets(ptr_NewStudent->data.Name);

	printf("\t Student Height: ");
	gets(temp_data);
	ptr_NewStudent->data.Height = atof(temp_data);

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");

	return DONE;
}

e_Status Add_Student()
{
	ptr_NewStudent = (Student_Node_t *)malloc(sizeof(Student_Node_t));
	if (NULL == ptr_NewStudent)
	{
		printf("error");
		return ERROR;
	}

	if (!ptr_FirstStudent)
		ptr_FirstStudent = ptr_NewStudent;
	else
	{
		// Navigate to the last student
		ptr_LastStudent = ptr_FirstStudent;
		while (ptr_LastStudent->ptr_next_student)
			ptr_LastStudent = ptr_LastStudent->ptr_next_student;

		ptr_LastStudent->ptr_next_student = ptr_NewStudent;
	}
	ptr_LastStudent = ptr_NewStudent;

	Get_Student(ptr_NewStudent);

	ptr_NewStudent->ptr_next_student = NULL;

	length++;

	return NO_ERROR;
}

e_Status Delete_Student()
{
	printf("Enter student ID:");
	gets(temp_data);

	ptr_CurrentStudent = ptr_FirstStudent;

	if (ptr_FirstStudent != NULL)
	{
		// if student is the first node
		if (atoi(temp_data) == ptr_FirstStudent->data.ID)
		{
			ptr_FirstStudent = ptr_FirstStudent->ptr_next_student;
			free(ptr_CurrentStudent->ptr_next_student);
		}
		else
		{
			// if student in any node
			while (atoi(temp_data) != ptr_CurrentStudent->data.ID)
			{
				if (NULL == ptr_CurrentStudent->ptr_next_student)
				{
					printf("This ID not exist.\n");
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
					return ERROR;
				}
				ptr_PrevStudent = ptr_CurrentStudent;
				ptr_CurrentStudent = ptr_CurrentStudent->ptr_next_student;
			}
			// if this element is the last node
			if (NULL == ptr_CurrentStudent->ptr_next_student)
				ptr_PrevStudent->ptr_next_student = NULL;
			else
			{
				ptr_PrevStudent->ptr_next_student =
					ptr_CurrentStudent->ptr_next_student;
				free(ptr_CurrentStudent->ptr_next_student);
			}
		}
	}

	length--;
	if (ptr_FirstStudent == NULL)
		printf("list is empty\n");

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
	return NO_ERROR;
}

e_Status Display_Students()
{
	uint32_t count = 0;
	ptr_CurrentStudent = ptr_FirstStudent;

	// list is empty
	if (NULL == ptr_FirstStudent)
	{
		printf("list is empty\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
		return EMPTY;
	}

	printf("Students are\n");
	while (NULL != ptr_CurrentStudent)
	{
		printf("Record number %d\n", count + 1);
		printf("\tID    : %d\n", ptr_CurrentStudent->data.ID);
		printf("\tName  : %s\n", ptr_CurrentStudent->data.Name);
		printf("\tHeight: %f\n", ptr_CurrentStudent->data.Height);
		ptr_CurrentStudent = ptr_CurrentStudent->ptr_next_student;
		count++;
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
	return DONE;
}

e_Status Delete_All()
{
	if (NULL == ptr_FirstStudent)
	{
		printf("list is empty");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
		return EMPTY;
	}
	else
	{
		ptr_CurrentStudent = ptr_FirstStudent;
		while (NULL != ptr_CurrentStudent)
		{
			ptr_CurrentStudent = ptr_FirstStudent->ptr_next_student;
			free(ptr_FirstStudent->ptr_next_student);
			ptr_FirstStudent = ptr_CurrentStudent;
		}
		printf("Done list is deleted\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");

		length = 0;
		return DONE;
	}
}

e_Status Get_nth_Node_first()
{

	printf("Enter student index from beginning: \n");
	gets(temp_data);

	uint32_t count = 0;
	if (NULL == ptr_FirstStudent)
	{
		printf("list is empty\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
		return EMPTY;
	}
	ptr_CurrentStudent = ptr_FirstStudent;

	while (atoi(temp_data) != count)
	{
		count++;
		ptr_CurrentStudent = ptr_CurrentStudent->ptr_next_student;
	}
	printf("Record Student of index %d\n", atoi(temp_data));
	printf("\tID    : %d\n", ptr_CurrentStudent->data.ID);
	printf("\tName  : %s\n", ptr_CurrentStudent->data.Name);
	printf("\tHeight: %f\n", ptr_CurrentStudent->data.Height);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
	return DONE;
}

e_Status Get_nth_Node_end()
{
	printf("Enter student index from the end: \n");
	gets(temp_data);
	int offset = atoi(temp_data);

	if (NULL == ptr_FirstStudent)
	{
		printf("list is empty\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
		return EMPTY;
	}
	uint32_t count = 0;
	Student_Node_t *ptr_main = ptr_FirstStudent;
	Student_Node_t *ptr_ref = ptr_FirstStudent;

	while(offset)
	{
		ptr_ref = ptr_ref->ptr_next_student;
		offset--;
	}
	while(ptr_ref->ptr_next_student)
	{
		ptr_ref = ptr_ref->ptr_next_student;
		ptr_main = ptr_main->ptr_next_student;
	}

	printf("Record Student of index ( %d ) from the end\n", atoi(temp_data));
	printf("\tID    : %d\n", ptr_main->data.ID);
	printf("\tName  : %s\n", ptr_main->data.Name);
	printf("\tHeight: %f\n", ptr_main->data.Height);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
	return DONE;
}

e_Status Find_Length_iterative()
{
	uint32_t count = 0;
	ptr_CurrentStudent = ptr_FirstStudent;
	if (NULL == ptr_FirstStudent)
	{
		printf("list is empty\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
		return EMPTY;
	}
	while (NULL != ptr_CurrentStudent)
	{
		count++;
		ptr_CurrentStudent = ptr_CurrentStudent->ptr_next_student;
	}
	printf("The number of student in the list using iterative function :%d\n", count);
	return DONE;

}

unsigned int Find_Length_recursive(Student_Node_t *ptr_idxStudent)
{
	if (NULL != ptr_idxStudent)
	{
		return 1 + Find_Length_recursive(ptr_idxStudent->ptr_next_student);
	}
	else
		return 0;
}

e_Status Find_Middle()
{
	int middle =1;
	Student_Node_t *ptr_fast = ptr_FirstStudent;
	Student_Node_t *ptr_slow = ptr_FirstStudent;

	if (NULL == ptr_FirstStudent)
	{
		printf("list is empty\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
		return EMPTY;
	}

	while(NULL != ptr_fast->ptr_next_student)
	{
		ptr_fast = ptr_fast->ptr_next_student->ptr_next_student;
		ptr_slow = ptr_slow->ptr_next_student;
		middle++;
	}

	printf("Record of the middle Student ( %d ) is :\n", middle);
	printf("\tID    : %d\n", ptr_slow->data.ID);
	printf("\tName  : %s\n", ptr_slow->data.Name);
	printf("\tHeight: %f\n", ptr_slow->data.Height);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
	return DONE;
}

void list_reverse()
{
	Student_Node_t *ptr_Prev = NULL;
	Student_Node_t *ptr_CurrentStudent = ptr_FirstStudent;
	Student_Node_t *ptr_Next = NULL;
	if(ptr_FirstStudent == NULL)
	{
		printf("\nThe List is not exist.\n");
		return;
	}

	while(ptr_CurrentStudent != NULL)
	{
		ptr_Next = ptr_CurrentStudent->ptr_next_student;
		ptr_CurrentStudent->ptr_next_student = ptr_Prev;
		ptr_Prev = ptr_CurrentStudent;
		ptr_CurrentStudent = ptr_Next;
	}
	ptr_FirstStudent = ptr_Prev;
	Display_Students();
}