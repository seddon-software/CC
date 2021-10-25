#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>


#define MAXBUF 1024
#define SA(S) ((struct sockaddr*)&S)
#define CLEAR(S) memset((void *)&(S), '\0', sizeof((S)));

int createSocket(int socketType)
{
    int sockFd = socket(AF_INET, socketType, 0);
    if (sockFd == -1) {
        perror("socket failed");
        exit(1);
    }
    return sockFd;
}

struct sockaddr_in bindSocket(int sockFd, int port)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    int reuse = 1;
    if (setsockopt(sockFd, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");

    if (bind(sockFd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        perror("socket failed");
        exit(1);
    }
    return addr;
}

void getMessage(int sockFd, struct sockaddr_in addr)
{
    struct hostent *host;
    char buffer[MAXBUF + 1];
    int addrlen, n; 
    CLEAR(addr);
    addrlen = sizeof(addr);
    n = recvfrom(sockFd, buffer, MAXBUF, 0, (struct sockaddr*) &addr,
            (socklen_t*) &addrlen);

    if (n > 0) {
        host = gethostbyaddr(
                   (char*) &addr.sin_addr, 
                   sizeof(struct in_addr),
                   AF_INET);
        if (host)
            printf("Client: %s\n", host->h_name);
        printf("IP addr: %s\n", inet_ntoa(addr.sin_addr));
        buffer[n] = '\0';
        printf("Data: %s\n", buffer);
    } else if (n < 0) {
        perror("recvfrom failed");
        exit(1);
    }
}

void readOnPort(int sockFd, struct sockaddr_in addr)
{
    getMessage(sockFd, addr);
}
int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void) {
    fd_set rfds;
    struct timeval tv;

    int sockFd1 = createSocket(SOCK_DGRAM);
    int sockFd2 = createSocket(SOCK_DGRAM);
    int sockFd3 = createSocket(SOCK_DGRAM);
    int sockFd4 = createSocket(SOCK_DGRAM);
    int sockFd5 = createSocket(SOCK_DGRAM);
    int maxFd;
    maxFd = max(0, sockFd1);
    maxFd = max(maxFd, sockFd2);
    maxFd = max(maxFd, sockFd3);
    maxFd = max(maxFd, sockFd4);
    maxFd = max(maxFd, sockFd5);
    printf("maxFd=%i\n", maxFd);

    struct sockaddr_in addr1 = bindSocket(sockFd1, 2000);
    struct sockaddr_in addr2 = bindSocket(sockFd2, 2001);
    struct sockaddr_in addr3 = bindSocket(sockFd3, 2002);
    struct sockaddr_in addr4 = bindSocket(sockFd4, 2003);
    struct sockaddr_in addr5 = bindSocket(sockFd5, 2004);

    while(1)
    {
        FD_ZERO(&rfds);
        FD_SET(sockFd1, &rfds);
        FD_SET(sockFd2, &rfds);
        FD_SET(sockFd3, &rfds);
        FD_SET(sockFd4, &rfds);
        FD_SET(sockFd5, &rfds);
        tv.tv_sec =  10;
        tv.tv_usec = 0;

        int selectStatus = select(maxFd+1, &rfds, NULL, NULL, &tv);
        if (selectStatus == -1)
            perror("select()");
        else if (selectStatus) {
            printf("Data is available now.\n");
            if (FD_ISSET(sockFd1, &rfds)) getMessage(sockFd1, addr1);
            if (FD_ISSET(sockFd2, &rfds)) getMessage(sockFd2, addr2);
            if (FD_ISSET(sockFd3, &rfds)) getMessage(sockFd3, addr3);
            if (FD_ISSET(sockFd4, &rfds)) getMessage(sockFd4, addr4);
            if (FD_ISSET(sockFd5, &rfds)) getMessage(sockFd5, addr5);
        } else {
            printf("No data within 10 seconds, exiting ...\n");
            exit(0);
        }
    }
    return 0;
}
