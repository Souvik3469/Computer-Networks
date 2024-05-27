#include "custom.h"

void main(){
	int cfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in client;
	// memset(&client, 0, sizeof(client));
	client.sin_family=AF_INET;
	client.sin_port=htons(PORT);
	client.sin_addr.s_addr=inet_addr(ip);
	int l=sizeof(client);
	
	if(connect(cfd,(struct sockaddr*)&client,l)<0){
		perror("Connection failed\n");
		exit(EXIT_FAILURE);
	}
	
		char buf[MAX];
		printf("Enter the string\n");
		fgets(buf,MAX,stdin);
		
		write(cfd,buf,strlen(buf)+1);
		read(cfd,buf,sizeof(buf));
		printf("Modified string from server is %s\n",buf);
		close(cfd);
	
	
}
/*
#include "custom.h"

int main() {
    int cfd = socket(AF_INET, SOCK_STREAM, 0);
    if (cfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons(PORT);
    client.sin_addr.s_addr = inet_addr(ip);

    if (connect(cfd, (struct sockaddr*)&client, sizeof(client)) < 0) {
        perror("Connection failed");
        close(cfd);
        exit(EXIT_FAILURE);
    }

    char buf[MAX];
    printf("Enter the string: ");
    fgets(buf, MAX, stdin);
    buf[strcspn(buf, "\n")] = 0; // Remove newline character

    if (write(cfd, buf, strlen(buf) + 1) < 0) {
        perror("Write to server failed");
        close(cfd);
        exit(EXIT_FAILURE);
    }

    memset(buf, 0, sizeof(buf));
    if (read(cfd, buf, sizeof(buf)) < 0) {
        perror("Read from server failed");
        close(cfd);
        exit(EXIT_FAILURE);
    }

    printf("Modified string from server is: %s\n", buf);
    close(cfd);
    return 0;
}*/

	
