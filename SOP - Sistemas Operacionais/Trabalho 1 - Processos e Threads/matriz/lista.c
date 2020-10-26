#include "lista.h"

/*
    Como eu nao tinha nenhum codigo pronto de lista
    e pra evitar fazer um horrivel as pressas, achei
    melhor colocar uma pilha sob vetor que resolve meu
    problema.
*/

Lista criaLista(int n)
{
    Lista l;
    l.max = n;
    l.topo = 0;
    l.impares = (int *)malloc(sizeof(int) * n);
    l.threads = (int *)malloc(sizeof(int) * n);

    return l;
}

void destroiLista(Lista *l)
{
    free(l->impares);
    free(l->threads);
    free(l);
}

void *insereTopoLista(Lista *l, int impar, int thread)
{
    l->impares[l->topo] = impar;
    l->threads[l->topo] = thread;
    l->topo++;
}

void percorreLista(Lista *l)
{
    for (int i = 0; i < l->topo; i++)
    {
        printf("Thread %d => %d impares\n", l->threads[i], l->impares[i]);
    }
}