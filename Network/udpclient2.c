#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

#define MAX 1024
#define PORT 8080
#define ip "127.0.0.1"

void main(){
	int clientfd,serverfd;
	clientfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in server,client;
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=inet_addr(ip);
	connect(clientfd,(struct sockaddr*)&server,sizeof(server));
	printf("Client socket created and ready to send the string\n");
	char buf[MAX];
	printf("Enter the string\n");
	fgets(buf,MAX,stdin);
	int l=sizeof(server);
	sendto(clientfd,buf,MAX,0,(struct sockaddr*)&server,l);
	printf("Client sent string %s to the server\n",buf);
	recvfrom(clientfd,buf,MAX,0,(struct sockaddr*)&server,&l);
	printf("Modified string received from the server is %s\n",buf);
	close(clientfd);
}
