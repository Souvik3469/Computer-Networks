#include "custom1.h"

void main(){
char buf[MAX];
	int cfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in client;
	client.sin_family=AF_INET;
	client.sin_port=htons(PORT);
	client.sin_addr.s_addr=inet_addr(ip);
	
	if(connect(cfd,(struct sockaddr*)&client,sizeof(client))<0){
		perror("Connection failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("ENter the string\n");
	fgets(buf,MAX,stdin);
	int l=sizeof(client);
	if(sendto(cfd,buf,strlen(buf)+1,0,(struct sockaddr*)&client,l)<0){
		perror("Send failed\n");
		exit(EXIT_FAILURE);
	}
	if(recvfrom(cfd,buf,sizeof(buf),0,(struct sockaddr*)&client,&l)<0){
		perror("Received failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Modified string received from server %s",buf);
	close(cfd);
}
