#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MYFIFO "/tmp/pipefile"

void main()
{
    //      int fd1;
    int fd;
    char str1[100];
    char str2[100];
    char ans[100];
    //      unlink(MYFIFO);
    mkfifo(MYFIFO, 0666);
    printf("Enter 1st string: ");
    scanf("%[^\n]", str1);
    printf("Enter 2nd string: ");
    scanf(" %[^\n]", str2);
    fd = open(MYFIFO, O_RDWR);
    write(fd, str1, strlen(str1) + 1);
    //      usleep(100);
    write(fd, str2, strlen(str2) + 1);
    //      usleep(100);
    read(fd, ans, 100);
    printf("Ans: %s", ans);
    //      close(fd1);
    close(fd);
}
