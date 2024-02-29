#include "custom.h"

void main(){

	struct sockaddr_un client;
	int fc;
	char buff[BUFF_SIZE];
	fc=socket(AF_UNIX,SOCK_STREAM,0);
	if(fc<1){
		perror("Client : Socket connection error\n");
		exit(0);
	}
	printf("Client socket connected\n");
	memset(&client,0,sizeof(struct sockaddr_un));
	client.sun_family=AF_UNIX;
	strcpy(client.sun_path,SOCKET_PATH);
	
	if(connect(fc,(struct sockaddr*)&client,sizeof(struct sockaddr_un))<0){
		perror("Client: Connection failed\n");
		exit(0);
	}
	printf("ENter bit stream");
	scanf("%s",buff);
	int n=write(fc,buff,strlen(buff));
	if(n<0){
		perror("Client Write failed\n");
		exit(0);
	}
	if(read(fc,buff,sizeof(buff))<0){
		perror("Client read failed\n");
		exit(0);
	}
	printf("Client: Modified bit stream %s\n",buff);
	close(fc);
	exit(0);
}
