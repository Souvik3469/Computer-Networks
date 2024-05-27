#include "custom.h"

char *rev(char *s){

	char* r=(char *)malloc(MAX*sizeof(char));
	int n=strlen(s);
	int i=0;
	int j=0;
	for(i=n-1;i>=0;i--)r[j++]=s[i];
	r[j]='\0';
	return r;
	
}

void main(){
	int sfd;
	char buf[MAX];
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in server;
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr(ip);
	server.sin_port=htons(PORT);
	int l=sizeof(server);
	bind(sfd,(struct sockaddr*)&server,l);
	
	listen(sfd,5);
	while(true){
		
		recvfrom(sfd,buf,MAX,0,(struct sockaddr*)&server,&l);
		printf("Server receiving original string from client is %s\n",buf);
		char ans[MAX];
		strcpy(ans,rev(buf));
		printf("Server sending modified string is %s\n",ans);
		sendto(sfd,ans,strlen(ans)+1,0,(struct sockaddr*)&server,l);
		
	}
	close(sfd);	
}
