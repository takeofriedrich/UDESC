#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX 2000

int n;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void f1(void *argp)
{
    int i, temp;
    pthread_mutex_lock(&mutex);
    for (i = 0; i < MAX; i++)
    {
        temp = n;
        temp++;
        n = temp;
    }
    pthread_mutex_unlock(&mutex);
}

void f2(void *argp)
{
    int i, temp;
    pthread_mutex_lock(&mutex);
    for (i = 0; i < MAX; i++)
    {
        temp = n;
        temp--;
        n = temp;
    }
    pthread_mutex_unlock(&mutex);
}

int main(void)
{
    pthread_t t1, t2;
    int rc;
    n = 0;
    rc = pthread_create(&t1, NULL, (void *)f1, NULL);
    rc = pthread_create(&t2, NULL, (void *)f2, NULL);
    rc = pthread_join(t1, NULL);
    rc = pthread_join(t2, NULL);
    printf("n=%d\n", n);
    pthread_mutex_destroy(&mutex);
    return 0;
}