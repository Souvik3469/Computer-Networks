#include "custom1.h"

void main(){
	int reuse=1;
	int enable=1;
	char buf[MAX];
	struct sockaddr_in b;
	int fd1=socket(AF_INET,SOCK_DGRAM,0);
	setsockopt(fd1,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	setsockopt(fd1,SOL_SOCKET,SO_BROADCAST,&enable,sizeof(enable));
	bzero(&b,sizeof(b));
	b.sin_family=AF_INET;
	b.sin_addr.s_addr=INADDR_BROADCAST;
	b.sin_port=htons(PORT);
	
	connect(fd1,(struct sockaddr*)&b,sizeof(b));
	while(true){
		bzero(buf,sizeof(buf));
		printf("Enter message to be broadcasted\n");
		scanf(" %[^\n]s",buf);
		sendto(fd1,buf,strlen(buf)+1,0,(struct sockaddr*)&b,sizeof(b));
		if(!strcmp(buf,"QUIT"))break;
		
	}
	printf("Broadcast terminated by sender\n");
	close(fd1);
	
}
