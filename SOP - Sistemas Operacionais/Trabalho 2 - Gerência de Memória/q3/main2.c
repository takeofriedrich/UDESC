#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void *imprime(void *valor)
{
    printf("%d ", (int)(valor));
}

int geraAleatorio(int max)
{
    if (max != 0)
    {
        int valor = 0;
        do
        {
            valor = rand() % max;
        } while (valor > max);
        return valor;
    }
    else
    {
        return 0;
    }
}

int main()
{
    list *lista = list_create(sizeof(int));

    for (int i=0;i<10;i++) {
        push(lista, (int*)(i), i);
    }

    printList(lista, imprime);

    for (int i=0;i<10;i++) {
        printf("(%d)", i);
        imprime(get(lista, i));
    }



    list_destroy(lista);

    return 0;
}