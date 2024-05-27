#include "custom1.h"

struct sockaddr_in m;
bool fl=false;
char buf[MAX];
int fd1;
int reuse=1;
void *rcv(){
	
	while(true){
		recvfrom(fd1,buf,MAX,0,NULL,NULL);
		if(fl==false)printf("Received %s\n",buf);
		fl=false;
	
	}
	pthread_exit(NULL);
}
void *snd(){
	
	while(true){
		fgets(buf,MAX,stdin);
		fl=true;
		sendto(fd1,buf,strlen(buf)+1,0,(struct sockaddr*)&m,sizeof(m));
		
	
	}
	pthread_exit(NULL);
}



void main(){
	struct ip_mreq req;
	fd1=socket(AF_INET,SOCK_DGRAM,0);
	printf("ENter messages\n");
	pthread_t t1,t2;	
	m.sin_family=AF_INET;
	m.sin_addr.s_addr=inet_addr(ip);
	m.sin_port=htons(PORT);
	
	setsockopt(fd1,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	bind(fd1,(struct sockaddr*)&m,sizeof(m));
	req.imr_multiaddr.s_addr=inet_addr(ip);
	req.imr_interface.s_addr=INADDR_ANY;
	setsockopt(fd1,IPPROTO_IP,IP_ADD_MEMBERSHIP,&req,sizeof(req));
	
	pthread_create(&t1,NULL,rcv,NULL);
	pthread_create(&t2,NULL,snd,NULL);
	pthread_join(t2,NULL);
	pthread_join(t1,NULL);
}
	
