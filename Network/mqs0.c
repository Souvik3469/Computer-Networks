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
    char s[MAX];
    printf("SENDER sending data\n");
    printf("Enter string\n");
    //scanf("%s", &n);
    fgets(s,MAX,stdin);
    
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("MSG");
        exit(EXIT_FAILURE);
    }
    MSG mq1;
    strcpy(mq1.msg, s);
    
    mq1.type = 1;
    
    msgsnd(msgid, &mq1, sizeof(mq1), 0);
    
    printf("ALL Data sent from sender\n");
}
