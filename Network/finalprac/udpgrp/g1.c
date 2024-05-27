#include "custom.h"

int reuse=1;
int fd1;
struct sockaddr_in m;
char buf[MAX];
bool fl=false;

void *rcv(void *args){
	
	while(true){
		recvfrom(fd1,buf,MAX,0,NULL,NULL);
		if(fl==false)printf("Received %s",buf);
		fl=false;
	}
	pthread_exit(NULL);
}

void *snd(void *args){
	
	while(true){
		fgets(buf,MAX,stdin);
		fl=true;
		sendto(fd1,buf,strlen(buf)+1,0,(struct sockaddr*)&m,sizeof(m));
	}
	pthread_exit(NULL);
}


void main(){
	struct ip_mreq req;
	pthread_t t1,t2;
	printf("Enter messages\n");
	
	m.sin_family=AF_INET;
	m.sin_port=htons(PORT);
	m.sin_addr.s_addr=inet_addr(ip);
	fd1=socket(AF_INET,SOCK_DGRAM,0);
	setsockopt(fd1,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	bind(fd1,(struct sockaddr*)&m,sizeof(m));
	req.imr_multiaddr.s_addr=inet_addr(ip);
	req.imr_interface.s_addr=INADDR_ANY;
	setsockopt(fd1,IPPROTO_IP,IP_ADD_MEMBERSHIP,&req,sizeof(req));
	pthread_create(&t1,NULL,(void*)&rcv,NULL);
	pthread_create(&t2,NULL,(void*)&snd,NULL);
	pthread_join(t2,NULL);
	pthread_join(t1,NULL);
}
	
