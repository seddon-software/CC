#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAXBUF 1024

void CHLDhandler(int sig) {
    while (waitpid(0, NULL, WNOHANG) > 0) {
    }
}

void TERMhandler(int sig) {
    printf("Server closing down\n");
    exit(0);
}

int createSocket()
{
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }
    return sockfd;
}

struct sockaddr_in bindToAddress(int sockfd, int port)
{
    int reuse = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2000);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        perror("socket failed");
        exit(1);
    }
    return addr;
}

void setupListenBuffer(int sockfd)
{
    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(1);
    }
}

int acceptConnections(int sockfd, struct sockaddr_in addr, int* pResult)
{
    int commfd;
    size_t addrlen;
    addrlen = sizeof(addr);
    commfd = accept(sockfd, (struct sockaddr*) &addr,
            (socklen_t*) &addrlen);

    if (commfd < 0) {
        if (errno != EINTR) {
            perror("accept failed");
            exit(1);
        }
    }
    *pResult = errno;
    return commfd;
}

// STREAM SERVER
int main(int argc, char *argv[]) {
    char buffer[MAXBUF];
    struct sockaddr_in addr;
    struct hostent *host;
    int n, result;
    int pid, sockfd, commfd;

    signal(SIGCHLD, CHLDhandler);
    signal(SIGTERM, TERMhandler);

    sockfd = createSocket();
    addr = bindToAddress(sockfd, 2001);
    setupListenBuffer(sockfd);

    for (;;) { // Loop waiting for requests and servicing them
        commfd = acceptConnections(sockfd, addr, &result);
        if (result == EINTR) continue;   // Just a minor interruption, go back and wait again...

            /* Print message to say who is calling... */

        host = gethostbyaddr((char*) &addr.sin_addr, sizeof(struct in_addr),
                AF_INET);
        printf("Connection from host %s (%s) on port %d\n",
                host ? host->h_name : inet_ntoa(addr.sin_addr),
                inet_ntoa(addr.sin_addr), addr.sin_port);

        /* Now deal with the request */

        switch (pid = fork()) {
        case -1:
            perror("fork failed");
            exit(1);

        case 0:
            /* Child process - handle request */
            close(sockfd);

            while ((n = read(commfd, buffer, MAXBUF)) > 0) {
                printf("Message; %s\n", buffer);
            }

            if (n < 0) {
                perror("read failed");
                exit(1);
            }
            exit(0);

        default:
            /* Parent process - go back and wait for next request */
            close(commfd);

        }
    }
    return 0;
}
