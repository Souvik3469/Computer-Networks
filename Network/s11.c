#include "custom.h"
void main(){
	
	struct sockaddr_un server;
	int fs;
	char buff[BUFF_SIZE];
	fs=socket(AF_UNIX,SOCK_STREAM,0);
	if(fs<0){
		perror("Server :Socket connection failed\n");
		exit(0);
	}
	memset(&server,0,sizeof(struct sockaddr_un));
	server.sun_family=AF_UNIX;
	strcpy(server.sun_path,SOCKET_PATH);
	
	if(bind(fs,(struct sockaddr*)&server,sizeof(struct sockaddr_un))<0)
	{
		perror("Server: Bind failed\n");
		exit(0);
	}
	if(listen(fs,20)<0){
		perror("Server: Listen failed\n");
		exit(0);
	}
	while(true){
		int fc=accept(fs,NULL,NULL);
		if(fc<0){
			perror("Server: Accept failed\n");
			exit(0);
		}
		int n=read(fc,buff,sizeof(buff));
		if(n<0){
			perror("Server read failed\n");
			exit(0);
		}
		int i,p=0;
		for(i=0;i<n;i++){
			if(buff[i]=='1')p++;
		}
		buff[n]=p%2?'1':'0';
		printf("Server: Modified bit stream:%s\n",buff);
		if(write(fc,buff,n+1)<0){
			perror("Server write failed\n");
			exit(0);
		}
		memset(buff,0,sizeof(buff));
		close(fc);
	}
	close(fs);
	unlink(SOCKET_PATH);
}
		
		
		
		
		
