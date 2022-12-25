#include "Platform_Types.h"
#include "SMS.h"
#include "FIFO.h"
#include "string.h"

FILE *ptrFile, *ptrList;

Student_t load_Student;
Student_t *_createStudent();

sint32_t Roll_Number_Searcher(FIFO_t *FIFO_obj, uint32_t ID)
{
    Student_t *tempStudent;
    FIFO_Status_t ret_status;

    for (uint32_t i = 0; i < FIFO_obj->ElementCount; i++)
    {
        tempStudent = (Student_t *)FIFO_n_elemnet(FIFO_obj, i, &ret_status);

        if (tempStudent->Roll_Num == ID)
        {
            return i;
        }
    }
    return -1;
}

void SMS_Add_Student_From_File(FIFO_t *FIFO_obj)
{
    Student_t *NewStudent = _createStudent();
    sint32_t Student_index;

    // Read students file
    ptrFile = fopen("students.txt", "r");

    // check null pointer
    if (ptrFile == NULL)
    {
        printf("[ERROR] Student_File.txt file isn't found \n");
        printf("[ERROR] adding students from file failed. \n");
    }

    // scan student.txt file untill the end
    while ( !feof(ptrFile) )
    {
        // Reading Roll Number of The Student
        fscanf(ptrFile, "%d", &NewStudent->Roll_Num);
        // check that student does not exist in the list before appending
        Student_index = Roll_Number_Searcher(FIFO_obj, NewStudent->Roll_Num);
        if ( Student_index != -1)
        {
            // Ignore that line
            fscanf(ptrFile, "%*[^\n]");
            //printf("[warning] Appending faild for student  %d  \n",NewStudent->Roll_Num);
           //printf("[warning] Student with %d Roll number is already exist is the list \n",NewStudent->Roll_Num);
            continue;
        }

        // Reading Name of The Student
        fscanf(ptrFile, "%s", NewStudent->F_name);
        fscanf(ptrFile, "%s", NewStudent->L_name);

        // Reading GPA of The Student
        fscanf(ptrFile, "%f", &NewStudent->GPA);

        // Reading Registered Courses of The Student
        for (uint32_t i = 0; i < 4; i++)
        {
            fscanf(ptrFile, "%d", &NewStudent->Course_CRN[i]);
        }

        FIFO_EnqueueElement(FIFO_obj, (void *)NewStudent);
    }

    fclose(ptrFile);
}

Status_t SMS_Add_Student_Manually(FIFO_t *FIFO_obj)
{
    Student_t * myStudent = _createStudent();

    sint32_t Student_index;

    printf("Student Roll Number: ");
    scanf("%d", &myStudent->Roll_Num);

    Student_index = Roll_Number_Searcher(FIFO_obj, myStudent->Roll_Num);

        if ( Student_index != -1)
        {
            fscanf(ptrFile, "%*[^\n]");
            printf("[warning] Appending faild for student  %d  \n", myStudent->Roll_Num);
            printf("[warning] Student with %d Roll number is already exist is the list \n",myStudent->Roll_Num);
            return 0;
        }



    printf("Student First Name: ");
    scanf("%s", myStudent->F_name);

    // read Student Last Name
    printf("Student Last Name: ");
    scanf("%s", myStudent->L_name);

    printf("Student GPA: ");
    scanf("%f", &myStudent->GPA);

    printf("C programming CRN course is  1\n");
    printf("Embedded C CRN course is     2\n");
    printf("Data Struture CRN course is  3\n");
    printf("Micro-controller course is  4\n");
    printf("Interfacing CRN course is    5\n");
    printf("Validation CRN course is     6\n");
    printf("_____________________________\n");

    // setection Courses CRN
    printf("Courses are \n");
    for (uint32_t i = 0; i < 4; i++)
    {
        printf("Course %d: ", i);
        scanf("%d", &myStudent->Course_CRN[i]);
    }

    FIFO_EnqueueElement(FIFO_obj, myStudent);
}

void SMS_Find_Student_Using_RollNumber(FIFO_t *FIFO_obj)
{
    uint32_t Flag = 0;
    Student_t *sStudent = _createStudent();
    uint32_t ret_status;
    uint32_t reqID;

    // read Student Roll Number
    printf("Student Roll Number : ");
    scanf("%i", &reqID);

    for (uint32_t i = FIFO_obj->index_Front; i < FIFO_obj->ElementCount; i++)
    {
        sStudent = (Student_t *)FIFO_n_elemnet(FIFO_obj, i, &ret_status);

        if (reqID == sStudent->Roll_Num)
        {
            Flag = 1;
            printf("This Roll number for student: \n");
            View_Student((Student_t *)FIFO_obj, i);
            break;
        }
    }

    if (!Flag)
        printf("This Roll number is not exist in the list\n");
}

void SMS_Find_Student_Using_FirstName(FIFO_t *FIFO_obj)
{
    char str[20];
    uint32_t Flag = 0;
    Student_t *sStudent = _createStudent();
    uint32_t ret_status;

    // read Student First Name
    printf("Student First Name : ");
    scanf("%s", str);

    for (uint32_t i = FIFO_obj->index_Front; i < FIFO_obj->ElementCount; i++)
    {
        sStudent = (Student_t *)FIFO_n_elemnet(FIFO_obj, i, &ret_status);

        if (stricmp(sStudent->F_name, str) == 0)
        {
            Flag = 1;
            printf("This Name is for Student \n");
            View_Student((Student_t *)FIFO_obj, i);
        }
    }

    if (!Flag)
        printf("This Name is not exist in the list\n");
}

