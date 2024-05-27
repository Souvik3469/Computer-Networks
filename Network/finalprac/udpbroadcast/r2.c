#include "custom1.h"

void main(){
	int reuse=1;
	int enable=1;
	char buf[MAX];
	struct sockaddr_in b;
	int fd1=socket(AF_INET,SOCK_DGRAM,0);
	setsockopt(fd1,SOL_SOCKET,SO_BROADCAST,&enable,sizeof(enable));
	setsockopt(fd1,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	
	bzero(&b,sizeof(b));
	b.sin_family=AF_INET;
	b.sin_addr.s_addr=INADDR_BROADCAST;
	b.sin_port=htons(PORT);
	int l=sizeof(b);
	bind(fd1,(struct sockaddr*)&b,sizeof(b));
	while(true){
		bzero(buf,sizeof(buf));
		recvfrom(fd1,buf,MAX,0,(struct sockaddr*)&b,&l);
		printf("Broadcasted message is %s\n",buf);
		
		
		if(!strcmp(buf,"QUIT"))break;
		
	}
	printf("Broadcast terminated by sender\n");
	close(fd1);
	
}
