// create a file test.txt with the content "1234567890abcdefghij54321"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
    int old_fd, new_fd;
    char buff[10];
    old_fd = open("test.txt", O_RDWR);
    read(old_fd, buff, 10); // read first 10 characters using old file descriptor
    write(1, buff, 10);     // prints them on screen
    new_fd = dup(old_fd);   // duplicates file descriptor
    read(old_fd, buff, 10); // this read will read the next 10 characters even if new file descriptor is used
    write(1, buff, 10);
}