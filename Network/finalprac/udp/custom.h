#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>

#define MAX 1024
#define PORT 8000
#define ip "127.0.0.1"
