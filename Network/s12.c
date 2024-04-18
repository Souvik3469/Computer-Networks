#include "head.h"

void rv(char *s){
	
	int i=0;
	int j=strlen(s)-1;
	while(i<j){
		char t=s[i];
		s[i]=s[j];
		s[j]=t;
		i++;
		j--;
	}
}
void main(){
	struct sockaddr_un server;
	char buff[MAX];
	unlink(path);
	int fs=socket(AF_UNIX,SOCK_STREAM,0);
	if(fs<0){
		perror("Server socket creation failed\n");
		exit(0);
	}
	printf("Server socket created\n");
	memset(&server,0,sizeof(struct sockaddr_un));
	server.sun_family=AF_UNIX;
	strcpy(server.sun_path,path);
	if(bind(fs,(struct sockaddr*)&server,sizeof(struct sockaddr_un))<0){
		perror("Server bind failed\n");
		exit(0);
	}
	if(listen(fs,20)<0){
		perror("Server listen failed\n");
		exit(0);
	}
	while(true){
		int fc=accept(fs,NULL,NULL);
		if(fc<0){
			perror("Server accept failed\n");
			exit(0);
		}
		int n=read(fc,buff,sizeof(buff));
		if(n<0){
			perror("Server read failed\n");
			exit(0);
		}
		rv(buff);
		printf("Modified string from server\n");
		printf("%s\n",buff);
		if(write(fc,buff,n)<0){
			perror("Server write failed\n");
			exit(0);
		}
		
		close(fc);
		
		
		
	}
	close(fs);
	unlink(path);
}
