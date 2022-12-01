/*
 * @file: 01-Student_Info.c
 * @author:	Ahmed Hanie
 */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    int roll;
    float marks;

} info_t;

info_t get_student_info();
void display_student_info(info_t*);

void main(void)
{
    info_t student = get_student_info();
    display_student_info(&student);
}

info_t get_student_info()
{
    printf("Enter the student Info...\n");

    info_t local_student;
    printf("Enter the student name :");
    gets(local_student.name);

    printf("\nEnter the student roll number :");
    scanf("%d", &local_student.roll);

    printf("\nEnter the student mark :");
    scanf("%f", &local_student.marks);

    return local_student;
}
void display_student_info(info_t *local_student)
{
    printf("\nDisplaying student Info...");

printf("\nname : %s", local_student->name);
    printf("\nroll : %i", local_student->roll);
    printf("\nmarks : %0.2f", local_student->marks);
}