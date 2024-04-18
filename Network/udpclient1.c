#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

#define MAX 1024
#define ip "127.0.0.1"
#define PORT 8080

void main(){
	int clientfd,serverfd;
	clientfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in server,client;
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=inet_addr(ip);
	int l=sizeof(server);
	connect(clientfd,(struct sockaddr *)&server,sizeof(server));
	printf("Client socket created and preparing to send string\n");
	printf("Enter string\n");
	char buf[MAX];
	fgets(buf,MAX,stdin);
	printf("Client sending the string %s to server\n",buf);
	sendto(clientfd,buf,MAX,0,(struct sockaddr *)&server,l);
	printf("String sent successfully to server\n");
	recvfrom(clientfd,buf,MAX,0,(struct sockaddr *)&server,&l);
	printf("Modified string received from server to client is %s\n",buf);
	close(clientfd);
}
