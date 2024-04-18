#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<pthread.h>

#define MAX 1024
#define ip "127.0.0.1"
#define S_PORT 8001
#define D_PORT 8002

int fd1;
struct sockaddr_in caddr;
int chatactive=1;
void *sender(){
	char buf[MAX];
	while(chatactive){
	//printf("User1: ");
	fgets(buf,MAX,stdin);
	int l=sizeof(caddr);
	sendto(fd1,buf,strlen(buf)+1,0,(struct sockaddr*)&caddr,l);
	if(strcmp("STOP\n",buf)==0){
		chatactive=0;
		pthread_exit(NULL);
	}
	}
}
void *receiver(){
	char buf[MAX];
	while(chatactive){
	
	int l=sizeof(caddr);
	recvfrom(fd1,buf,MAX,0,(struct sockaddr*)&caddr,&l);
	printf("\nUser2: %s",buf);

	if(strcmp("STOP",buf)==0){
		chatactive=0;
		pthread_exit(NULL);
	}
	}
}

void main(){
	pthread_t t1,t2;
	fd1=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in saddr,daddr;
	saddr.sin_family=AF_INET;
	saddr.sin_addr.s_addr=inet_addr(ip);
	saddr.sin_port=htons(S_PORT);
	
	daddr.sin_family=AF_INET;
	daddr.sin_addr.s_addr=inet_addr(ip);
	daddr.sin_port=htons(D_PORT);
	
	bind(fd1,(struct sockaddr *)&saddr,sizeof(saddr));
	caddr=saddr;
	pthread_create(&t1,NULL,sender,NULL);
	pthread_create(&t2,NULL,receiver,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Chat terminated...\n");
}