void SMS_Find_Student_Using_CourseCRN(FIFO_t *FIFO_obj)
{
    Student_t *sStudent = _createStudent();
    uint32_t ret_status;
    uint32_t Flag = 0;
    uint32_t courseCRN;

    // Read Course CRN
    printf("Enter CRN of the Course: ");
    scanf("%d", &courseCRN);

    for (uint32_t i = FIFO_obj->index_Front; i < FIFO_obj->ElementCount; i++)
    {
        sStudent = (Student_t *)FIFO_n_elemnet(FIFO_obj, i, &ret_status);
        for (uint32_t course_index = 0; course_index < NUMBER_OF_COURSES; course_index++)
            if (courseCRN == sStudent->Course_CRN[course_index])
            {
                Flag = 1;
                View_Student((Student_t *)FIFO_obj, i);
            }
    }
    if (!Flag)
        printf("no one registered this course\n");
}

void SMS_Find_Length(FIFO_t *FIFO_obj)
{
    uint32_t FIFOCount;
    FIFO_Get_Count(FIFO_obj, &FIFOCount);
    printf("This list content %d Student\n", FIFOCount);
}

void SMS_Update_Student(FIFO_t *FIFO_obj)
{
    uint32_t selection, id, Roll_Number, tempData;
    char str[20];
    FIFO_Status_t state;

    printf("Enter Student Roll Number: ");
    scanf("%d", &Roll_Number);

    id = Roll_Number_Searcher(FIFO_obj, Roll_Number);

    if (-1 == id)
    {
        printf("This Roll Number isn't found  in the list\n");
    }
    else
    {
        Student_t *student2update = (Student_t *)FIFO_n_elemnet(FIFO_obj, id, &state);

        printf("Update Student name select 1\n");
        printf("Update roll number select 2\n");
        printf("Update Student GPA select 3\n");
        printf("Update courses CRN select 4\n");
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
        {
            // read Student First Name
            printf("Student First Name: ");
            scanf("%s", str);
            strcpy(student2update->F_name, str);

            // read Student First Name
            printf("Student Last Name: ");
            scanf("%s", str);
            strcpy(student2update->L_name, str);

            printf("[DONE]\n");
        }
        break;
        case 2:
        {
            // read Student Roll Number
            printf("Student Roll Number: ");
            scanf("%d", &tempData);
            student2update->Roll_Num = tempData;

            printf("[DONE]\n");
        }
        break;
        case 3:
        {
            // read Student GPA
            printf("Student GPA: ");
            scanf("%d", &tempData);
            student2update->GPA = tempData;

            printf("[DONE]\n");
        }
        break;
        case 4:
        {
            // read Student Courses to be registered
            printf("C programming CRN course is  1\n");
            printf("Embedded C CRN course is     2\n");
            printf("Data Struture CRN course is  3\n");
            printf("Micro-controller course is  4\n");
            printf("Interfacing CRN course is    5\n");
            printf("Validation CRN course is     6\n");
            printf("_____________________________\n");

            // setection Courses CRN
            printf("Courses are \n");
            for (uint32_t i = 0; i < 4; i++)
            {
                printf("Course CRN %d: ", i);
                scanf("%d", &tempData);
                student2update->Course_CRN[i] = tempData;
            }

            printf("[DONE]\n");
            break;
        }
        }
    }
}
void SMS_View_Students(FIFO_t *FIFO_obj)
{
    uint32_t ststes, FIFOCount;
    Student_t *myStudent;

    FIFO_Get_Count(FIFO_obj, &FIFOCount);

    for (uint32_t index = FIFO_obj->index_Front; index < FIFO_obj->ElementCount; index++)
    {
        View_Student((Student_t *)FIFO_obj, index);
    }
    printf("--------------------------------------------------\n");
}

void SMS_Save_to_File(FIFO_t *FIFO_obj)
{
    uint32_t ststes, FIFOCount;
    Student_t *myStudent;
    FIFO_Get_Count(FIFO_obj, &FIFOCount);
    ptrList = fopen("students.txt", "w");
    if (ptrList == NULL)
    {
        printf("[ERROR] student.txt file isn't found \n");
        printf("[ERROR] adding students from file failed. \n");
    }
    for (uint32_t index = FIFO_obj->index_Front; index < FIFO_obj->ElementCount; index++)
    {
        myStudent = (Student_t *)FIFO_n_elemnet(FIFO_obj, index, &ststes);
        // save Student details
        fprintf(ptrList, "%d ", myStudent->Roll_Num);
        fprintf(ptrList, "%s ", myStudent->F_name);
        fprintf(ptrList, "%s ", myStudent->L_name);
        fprintf(ptrList, "%f ", myStudent->GPA);

        for (uint32_t i = 0; i < 4; i++)
        {
            fprintf(ptrList, "%d ", myStudent->Course_CRN[i]);
        }
        fprintf(ptrList, "\n");
    }
}

Student_t *_createStudent()
{
    Student_t *myStudent;
    myStudent = (Student_t *)malloc(sizeof(Student_t));
    /* Should check for null **/
    return myStudent;
}

void View_Student(Student_t *FIFO_buf, uint32_t index)
{
    uint32_t ststes, FIFOCount;
    Student_t *myStudent;

    FIFO_Get_Count((FIFO_t *)FIFO_buf, &FIFOCount);
    printf("--------------------------------------------------\n");
    myStudent = (Student_t *)FIFO_n_elemnet((FIFO_t *)FIFO_buf, index, &ststes);
    printf("Student Roll Number: %d\n", myStudent->Roll_Num);
    printf("Student Name: %s %s\n", myStudent->F_name, myStudent->L_name);
    printf("Student GPA: %f\n", myStudent->GPA);
}
