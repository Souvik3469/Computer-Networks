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
	struct sockaddr_un server;
	char buf[MAX];
	unlink(SOCKET_PATH);
	int sfd=socket(AF_UNIX,SOCK_STREAM,0);
	if(sfd<0){
		perror("Socket failed\n");
		exit(EXIT_FAILURE);
	}
	//memset(&server,0,sizeof(server));
	server.sun_family=AF_UNIX;
	strcpy(server.sun_path,SOCKET_PATH);
	
	if(bind(sfd,(struct sockaddr*)&server,sizeof(server))<0){
		perror("Bind failed\n");
		exit(EXIT_FAILURE);
	}
	if(listen(sfd,5)<0){
		perror("Listen failed\n");
		exit(EXIT_FAILURE);
	}
	
	while(true){
		
		int cfd=accept(sfd,NULL,NULL);
		if(cfd<0){
			perror("Accept failed\n");
			exit(EXIT_FAILURE);
		}
		if(read(cfd,buf,sizeof(buf))<0){
			perror("Read failed\n");
			exit(EXIT_FAILURE);
		}
		printf("Original string from server %s\n",buf);
		char ans[MAX];
		strcpy(ans,rev(buf));
		printf("Modified string sent to client %s\n",ans);
		
		if(write(cfd,ans,strlen(ans)+1)<0){
			perror("Write failed\n");
			exit(EXIT_FAILURE);
		}
		
		close(cfd);
		
	}
	close(sfd);
	unlink(SOCKET_PATH);
}
	
