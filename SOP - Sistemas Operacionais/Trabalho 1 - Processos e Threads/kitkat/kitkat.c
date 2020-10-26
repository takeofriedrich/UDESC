#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s1, s2, s3;

void *a(void *argp)
{
    sem_wait(&s1);
    while (1)
    {
        printf("i");
        sem_post(&s2);
        sem_wait(&s1);
        printf("a");
        sem_post(&s2);
        sem_wait(&s1);
    }
    pthread_exit(NULL);
}

void *b(void *argp)
{
    sem_wait(&s2);
    while (1)
    {
        for (int i = 0; i < 2; i++)
        {
            printf("t");
            if (i == 0)
            {
                printf(" ");
            }
            sem_post(&s3);
            sem_wait(&s2);
        }
    }
    pthread_exit(NULL);
}

void *c(void *argp)
{
    while (1)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("K");
            sem_post(&s1);
            sem_wait(&s3);
        }
        printf("\n");
    }
    pthread_exit(NULL);
}

/*
    Utilizar apenas as primitivas down(), up(), sem_wait(), sem_post()

    -> sem_post()
        libera a seção crítica do sinaleiro. 
        contador é incrementado. 
        primeira tarefa da fila é acordada

    -> sem_wait()
        solicita acesso a seção critica
        caso esteja livre a tarefa continua
        caso não, a tarefa é adicionada a fila
        contador decrementado

*/

int main(void)
{
    pthread_t t1, t2, t3;
    sem_init(&s1, 0, 0);
    sem_init(&s2, 0, 0);
    sem_init(&s3, 0, 0);
    int rc;
    rc = pthread_create(&t1, NULL, a, NULL);
    assert(rc == 0);
    rc = pthread_create(&t2, NULL, b, NULL);
    assert(rc == 0);
    rc = pthread_create(&t3, NULL, c, NULL);
    assert(rc == 0);
    rc = pthread_join(t1, NULL);
    assert(rc == 0);
    rc = pthread_join(t2, NULL);
    assert(rc == 0);
    rc = pthread_join(t3, NULL);
    assert(rc == 0);
    return 0;
}