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

char *rev(char *s){
	int n=strlen(s);
	int i=0;
	int j=0;
	char *ans=(char *)malloc(MAX*sizeof(char));
	
	for(i=n-1;i>=0;i--)ans[j++]=s[i];
	ans[j]='\0';
	return ans;
}
void main(){
	int clientfd,serverfd;
	serverfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server,client;
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=INADDR_ANY;
	bind(serverfd,(struct sockaddr*)&server,sizeof(server));
	printf("Server socket created and ready to receive the string from client\n");
	listen(serverfd,20);
	while(true){
	clientfd=accept(serverfd,NULL,NULL);
		char buf[MAX];
	read(clientfd,buf,sizeof(buf));
	printf("String received from client %s\n",buf);
	char ans[MAX];
	strcpy(ans,rev(buf));

	printf("Modified string sent to the client %s\n",ans);
	write(clientfd,ans,strlen(ans));
	close(clientfd);
	}
	close(serverfd);
}
