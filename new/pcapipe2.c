#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#define myfifo "/tmp/myfifo"
#include <fcntl.h>

void main()
{
    char s1[20], a[20];
    int fd, i = 0;
    fd = open(myfifo, O_RDWR);
    read(fd, s1, 20);
    while (s1[i] != '\0')
    {
        s1[i] = toupper(s1[i]);
        i++;
    }
    usleep(100);
    write(fd, s1, strlen(s1) + 1);
    close(fd);
}