#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<pthread.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<sys/un.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/ipc.h>

#define MAX 1024
#define PORT 8085
#define ip "127.0.0.1"
#define SOCKET_PATH "/tmp/socket6"

typedef struct{
	long type;
	char arr[MAX];
}mssg;
