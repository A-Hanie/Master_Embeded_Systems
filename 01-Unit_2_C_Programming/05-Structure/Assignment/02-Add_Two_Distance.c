/*
 * @file: 02-Add_Two_Distance.c
 * @author:	Ahmed Hanie
 */

#include <stdio.h>
#include <string.h>

typedef struct
{
    int feet;
    float inch;

} distance_t;

distance_t get_distance();
distance_t add_distance(distance_t *, distance_t *);

void main(void)
{
    distance_t dis1 = get_distance();
    distance_t dis2 = get_distance();
    distance_t result = add_distance(&dis1, &dis2);

    printf("\nSum of two distances =  %d' %0.2f\" ", result.feet, result.inch);
}

distance_t get_distance()
{
    static int num = 0;
    num++;
    distance_t dis;
    printf("\nEnter the %d Distance  info : ", num);

    printf("\nEnter Feet : ");
    scanf("%i", &dis.feet);

    printf("Enter inch :");
    scanf("%f", &dis.inch);

    printf("%d' %0.2f\"\n", dis.feet, dis.inch);

    return dis;
}
distance_t add_distance(distance_t *dist1, distance_t *dist2)
{
    distance_t result;

    result.feet = dist1->feet + dist2->feet;
    result.inch = dist1->inch + dist2->inch;

    while (12.06 < result.inch)
    {
        result.inch -= 12;
        result.feet++;
    }
    return result;
}
