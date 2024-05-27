#include "custom1.h"

void main(){
	
	struct sockaddr_in client;
	int cfd=socket(AF_INET,SOCK_STREAM,0);
	if(cfd<0){
		perror("Socket failed\n");
		exit(EXIT_FAILURE);
	}
	memset(&client,0,sizeof(client));
	client.sin_family=AF_INET;
	client.sin_port=htons(PORT);
	client.sin_addr.s_addr=inet_addr(ip);
	
	if(connect(cfd,(struct sockaddr*)&client,sizeof(client))<0){
		perror("Connection failed\n");
		exit(EXIT_FAILURE);
	}
	
	char buf[MAX];
		printf("Enter the string\n");
		fgets(buf,MAX,stdin);
		if(write(cfd,buf,strlen(buf)+1)<0){
			perror("Write failed\n");
			exit(EXIT_FAILURE);
		}
		if(read(cfd,buf,sizeof(buf))<0){
			perror("Write failed\n");
			exit(EXIT_FAILURE);
		}
		printf("Modified string is %s ",buf);
		close(cfd);
}
		
