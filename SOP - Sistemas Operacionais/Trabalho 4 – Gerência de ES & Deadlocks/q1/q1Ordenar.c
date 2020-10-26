#include "stdlib.h"
#include "stdio.h"
#include "lista.h"

#define ANTERIOR 212

void quick_sort(int *array, int esq, int dir)
{
    // Função adaptada de: https://www.vivaolinux.com.br/script/Ordenacao-QuickSort

    int i = esq;
    int j = dir;

    int meio = (int)((i + j) / 2);

    int pivo = array[meio];
    int aux;

    do
    {
        while (array[i] < pivo)
            i++;
        while (array[j] > pivo)
            j--;

        if (i <= j)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    } while (j > i);

    if (esq < j)
    {
        quick_sort(array, esq, j);
    }

    if (i < dir)
    {
        quick_sort(array, i, dir);
    }
}

int main()
{

    list *lista = list_create(sizeof(int));

    int *v = malloc(sizeof(int));

    *v = 0;

    int cont = 0;

    while (*v != -1)
    {
        scanf("%d", v);

        if (*v != -1)
        {
            push(lista, v, cont);
            cont++;
        }
    }

    int trilhas[cont];

    for (int i = 0; i < cont; i++)
    {
        trilhas[i] = *((int *)(elementAt(lista, i)));
    }

    quick_sort(trilhas, 0, cont - 1);

    int dist = 0;

    int anterior = ANTERIOR;

    int cont2 = 0;

    for (int i = 0; i < cont; i++)
    {
        if (trilhas[i] < anterior)
            cont2++;
    }

    int trilhas2[cont];

    printf(",");

    for (int i = 0; i < cont; i++)
    {
        printf("%d,", trilhas[i]);
    }

    printf("\n");

    for (int i = 0; i < cont; i++)
    {
        printf("%d,", trilhas[i]);

        for (int j = 0; j < cont; j++)
        {
            dist = trilhas[i] - trilhas[j];
            if (dist < 0)
                dist *= -1;
            printf("%d,", dist);
        }
        printf("\n");
    }

    list_destroy(lista);

    free(v);

    return 0;
}
