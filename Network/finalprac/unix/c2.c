#include "custom1.h"

void main(){
	struct sockaddr_un client;
	char buf[MAX];
		printf("Enter the string\n");
		fgets(buf,MAX,stdin);
	int cfd=socket(AF_UNIX,SOCK_STREAM,0);
	if(cfd<0){
		perror("Socket failed\n");
		exit(EXIT_FAILURE);
	}
	//memset(&client,0,sizeof(client));
	client.sun_family=AF_UNIX;
	strcpy(client.sun_path,SOCKET_PATH);
	
	if(connect(cfd,(struct sockaddr*)&client,sizeof(client))<0){
		perror("Connection failed\n");
		exit(EXIT_FAILURE);
	}
	
	//while(true){
		
		if(write(cfd,buf,strlen(buf)+1)<0){
			perror("write failed\n");
			exit(EXIT_FAILURE);
		}
		if(read(cfd,buf,sizeof(buf))<0){
			perror("Read failed\n");
			exit(EXIT_FAILURE);
		}
		printf("Modified string is %s ",buf);
		
		
	//}
	close(cfd);
}
	
