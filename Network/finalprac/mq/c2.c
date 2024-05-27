#include "custom1.h"

void main(){
	char buf[MAX];
	printf("Enter the string\n");
	fgets(buf,MAX,stdin);
	
	int msgid=msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid<0){
		perror("MQ failed");
		exit(EXIT_FAILURE);
	}
	
	mssg m1,m2;
	m1.type=1;
	strcpy(m1.arr,buf);
	msgsnd(msgid,&m1,sizeof(m1),0);
	m2.type=2;
	msgrcv(msgid,&m2,sizeof(m2),2,0);
	strcpy(buf,m2.arr);
	printf("Modified string received from server is %s \n",buf);
}
