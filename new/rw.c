#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

sem_t rcLock, writerLock;
int read_count = 0;
// rcLock is for updating the read count so that only thread is able to update it.

void *read_fn(void *n)
{
    char *name = (char *)n;
    printf("%s entered to read and waiting\n", name);
    sem_wait(&rcLock);
    read_count += 1;

    if (read_count == 1)
        sem_wait(&writerLock);

    sem_post(&rcLock);
    printf("%s is reading\n", name);
    sleep(rand() % 4 + 1);

    sem_wait(&rcLock);
    read_count -= 1;
    printf("%s finished reading\n", name);

    if (read_count == 0)
        sem_post(&writerLock);

    sem_post(&rcLock);
}

void *write_fn(void *n)
{
    char *name = (char *)n;
    printf("\t%s entered to write and waiting\n", name);
    sem_wait(&writerLock);
    printf("\t%s is writing\n", name);
    sleep(rand() % 2 + 1);
    sem_post(&writerLock);
    printf("\t%s finished writing\n", name);
}

int main()
{
    pthread_t r[5], w[1];

    sem_init(&rcLock, 0, 1);
    sem_init(&writerLock, 0, 1);

    while (1)
    {
        pthread_create(&r[0], NULL, &read_fn, (void *)"Reader 0");
        pthread_create(&r[1], NULL, &read_fn, (void *)"Reader 1");
        pthread_create(&r[2], NULL, &read_fn, (void *)"Reader 2");
        pthread_create(&w[0], NULL, &write_fn, (void *)"Writer 1");
        pthread_create(&r[3], NULL, &read_fn, (void *)"Reader 3");
        pthread_create(&r[4], NULL, &read_fn, (void *)"Reader 4");

        pthread_join(r[0], NULL);
        pthread_join(r[1], NULL);
        pthread_join(r[2], NULL);
        pthread_join(w[0], NULL);
        pthread_join(r[3], NULL);
        pthread_join(r[4], NULL);

        printf("----------------------------\n");
    }
}