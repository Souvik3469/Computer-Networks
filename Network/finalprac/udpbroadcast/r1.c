#include "custom.h"

void main(){

	struct sockaddr_in r;
	int fd1=socket(AF_INET,SOCK_DGRAM,0);
	int reuse=1;
	int enable=1;
	setsockopt(fd1,SOL_SOCKET,SO_BROADCAST,&enable,sizeof(enable));
	setsockopt(fd1,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	char buf[MAX];
	bzero(&r,sizeof(r));
	r.sin_family=AF_INET;
	r.sin_port=htons(PORT);
	r.sin_addr.s_addr=INADDR_ANY;
	bind(fd1,(struct sockaddr*)&r,sizeof(r));
	
	while(true){
		bzero(buf,sizeof(buf));
		recvfrom(fd1,buf,MAX,0,NULL,NULL);
		printf("Broadcasted message %s\n",buf);
		
		if(!strcmp(buf,"QUIT"))break;
	}
	printf("Broadcast is being terminated....\n");
	close(fd1);
}
