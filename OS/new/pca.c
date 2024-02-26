#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *f(void *a)
{
    int *x = a;
    int thn = x[0];
    int st = x[1];
    int en = x[2];
    int i, j, c;
    printf("Thread no. %d ,range %d to %d\n", thn, st, en);
    for (i = st; i <= en; i++)
    {
        if (i == 1)
            continue;
        c = 0;
        for (j = 1; j <= i; j++)
        {
            if (i % j == 0)
                c++;
        }
        if (c == 2)
            printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    pthread_t th;
    int a[3];
    int d = n / 10;
    int r = n % 10;
    int i;
    for (i = 1; i <= 10; i++)
    {

        a[0] = i;
        a[1] = (i - 1) * d + 1;
        if (i == 10)
        {

            a[2] = (i - 1) * d + d + r;
        }
        else
            a[2] = (i - 1) * d + d;
        int st = a[1];
        int en = a[2];
        pthread_create(&th, NULL, f, (void *)a);
        pthread_join(th, NULL);
        sleep(1);
    }
    return 0;
}