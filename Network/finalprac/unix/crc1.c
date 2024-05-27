#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
#define MAX 100

typedef struct{
	char dw[MAX];
	char gen[MAX];
}Word;
char* crc(char *gen,char *dw){
	
	int m=strlen(gen);
	int n=strlen(dw);
	int i=0;
	int j=0;
	char rem[100];
	//char *rem=(char*)malloc(100*sizeof(char));
	
	for(i=0;i<m;i++)rem[i]=dw[i];
	
	for(i=m;i<=n;i++){
		if(rem[0]=='1'){
			for(j=1;j<m;j++)rem[j]=rem[j]==gen[j]?'0':'1';
		}
		for(j=0;j<m-1;j++)rem[j]=rem[j+1];
		rem[j]=dw[i];
	}
	rem[m]='\0';
	char *res=(char*)malloc(100*sizeof(char));
	
	j=0;
	for(i=0;i<n;i++){
		if(i<=n-m)res[i]=dw[i];
		else res[i]=rem[j++];
	}
	res[i]='\0';
	return res;
}

void main(){
	Word w;
	
	
	printf("Enter the dw\n");
	//fgets(w.dw,MAX,stdin);
	scanf(" %[^\n]s",w.dw);
	printf("ENter the gen\n");
	scanf(" %[^\n]s",w.gen);
	//fgets(w.gen,MAX,stdin);
	char ans[MAX];
	int i=0;
	int n=strlen(w.dw);
	int m=strlen(w.gen);
	for(i=n;i<n+m-1;i++)w.dw[i]='0';
	printf("bufff %s",w.dw);
	strcpy(ans,crc(w.gen,w.dw));
	printf("Codeword %s",ans);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
				
