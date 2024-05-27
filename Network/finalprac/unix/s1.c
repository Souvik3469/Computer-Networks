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
	struct sockaddr_un server;
	int sfd;
	unlink(SOCKET_PATH);
	sfd=socket(AF_UNIX,SOCK_STREAM,0);
	if(sfd<0){
		perror("Socket failed\n");
		exit(0);
	}
	//memset(&server,0,sizeof(server));
	server.sun_family=AF_UNIX;
	strcpy(server.sun_path,SOCKET_PATH);
	
	if(bind(sfd,(struct sockaddr*)&server,sizeof(server))<0){
		perror("Bind failed\n");
		exit(0);
	}
	if(listen(sfd,5)<0){
		perror("Listen failed\n");
		exit(0);
	}
	
	while(true){
		int cfd=accept(sfd,NULL,NULL);
		read(cfd,buf,sizeof(buf));
		printf("Server receiving original string from client is %s\n",buf);
		char ans[MAX];
		strcpy(ans,rev(buf));
		printf("Server sending modified string is %s\n",ans);
		write(cfd,ans,strlen(ans)+1);
		
		
		
		close(cfd);
	}
	close(sfd);
	unlink(SOCKET_PATH);
}
	
