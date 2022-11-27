/*
 * @file: 03-Transpose_of_matrix.c
 * @author:	Ahmed Hanie
 * @brief:
 */

#include <stdio.h>

void main(void)
{
    int matrix[10][10] = {0};

    int raws, cols, r_index, c_index;
    printf("Enter number of raws and column of matrix:\n");
    scanf("%d", &raws);
    scanf("%d", &cols);

    printf("Enter the element of 1st matrix\n");
    for (r_index = 0; r_index < raws; r_index++)
    {
        for (c_index = 0; c_index < cols; c_index++)
        {
            printf("Enter a%d%d : ", r_index + 1, c_index + 1);
            /* swap index of raws and cols, can be done with making temp matrix */
            scanf("%d", &matrix[c_index][r_index]); 
        }
    }

    for (r_index = 0; r_index < cols; r_index++)
    {
        for (c_index = 0; c_index < raws; c_index++)
        {
            printf("%d ", matrix[r_index][c_index]);
        }
        printf("\n");
    }
}