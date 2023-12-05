#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>
#define myfifo "/tmp/myfifo"
#include<unistd.h>
#include<string.h>
void main(){
mkfifo(myfifo,0666);
int fd;
char s1[20],s2[20],ans[20];
fd=open(myfifo,O_RDWR);
printf("enter a string");
scanf("%[^\n]s",s1);
write(fd,s1,strlen(s1)+1);
close(fd);
fd=open(myfifo,O_RDONLY);
read(fd,ans,20);
printf("the converted string is %s " ,ans);
close(fd);

}