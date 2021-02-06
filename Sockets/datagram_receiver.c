#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXBUF 1024
#define SA(S) ((struct sockaddr*)&S)
#define CLEAR(S) memset((void *)&(S), '\0', sizeof((S)));


int main(void) {
    char buffer[MAXBUF + 1];
    struct sockaddr_in addr;
    struct hostent *host;
    size_t addrlen;
    int n;

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(2000);
    addr.sin_addr.s_addr = INADDR_ANY;

    int reuse = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");

    if (bind(sockfd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        perror("socket failed");
        exit(1);
    }

    CLEAR(addr);
    addrlen = sizeof(addr);
    n = recvfrom(sockfd, buffer, MAXBUF, 0, (struct sockaddr*) &addr,
            (socklen_t*) &addrlen);

    if (n > 0) {
        host = gethostbyaddr((char*) &addr.sin_addr, sizeof(struct in_addr),
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

    return 0;
}
