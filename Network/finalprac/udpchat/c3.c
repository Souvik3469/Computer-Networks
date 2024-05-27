// custom.h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define S_PORT_NO 7001
#define D_PORT_NO 7002
#define MAX 100
#define IP "127.0.0.1"

int ss;
bool chat_active = true;
struct sockaddr_in saddr, daddr, caddr;

void* sender(void* args) {
    char buf[MAX];
    while(chat_active) {
        fgets(buf, MAX, stdin);
        int length = sizeof(daddr);
        sendto(ss, buf, strlen(buf) + 1, 0, (struct sockaddr*)&daddr, length);
        if(!strcmp(buf, "stop\n")) {
            chat_active = false;
            pthread_exit(NULL);
        }
    }
    return NULL;
}

void* receiver(void* args) {
    char buf[MAX];
    while(chat_active) {
        int length = sizeof(caddr);
        recvfrom(ss, buf, MAX, 0, (struct sockaddr*)&caddr, &length);
        printf("\nReceived: %s", buf);
        if(!strcmp(buf, "stop")) {
            chat_active = false;
            pthread_exit(NULL);
        }
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    ss = socket(AF_INET, SOCK_DGRAM, 0);
    if (ss < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    int reuse = 1;
    if (setsockopt(ss, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt(SO_REUSEADDR) failed");
        close(ss);
        exit(EXIT_FAILURE);
    }

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr(IP);
    saddr.sin_port = htons(S_PORT_NO);

    daddr.sin_family = AF_INET;
    daddr.sin_addr.s_addr = inet_addr(IP);
    daddr.sin_port = htons(D_PORT_NO);

    if (bind(ss, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
        perror("bind failed");
        close(ss);
        exit(EXIT_FAILURE);
    }

    caddr = daddr;
    pthread_create(&t1, NULL, sender, NULL);
    pthread_create(&t2, NULL, receiver, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Chat terminated...\n");
    close(ss);
    return 0;
}

