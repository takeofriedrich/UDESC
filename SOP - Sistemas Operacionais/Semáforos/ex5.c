#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

#define down(x) sem_wait(x)
#define up(x) sem_post(x)
#define MAX 10
#define N 4

int lugares[MAX];

sem_t s0;

void *comprarIngresso(int assento, int dinheiro, int *resul)
{
    if (assento > MAX)
    {
        *resul = -1;
    }
    else
    {
        if (dinheiro > 100)
        {
            up(&s0);
            if (lugares[assento] == 0)
            {
                lugares[assento] = 1;
                down(&s0);
                *resul = 1;
            }
            else
            {
                down(&s0);
                *resul = -1;
            }
        }
        else
        {
            *resul = -1;
        }
    }
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t t1, t2, t3;
    int rc;

    int *resul = 0;

    rc = pthread_create(&t1, NULL, comprarIngresso(2, 3, resul), NULL);
    assert(rc == 0);
    rc = pthread_create(&t2, NULL, comprarIngresso(2, 5, resul), NULL);
    assert(rc == 0);
    rc = pthread_create(&t3, NULL, comprarIngresso(2, 11, resul), NULL);
    assert(rc == 0);

    rc = pthread_join(t1, NULL);
    assert(rc == 0);
    rc = pthread_join(t2, NULL);
    assert(rc == 0);
    rc = pthread_join(t3, NULL);
    assert(rc == 0);

    return 0;
}