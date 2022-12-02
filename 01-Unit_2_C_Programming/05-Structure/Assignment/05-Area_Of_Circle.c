/*
 * @file: 05-Area_Of_Circle.c
 * @author:	Ahmed Hanie
 */

#include <stdio.h>
#include <string.h>


#define     MATH_PI             3.14

#define    CIRCLE_AREA(r)      (MATH_PI* r*r)

void main(void)
{
    float reduis;
    printf("Enter Circle Redius : ");
    scanf("%f", &reduis);
    printf("The Area of the circule = %0.2f  unit^2",CIRCLE_AREA(reduis));
}
