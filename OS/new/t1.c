#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int sum, sum1, sum2;
int n;
int n1, n2;
int *a1;
int *a2;

void *f(void *arg)
{
    //      int x=*(int *)arg;
    // res=x+2;
    int *x = arg;
    //      res=x[0]+x[1];
    sum = 0;
    int i;
    for (i = 0; i < n; i++)
        sum += x[i];
    pthread_exit(&sum);
}
void *f1(void *arg)
{
    a1 = arg;
    int i;
    sum1 = 0;
    for (i = 0; i < n1; i++)
        sum1 += a1[i];
    pthread_exit(&sum1);
}
void *f2(void *arg)
{
    a2 = arg;
    int i;
    sum2 = 0;
    for (i = 0; i < n2; i++)
        sum2 += a2[i];
    pthread_exit(&sum2);
}

void *f3(void *arg)
{
    a1 = arg;
    int i;
    int ans1[n1];
    int k = 0;
    for (i = n1 - 1; i >= 0; i--)
        ans1[k++] = a1[i];
    for (i = 0; i < n1; i++)
        a1[i] = ans1[i];
    pthread_exit(a1);
}
void *f4(void *arg)
{
    a2 = arg;
    int i;
    int ans2[n2];
    int k = 0;
    for (i = n2 - 1; i >= 0; i--)
        ans2[k++] = a2[i];
    for (i = 0; i < n2; i++)
        a2[i] = ans2[i];
    pthread_exit(a2);
}

void main()
{

    pthread_t th, th1, th2, th3, th4;
    //      int n;
    printf("Enter n: ");
    scanf("%d", &n);
    void *res;
    void *res1;
    void *res2;
    void *left;
    void *right;
    int i;
    int j;
    int a[n];
    // a[0]=1;
    // a[1]=2;
    n1 = n / 2;
    n2 = n - n1;
    a1 = (int *)malloc(n1 * (sizeof(int)));
    a2 = (int *)malloc(n2 * (sizeof(int)));
    printf("Enter array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n1; i++)
        a1[i] = a[i];
    for (j = 0; j < n2; j++)
        a2[j] = a[i + j];

    //      pthread_create(&th,NULL,f,(void*)&n);
    //      pthread_join(th,&res);
    pthread_create(&th, NULL, f, (void *)a);
    pthread_join(th, &res);
    pthread_create(&th1, NULL, f1, (void *)a1);
    pthread_join(th1, &res1);
    pthread_create(&th2, NULL, f2, (void *)a2);
    pthread_join(th2, &res2);
    pthread_create(&th3, NULL, f3, (void *)a1);
    pthread_join(th3, &left);
    pthread_create(&th4, NULL, f4, (void *)a2);
    pthread_join(th4, &right);
    //      int *ansleft;
    //      int *ansright;
    a1 = (int *)left;
    a2 = (int *)right;
    printf("Ans is: %d\n ", *(int *)res);
    printf("Ans1 is: %d\n ", *(int *)res1);
    printf("Ans2 is: %d\n ", *(int *)res2);
    printf("First half array in reverse:\n");
    for (i = 0; i < n1; i++)
        printf("%d ", a1[i]);
    printf("\n");
    printf("Second half array in reverse:\n");
    for (i = 0; i < n2; i++)
        printf("%d ",
               a2[i]);
    printf("\n");
}