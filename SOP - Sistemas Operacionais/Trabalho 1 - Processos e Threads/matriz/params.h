#ifndef PARAMS_H
#define PARAMS_H

#include <stdlib.h>
#include <stdio.h>

/*
Estrutura que define os parâmetros passados para a thread
*/

typedef struct params
{
    // Linha da matriz
    int *linha;

    // ordem da matriz
    int m;
    int n;

    // numero da thread
    int id;

} Params;

Params *criaParams(int *linha, int id, int m, int n);

void destroiParams(Params *parametros);

#endif