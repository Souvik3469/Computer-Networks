#include "custom1.h"


void *rev(char *s){

	char *r=(char *)malloc( MAX*sizeof(char));
	int i=0;
	int j=0;
	int n=strlen(s);
	for(i=n-1;i>=0;i--)r[j++]=s[i];
	
	r[j]='\0';
	return r;
}
	
void main(){
	char buf[MAX];
	
	
	int msgid=msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid<0){
		perror("MQ failed");
		exit(EXIT_FAILURE);
	}
	
	mssg m1,m2;
	m1.type=1;
	msgrcv(msgid,&m1,sizeof(m1),1,0);
	strcpy(buf,m1.arr);
	printf("Original string received from client is %s ",buf);
	char ans[MAX];
	strcpy(ans,rev(buf));
	m2.type=2;
	strcpy(m2.arr,ans);
	printf("Modified string sent to client is %s \n",ans);
	msgsnd(msgid,&m2,sizeof(m2),0);
	
	
}
