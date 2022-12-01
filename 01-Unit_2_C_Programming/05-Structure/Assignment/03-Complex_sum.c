/*
 * @file: 03-Complex_sum.c
 * @author:	Ahmed Hanie
 */

#include <stdio.h>
#include <string.h>

typedef struct
{
    float real;
    float img;

} complex_t;

complex_t get_complex();
complex_t add_complex(complex_t *, complex_t *);

void main(void)
{
    complex_t comp1 = get_complex();
    complex_t comp2 = get_complex();
    complex_t result = add_complex(&comp1, &comp2);

    char real_sign = (result.real < 0) ? '\0' : '+';// '\0' because negative sign is already assigned with number
    char img_sign = (result.img < 0) ? '\0' : '+'; 

    printf("\nResult = %c %.2f %c %0.2fi ", real_sign, result.real, img_sign, result.img);
}

complex_t get_complex()
{
    complex_t comp;

    printf("\nEnter the real term : ");
    scanf("%f", &comp.real);

    printf("\nEnter the imagnery term :");
    scanf("%f", &comp.img);

    char real_sign = (comp.real < 0) ? '\0' : '+';
    char img_sign = (comp.img < 0) ? '\0' : '+';

    printf("\n %c%0.2f %c %0.2fi", real_sign, comp.real, img_sign, comp.img);

    return comp;
}
complex_t add_complex(complex_t *comp1, complex_t *comp2)
{
    complex_t result;

    result.real = comp1->real + comp2->real;
    result.img = comp1->img + comp2->img;
    return result;
}