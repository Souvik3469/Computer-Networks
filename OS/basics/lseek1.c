#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    int n, f;
    char buff[10];
    f = open("seeking", O_RDWR);
    read(f, buff, 10);
    write(1, buff, 10);
    read(f, buff, 10);
    write(1, buff, 10);
}