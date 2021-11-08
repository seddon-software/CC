#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXBUF 1024
#define PORT 7002
#define CLEAR(S) memset((void*)&S, '\0', sizeof(S))

int createSocket()
{
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }
    return sockfd;
}

void connectToServer(int sockfd, const char* ip, int port)
{
    struct sockaddr_in addr;
    int n;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    n = connect(sockfd, (struct sockaddr*) &addr, sizeof(addr));
    if (n < 0) {
        perror("connect failed");
        exit(1);
    }
}

void writeToServer(int sockfd)
{
    int n;
    char msg[MAXBUF];
    sprintf(msg, "Test message from client [%d]", getpid());
    n = write(sockfd, msg, strlen(msg) + 1);
    if (n < 0) {
        perror("write failed");
        exit(1);
    }
}

// STREAM CLIENT
int main(int argc, char *argv[]) {
    int sockfd;
    int pid;
//    int n;

    for(int i = 0; i < 5; i++)
    {
        pid = fork();
        if(pid > 0) exit(0);  // parent exits, child continues
        sockfd = createSocket();
        connectToServer(sockfd, "127.0.0.1", PORT);
        writeToServer(sockfd);
    }
}
