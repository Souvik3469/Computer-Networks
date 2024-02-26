#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <wait.h>
#include <fcntl.h>

#define MAX 100

int main()
{

    char str1[MAX];
    char str2[MAX];
    char res[MAX];
    int fd1, fd2;
    mkfifo("tmp/fifo1", 0666);
    fd1 = open("tmp/fifo1", O_WRONLY);
    printf("Enter str1: ");
    scanf("%s", str1);
    write(fd1, str1, strlen(str1) + 1);
    printf("Enter str2: ");
    scanf("%s", str2);
    write(fd1, str2, strlen(str2) + 1);

    fd2 = open("tmp/fifo2", O_RDONLY);
    read(fd2, res, sizeof(res));
    printf("%s and %s are %s\n", str1, str2, res);
    close(fd1);
    close(fd2);
    return 0;
}