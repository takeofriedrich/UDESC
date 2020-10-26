#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Apenas para gerar a matriz m x n e preenche-la com valores aleatórios
*/

int **criaMatriz(int m, int n);

void preencheMatriz(int **matriz, int m, int n);

void destroiMatriz(int **matriz, int m);

void exibeMatriz(int **matriz, int m, int n);

#endif