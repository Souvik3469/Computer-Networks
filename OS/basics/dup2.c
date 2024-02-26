#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
    int old_fd, new_fd;
    old_fd = open("test.txt", O_RDWR);
    printf("File descriptor is %d\n", old_fd);
    new_fd = dup2(old_fd, 7);
    printf("New file descriptor is %d\n", new_fd);
}