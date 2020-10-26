#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

void *PrintHello(void *arg)
{
    long tid = (long)arg;
    printf("Alo da thread %ld\n",
           tid);
    pthread_exit(NULL);
}

void *quadrado(void *arg)
{
    long tid = (long)arg;
    printf("Thread: %ld - O quadrado do numero eh: %d\n", tid, tid * tid);
    pthread_exit((void *)(tid * tid));
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("main: criando thread %ld\n", t);
        rc = pthread_create(&threads[t],
                            NULL,
                            PrintHello,
                            (void *)t);
        if (rc)
        {
            printf("ERRO - rc=%d\n", rc);
            exit(-1);
        }
    }
    /*Ultima coisa que main() deve fazer */

    pthread_t threads2[NUM_THREADS + 3];
    int rc2;
    int cont = 0;
    for (long t2 = 0; t2 < NUM_THREADS + 3; t2++)
    {
        void *resul = NULL;
        printf("main: criando a thread %ld\n", t2);
        rc2 = pthread_create(&threads2[t2], NULL, quadrado, ((void *)t2));
        pthread_join(threads2[t2], &resul);
        cont += (long)resul;
        printf("Soma até o momento: %ld\n", cont);
        if (rc2)
        {
            printf("Erro - rc=%d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}