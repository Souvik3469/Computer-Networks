#include "custom.h"

void main(){
	
	char buf[MAX];
	struct sockaddr_un client;
	int cfd;
	printf("Enter the string\n");
	fgets(buf,MAX,stdin);
	cfd=socket(AF_UNIX,SOCK_STREAM,0);
	//memset(&client,0,sizeof(client));
	client.sun_family=AF_UNIX;
	strcpy(client.sun_path,SOCKET_PATH);
	
	connect(cfd,(struct sockaddr*)&client,sizeof(client));
	printf("Client sending string to server is %s\n",buf);
	write(cfd,buf,strlen(buf)+1);
	read(cfd,buf,sizeof(buf));
	printf("Client receiving modified string is %s\n",buf);
	close(cfd);
}
	
