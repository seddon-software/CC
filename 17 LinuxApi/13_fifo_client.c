#include "headers.h"
#define MAXBUF 256

int main() {
    int fd, n;
    char buffer[MAXBUF];

    if ((fd = open("fifo", O_WRONLY, 0)) < 0) {
        perror("fifo does not exist");
        exit(1);
    }

    sprintf(buffer, "Message from client %d\n", getpid());
    n = write(fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write to FIFO failed");
        exit(1);
    }
    close(fd);
}
