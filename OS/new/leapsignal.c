#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>

int r = 0;

void l(int y)
{
    if (y % 400 == 0)
        printf("Leap\n");
    else if (y % 100 != 0 && y % 4 == 0)
        printf("Leap\n");
    else
        printf("Not Leap\n");
}
void f(int s)
{
    r = 1;
}
void main()
{
    int p;
    int n;
    int i = 1;
    signal(SIGCHLD, f);
    p = fork();
    if (p < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (p == 0)
    {
        printf("Child with pid %d and ppid %d started\n", getpid(), getppid());
        while (1)
        {
            pause();
            if (r == 1)
            {
                printf("Child with pid %d asking for year : ", getpid());
                scanf("%d", &n);
                l(n);
                r = 0;
            }
        }
    }