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
    char res[100];
    char str1[100];
    char str2[100];
    fd = open(MYFIFO, O_RDWR);
    read(fd, str1, 100);
    read(fd, str2, 100);
    if (strcmp(str1, str2) == 0)
        write(fd, "SAME", 5);
    else
        write(fd, "NOT SAME", 9);
    //      close(fd1);
    close(fd);
}