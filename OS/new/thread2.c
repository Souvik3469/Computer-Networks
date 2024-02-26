// wap to create athread to add 2nos
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *thread_func(void *arg);
int num[2] = {3, 5};
int main()
{
    pthread_t a;
    void *res;
    pthread_create(&a, NULL, thread_func, (void *)num);
    pthread_join(a, &res);
    printf("Inside main process\n");
    printf("Thread returned: %s\n", (char *)res);
}
void *thread_func(void *arg)
{
    printf("Inside Thread\n");
    int *x = arg;
    int s = x[0] + x[1];
    printf("Sum is %d\n", s);
    pthread_exit("Sumcalc");
}