#include "head.h"

void main(){
	struct sockaddr_un client;
	char buff[MAX];
	int fc=socket(AF_UNIX,SOCK_STREAM,0);
	if(fc<0){
		perror("CLient: Socket creation failed\n");
		exit(0);
	}
	printf("Client socket created\n");
	memset(&client,0,sizeof(struct sockaddr_un));
	client.sun_family=AF_UNIX;
	strcpy(client.sun_path,path);
	
	if(connect(fc,(struct sockaddr*)&client,sizeof(struct sockaddr_un))){
		perror("Client failed to connect socket\n");
		exit(0);
	}
	
	printf("Enter string\n");
	scanf("%s",buff);
	
	int n=write(fc,buff,sizeof(buff));
	if(n<0){
		perror("Client write failed\n");
		exit(0);
	}
	printf("Modified string received in client\n");
	if(read(fc,buff,strlen(buff))<0){
		perror("Client read failed\n");
		exit(0);
	}
	printf("%s\n",buff);
}
	
