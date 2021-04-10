#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


int createSocket(int socketType)
{
    int sockFd = socket(AF_INET, socketType, 0);
    if (sockFd == -1) {
        perror("socket failed");
        exit(1);
    }
    return sockFd;
}

struct sockaddr_in getAddress(const char* ip, int port)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    return addr;
}

void sendMessage(int sockfd, struct sockaddr_in address, const char* msg)
{
    int n;
    n = sendto(sockfd,
               msg, 
               strlen(msg),
               0,
               (struct sockaddr*) &address, 
               sizeof(address));
  if (n < 0)
  {
      perror("sendto failed");
      exit(1);
  }
}

void writeToPort(int sockFd, int port)
{
    char msg[50];
    sprintf(msg, "Message from datagram sender on port %i", port);
    struct sockaddr_in addr;
    addr = getAddress("127.0.0.1", port);
    sendMessage(sockFd, addr, msg);
}

int main(int argc, char *argv[])
{
    int sockFd = createSocket(SOCK_DGRAM);
    srand(time(NULL));
    for(int i = 0; i < 20; i++)
    {
        sleep(1);
        int numberOfSockets = 5;
        int r = rand(); 
        int port = 2000 + r % numberOfSockets;   
        printf("writing to port %i\n", port);  
        writeToPort(sockFd, port);
    }
    return 0;
}
