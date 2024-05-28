#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<pthread.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<sys/un.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/ipc.h>
#include<math.h>

#define MAX 1024

void main(){
	char buf[MAX];
	printf("Enter dataword\n");
	scanf(" %[^\n]s",buf);
	
	int m=strlen(buf);
	int p=0;
	while(pow(2,p)<p+m+1)p++;
	int n=p+m;
	
	char ans[n];
	int i=0;
	int j=0;
	for(i=0;i<n;i++){
		if(ceil(log2(n-i))==floor(log2(n-i)))ans[i]='p';
		else ans[i]=buf[j++];
	}
	ans[n]='\0';
	int k=0;
	while(k<p){
		int posi=pow(2,k);
		int i=posi;
		int o=0;
		while(i<=n){
			 j=0;
			while(j<posi){
				if(ans[n-(i+j)]=='1')o++;
				j++;
			}
		i+=(2*posi);
		}
		if(o%2==0)ans[n-posi]='0';
		else ans[n-posi]='1';
	
		k++;
	}
	
	printf("Codeword is %s \n",ans);
}
	
	
	
	
	
