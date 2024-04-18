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
	serverfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in server,client;
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=inet_addr(ip);
	bind(serverfd,(struct sockaddr*)&server,sizeof(server));
	printf("Server socket created and ready to receive the string\n");
	
	while(true){
	char buf[MAX];
	
	int l=sizeof(server);
	
	recvfrom(serverfd,buf,MAX,0,(struct sockaddr*)&client,&l);
	printf("String received from client is %s\n",buf);
	char ans[MAX];
	strcpy(ans,rev(buf));
	printf("Modified string sent to the client is %s\n",ans);
	sendto(serverfd,ans,MAX,0,(struct sockaddr*)&client,l);
	

	}
	
		close(serverfd);
}
