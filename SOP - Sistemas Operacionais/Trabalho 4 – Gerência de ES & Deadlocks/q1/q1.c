#include "stdlib.h"
#include "stdio.h"
#include "lista.h"

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

    int dist = 0;

    for (int i = 0; i < cont; i++)
    {
        for (int j = 0; j < cont; j++)
        {
            dist = *(int *)(elementAt(lista, i)) - *(int *)(elementAt(lista, j));
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
