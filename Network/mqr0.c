#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 50

typedef struct
{
    long type;
    char msg[MAX];
} MSG;

void main()
{

    

    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("MSG");
        exit(EXIT_FAILURE);
    }
    printf("Receiver receivin\n");
    MSG mq1;

    mq1.type = 1;


    msgrcv(msgid, &mq1, sizeof(mq1), 1, 0);
    printf("\nString is:%s", mq1.msg);
 
    printf("\nALL Data received from sender\n");
}
