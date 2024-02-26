// wap to cereate a thread.Thread prints 0-4 while the main process prints 20-24
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *thread_func(void *arg);
int i, j;

int main()
{
    pthread_t a;
    pthread_create(&a, NULL, thread_func, NULL);
    pthread_join(a, NULL);
    printf("Inside main prog\n");
    for (j = 20; j < 25; j++)
    {
        printf("%d\n", j);
        sleep(1);
    }
}
void *thread_func(void *arg)
{
    printf("Inside Thread\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
}