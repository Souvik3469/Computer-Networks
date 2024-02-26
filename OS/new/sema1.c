// program for process synchron using semaphores
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

void *fun1();
void *fun2();
int sh = 1;
sem_t s;
int main()
{
    sem_init(&s, 0, 1);
    pthread_t th1, th2;
    pthread_create(&th1, NULL, fun1, NULL);
    pthread_create(&th2, NULL, fun2, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("Final val of shared var is %d\n", sh);
}
void *fun1()
{
    int x;
    sem_wait(&s);
    x = sh;
    printf("Thread1 reads the val as %d\n", x);
    x++;
    printf("Loal updaton by thread1: %d\n", x);
    sleep(1);
    sh = x;
    printf("Val of shared var updated by thread1 is %d\n", sh);
    sem_post(&s);
}

void *fun2()
{
    int y;
    sem_wait(&s);
    y = sh;
    printf("Thread2 reads the val as %d\n", y);
    y--;
    printf("Local updation by thread2: %d\n", y);
    sleep(1);
    sh = y;
    printf("Val of shared var updation by thread2 is %d\n", sh);
    sem_post(&s);
}