#include "custom.h"
char *rev(char *s){

	char* r=(char *)malloc(MAX*sizeof(char));
	int n=strlen(s);
	int i=0;
	int j=0;
	for(i=n-1;i>=0;i--)r[j++]=s[i];
	r[j]='\0';
	return r;
	
}
void main(){
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(PORT);
	server.sin_addr.s_addr=INADDR_ANY;
	int l=sizeof(server);
	//memset(&server, 0, sizeof(server));
	bind(sfd,(struct sockaddr*)&server,l);
	listen(sfd,20);
	while(true){
		int cfd=accept(sfd,NULL,NULL);
		char buf[MAX];
		char ans[MAX];
		read(cfd,buf,sizeof(buf));
		printf("String received from client is %s\n",buf);
		
		strcpy(ans,rev(buf));
		printf("Modified string sent to client is %s\n",ans);
		write(cfd,ans,strlen(ans)+1);
		
		close(cfd);		
	}
	close(sfd);
}
/*
#include "custom.h"

char *rev(char *s) {
    char *r = (char *)malloc(MAX * sizeof(char));
    int n = strlen(s);
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        r[j++] = s[i];
    }
    r[j] = '\0';
    return r;
}

int main() {
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    if (listen(sfd, 20) < 0) {
        perror("Listen failed");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        int cfd = accept(sfd, NULL, NULL);
        if (cfd < 0) {
            perror("Accept failed");
            continue;
        }

        char buf[MAX];
        memset(buf, 0, sizeof(buf));
        if (read(cfd, buf, sizeof(buf)) < 0) {
            perror("Read from client failed");
            close(cfd);
            continue;
        }

        printf("String received from client: %s\n", buf);

        char *ans = rev(buf);
        printf("Modified string sent to client: %s\n", ans);
        if (write(cfd, ans, strlen(ans) + 1) < 0) {
            perror("Write to client failed");
        }

        free(ans);
        close(cfd);
    }

    close(sfd);
    return 0;
}
*/
	
