#include <stdio.h>

void addMatrix(float matrix1[][2], float matrix2[][2], float result[][2])
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
     for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    printf("%.2f\t", resultMatrix[i][j]);
                }
                printf("\n");
            }
}

void subtractMatrix(float matrix1[][2], float matrix2[][2], float result[][2])
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
