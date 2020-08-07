#include <stdio.h>

#include "TSMatrix.h"

int main()
{
    TSMatrix A = {
        6, 7, 8,
        {
            {0, 0, 0},
            {1, 2, 12},
            {1, 3, 9},
            {3, 1, -3},
            {3, 6, 14},
            {4, 3, 24},
            {5, 2, 18},
            {6, 1, 15},
            {6, 4, -7}
        }
    },
    B;
    Printf_TSMatrix(&A, "Matrix:");
    puts("\nwriting into a triple, it is:\n");
    Show_Matrix_Triple(&A, "The original matrix is:");

    Transpose_TSMatrix(&A, &B);
    Show_Matrix_Triple(&B, "Transposed:");

    Fast_Transpose_TSMatrix(&A, &B);
    Show_Matrix_Triple(&B, "Fast_ transposed:");

    return 0;
}