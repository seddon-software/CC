#include "headers.h"
#define MAXBUF 256

int main() {
    int fd, n;
    char buffer[MAXBUF];

    if ((fd = open("fifo", O_RDONLY, 0)) < 0) {
        perror("fifo does not exist");
        exit(1);
    }

    for (;;) {
        if ((n = read(fd, buffer, MAXBUF - 1)) == -1) {
            perror("FIFO read failed");
            exit(1);
        }
        if (n == 0)
            break;
        buffer[n] = '\0';
        printf("Message: %s", buffer);
    }
    close(fd);
}
