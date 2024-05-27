#include "custom.h"

void main(){
	int cfd;
	char buf[MAX];
	
	cfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in client;
	client.sin_family=AF_INET;
	client.sin_addr.s_addr=inet_addr(ip);
	client.sin_port=htons(PORT);
	int l=sizeof(client);
	connect(cfd,(struct sockaddr*)&client,l);
	//while(true){
	
	printf("Enter the string\n");
	fgets(buf,MAX,stdin);
	printf("Client sending string to server is %s\n",buf);
	sendto(cfd,buf,strlen(buf)+1,0,(struct sockaddr*)&client,l);
	recvfrom(cfd,buf,MAX,0,(struct sockaddr*)&client,&l);
	printf("Client receiving modified string is %s\n",buf);
	//}
	close(cfd);
}
