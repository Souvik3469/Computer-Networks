#include "custom1.h"

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
	
	struct sockaddr_in server;
	int sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sfd<0){
		perror("Socket failed\n");
		exit(EXIT_FAILURE);
	}
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=INADDR_ANY;
	
	if(bind(sfd,(struct sockaddr*)&server,sizeof(server))<0){
		perror("Bind failed\n");
		exit(EXIT_FAILURE);
	}
	

	
	while(true){

	char buf[MAX];
	int l=sizeof(server);
	if(recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&server,&l)<0){
		perror("Received failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Original string received from client %s\n",buf);
	char ans[MAX];
	strcpy(ans,rev(buf));
	printf("Modified string sent to client %s\n",ans);
	if(sendto(sfd,ans,strlen(ans)+1,0,(struct sockaddr*)&server,l)<0){
		perror("Send failed\n");
		exit(EXIT_FAILURE);
	}
	
	
	}
	close(sfd);
}
