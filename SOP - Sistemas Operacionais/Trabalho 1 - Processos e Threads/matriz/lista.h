#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

/*
    Como eu nao tinha nenhum codigo pronto de lista
    e pra evitar fazer um horrivel as pressas, achei
    melhor colocar uma pilha sob vetor que resolve meu
    problema.
*/

/*
    IMPORTANTE:
    Todas as inserções nessa pilha acontecem simultâneamente, isto é
    insere um valor no array de impares e outro no de threads

    É um par (quantidade de impares,id da thread)
*/

typedef struct pilha
{
    // Tamanho máximo (nem cheguei a usar)
    int max;

    // Variável que controla as inserções
    int topo;

    // Array que mantém a quantidade de números impares
    int *impares;

    // Array que mantém o id da thread
    int *threads;

} Lista;

Lista criaLista(int n);

void destroiLista(Lista *l);

void *insereTopoLista(Lista *l, int impar, int thread);

void percorreLista(Lista *l);

#endif