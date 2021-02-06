#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
  char *msg="Test message from process 2";
  struct sockaddr_in addr;
  int n;
  int sockfd;

  // if(argc != 2) {
  //     printf("useage: datagram_sender <ip-address>\n");
  //     exit(1);
  // }
//  char hostname[33];
//  struct hostent *host;
//  int port;

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0)
  {
    perror("socket failed");
    exit(1);
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(2000);
//  addr.sin_addr.s_addr = inet_addr(argv[1]);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  n=sendto(sockfd,msg,strlen(msg),0,(struct sockaddr*)&addr, sizeof(addr));
  if (n < 0)
  {
    perror("sendto failed");
    exit(1);
  }
  return 0;
}
