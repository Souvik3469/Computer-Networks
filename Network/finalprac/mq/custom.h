#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/types.h>

#define MAX 1024

typedef struct{
	long type;
	char arr[MAX];
}mssg;
