#include "custom.h"

void main(){

	char buf[MAX];
	printf("Enter the string\n");
	fgets(buf,MAX,stdin);
	
	int msgid=msgget((key_t)1234,0666|IPC_CREAT);
	mssg m1;
	m1.type=1;
	
	strcpy(m1.arr,buf);
	
	printf("Client sending string to server is %s\n",buf);
	msgsnd(msgid,&m1,sizeof(m1),0);
	
	mssg m2;
	m2.type=2;
	
	msgrcv(msgid,&m2,sizeof(m2),2,0);
	
	strcpy(buf,m2.arr);
	printf("Client receiving modified string is %s\n",buf);
	
}
