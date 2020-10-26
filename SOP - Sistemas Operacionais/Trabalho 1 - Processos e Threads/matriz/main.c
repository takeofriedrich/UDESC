#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include "lista.h"
#include "matriz.h"
#include "params.h"

pthread_barrier_t barreira;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
Lista lista;

void *contaImpares(void *arg)
{
    // Desencapsula os parâmetros
    Params *parametros = (Params *)(arg);

    // Barreira aguarda as m threads serem criadas
    pthread_barrier_wait(&barreira);

    int cont = 0;

    for (int i = 0; i < parametros->n; i++)
    {
        if (parametros->linha[i] % 2 == 1)
        {
            cont++;
        }
    }

    pthread_mutex_lock(&mutex); // Protege a região crítica

    insereTopoLista(&lista, cont, parametros->id);

    pthread_mutex_unlock(&mutex); // Libera a região crítica

    // Barreira aguarda as m threads terminarem de contar
    pthread_barrier_wait(&barreira);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    // Captura os argumentos m e n
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    // Cria a matriz (ver header matriz.c)
    int **matriz = criaMatriz(m, n);

    // Cria a lista (ver header lista.c)
    lista = criaLista(m);

    // (ver header matriz.c)
    preencheMatriz(matriz, m, n);

    // (ver header matriz.c)
    exibeMatriz(matriz, m, n);

    // Inicia a barreira para aguardar por m threads
    pthread_barrier_init(&barreira, NULL, m);

    int rc;

    // cria um array contendo m threads
    pthread_t listaThreads[m];

    // cria um array de parametros para enviar para cada uma das m threads
    Params **parametros = (Params **)malloc(sizeof(Params *) * m);

    // preenche o array com cada linha da matriz, sua identificação e a ordem da matriz
    for (int i = 0; i < m; i++)
    {
        // (ver params.c)
        parametros[i] = criaParams(matriz[i], i, m, n);
    }

    // cria as m threads
    for (int i = 0; i < m; i++)
    {
        rc = pthread_create(&(listaThreads[i]), NULL, contaImpares, (void *)parametros[i]);
        assert(rc == 0);
    }

    // faz o join nas m threads
    for (int i = 0; i < m; i++)
    {
        rc = pthread_join(listaThreads[i], NULL);
        assert(rc == 0);
    }

    // exibe a lista contendo todos os pares <quantidade de impares,id thread>
    percorreLista(&lista);

    /*
    Os trechos abaixo liberam a memória utilizada no processo da contagem de impares
    */

    for (int i = 0; i < m; i++)
    {
        destroiParams(parametros[i]);
    }

    free(parametros);

    pthread_barrier_destroy(&barreira);
    pthread_mutex_destroy(&mutex);

    destroiMatriz(matriz, m);

    return 0;
}