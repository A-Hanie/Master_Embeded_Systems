/*
 * @file: 01-Student_Info.c
 * @author:	Ahmed Hanie
 */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[10];
    int roll;
    float marks;

} info_t;

info_t get_student_info();
void display_student_info(info_t *);

void main(void)
{
    int index;
    info_t student[10];

    printf("\nEnter information of students: ");
    for (index = 0; index < (sizeof(student) / sizeof(student[0])); index++)
    {
        student[index] = get_student_info();
    }

    printf("\nDisplaying student Info...\n");
    for (index = 0; index < (sizeof(student) / sizeof(student[0])); index++)
    {
        display_student_info(&student[index]);
    }
}

info_t get_student_info()
{
    static int roll_num = 0;
    info_t local_student;

    roll_num++;
    printf("\n================\n");
    printf("For roll number %d", roll_num);

    printf("\nEnter the student name :");
    scanf("%s", local_student.name);

    local_student.roll = roll_num;

    printf("Enter the student mark :");
    scanf("%f", &local_student.marks);

    return local_student;
}
void display_student_info(info_t *local_student)
{
    printf("\n================\n");
    printf("\nInfo For roll number : %d", local_student->roll);
    printf("\nname : %s", local_student->name);
    printf("\nmarks : %0.2f", local_student->marks);
}