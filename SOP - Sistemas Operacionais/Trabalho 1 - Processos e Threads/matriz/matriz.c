#include "matriz.h"

int **criaMatriz(int m, int n)
{
    int **matriz = (int **)malloc(sizeof(int *) * m);

    for (int i = 0; i < m; i++)
    {
        matriz[i] = (int *)malloc(sizeof(int) * n);
    }

    return matriz;
}

void preencheMatriz(int **matriz, int m, int n)
{
    srand(time(NULL));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }
}

void destroiMatriz(int **matriz, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}

void exibeMatriz(int **matriz, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}