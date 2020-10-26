#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

#define down(x) sem_wait(x)
#define up(x) sem_post(x)

int n = 1;

sem_t s0, s1;

void *x(void *argp)
{
    n = n * 16;
    printf("%d\n", n);
    up(&s0);
    pthread_exit(NULL);
}

void *y(void *argp)
{
    down(&s1);
    n = n / 7;
    printf("%d\n", n);
    up(&s0);
    pthread_exit(NULL);
}

void *z(void *argp)
{
    down(&s0);
    n = n + 40;
    printf("%d\n", n);
    up(&s1);
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t t1, t2, t3;
    int rc;

    rc = pthread_create(&t1, NULL, x, NULL);
    assert(rc == 0);
    rc = pthread_create(&t2, NULL, y, NULL);
    assert(rc == 0);
    rc = pthread_create(&t3, NULL, z, NULL);
    assert(rc == 0);

    rc = pthread_join(t1, NULL);
    assert(rc == 0);
    rc = pthread_join(t2, NULL);
    assert(rc == 0);
    rc = pthread_join(t3, NULL);
    assert(rc == 0);

    return 0;
}