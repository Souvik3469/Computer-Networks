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

    char bin[MAX], oct[MAX], hex[MAX];

    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("MSG");
        exit(EXIT_FAILURE);
    }
    printf("Receiver receivin\n");
    MSG mq1, mq2, mq3;

    mq1.type = 1;
    mq2.type = 2;
    mq3.type = 3;

    msgrcv(msgid, &mq1, sizeof(mq1), 1, 0);
    printf("\nBinary is:%s", mq1.msg);
    msgrcv(msgid, &mq2, sizeof(mq2), 2, 0);
    printf("\nOctal is:%s", mq2.msg);
    msgrcv(msgid, &mq3, sizeof(mq3), 3, 0);
    printf("\nHex is:%s", mq3.msg);
    printf("\nALL Data received from sender\n");
}
