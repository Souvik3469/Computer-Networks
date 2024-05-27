#include "custom.h"

char *rev(char *s){

	char* r=(char *)malloc(MAX*sizeof(char));
	int n=strlen(s);
	int i=0;
	int j=0;
	for(i=n-1;i>=0;i--)r[j++]=s[i];
	r[j]='\0';
	return r;
	
}
void main(){

	char buf[MAX];
	
	
	int msgid=msgget((key_t)1234,0666|IPC_CREAT);
	mssg m1;
	m1.type=1;
	msgrcv(msgid,&m1,sizeof(m1),1,0);
	strcpy(buf,m1.arr);
	printf("Server receiving original string from client is %s\n",buf);
	
	
	char ans[MAX];
	strcpy(ans,rev(buf));
	
	
	
	mssg m2;
	m2.type=2;
	strcpy(m2.arr,ans);
	printf("Server sending modified string is %s\n",ans);
	msgsnd(msgid,&m2,sizeof(m2),0);
	

	
}
