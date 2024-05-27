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
void swap(char a, char b)
{
    char t = a;
    a = b;
    b = t;
}
void rv(char *s)
{
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j)
    {
        //swap(s[i++], s[j--]);
        char t = s[i];
    	s[i] = s[j];
    	s[j] = t;
    	i++;
    	j--;
    }
}
void dtob(int n, char *s)
{
    int i = 0;
    while (n > 0)
    {
        s[i] = n % 2 + '0';
        n >>= 1;
        i++;
    }
    s[i] = '\0';
    rv(s);
}
void dtoo(int n, char *s)
{
    int i = 0;
    while (n > 0)
    {
        s[i] = n % 8 + '0';
        n >>= 3;
        i++;
    }
    s[i] = '\0';
    rv(s);
}
void dtoh(int n, char *s)
{
    int i = 0;
    while (n > 0)
    {
        s[i] = n % 16 > 0 ? n % 16 + '0' : n % 16 + 'A';
        n >>= 4;
        i++;
    }
    s[i] = '\0';
    rv(s);
}
void main()
{
    int n;
    printf("SENDER sending data\n");
    printf("Enter n:");
    scanf("%d", &n);
    char bin[MAX], oct[MAX], hex[MAX];
    dtob(n, bin);
    dtoo(n, oct);
    dtoh(n, hex);
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("MSG");
        exit(EXIT_FAILURE);
    }
    MSG mq1, mq2, mq3;
    strcpy(mq1.msg, bin);
    strcpy(mq2.msg, oct);
    strcpy(mq3.msg, hex);
    mq1.type = 1;
    mq2.type = 2;
    mq3.type = 3;
    msgsnd(msgid, &mq1, sizeof(mq1), 0);
    msgsnd(msgid, &mq2, sizeof(mq2), 0);
    msgsnd(msgid, &mq3, sizeof(mq3), 0);
    printf("ALL Data sent from sender\n");
}
