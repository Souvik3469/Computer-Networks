#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>

#define MAX 1024
#define SOCKET_PATH "/tmp/mysocket"

#define BUFF_SIZE 30

typedef struct {
    char dw[BUFF_SIZE];
    char gen[BUFF_SIZE];
} Word;

/*
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sys/un.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>

#define SOCKET_PATH "/tmp/mySocket"
#define BUFF_SIZE 30*/
