#include "params.h"

Params *criaParams(int *linha, int id, int m, int n)
{
    Params *aux = (Params *)malloc(sizeof(Params *));
    aux->linha = linha;
    aux->m = m;
    aux->n = n;
    aux->id = id;
    return aux;
}

void destroiParams(Params *parametros)
{
    free(parametros);
}
