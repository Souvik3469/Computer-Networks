#include "custom.h"

void main(){

	struct sockaddr_in b;
	int fd1=socket(AF_INET,SOCK_DGRAM,0);
	int reuse=1;
	int enable=1;
	setsockopt(fd1,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	setsockopt(fd1,SOL_SOCKET,SO_BROADCAST,&enable,sizeof(enable));
	bzero(&b,sizeof(b));
	char buf[MAX];
	b.sin_family=AF_INET;
	b.sin_port=htons(PORT);
	b.sin_addr.s_addr=INADDR_BROADCAST;
	
	while(true){
		bzero(buf,sizeof(buf));
		printf("Enter message to be broadcasted ");
		scanf(" %[^\n]s",buf);
		sendto(fd1,buf,strlen(buf),0,(struct sockaddr*)&b,sizeof(b));
		if(!strcmp(buf,"QUIT"))break;
	}
	printf("Sender terminating the broadcast....\n");
	close(fd1);
}
