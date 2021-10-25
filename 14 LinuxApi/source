#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUF 256

int main() {
    int fds[2]; /* buffer for pipe file descrp */
    char buffer[MAXBUF];
    char *msg = "Test message";

    if (pipe(fds) < 0) {
        perror("pipe failed");
        exit(1);
    }

    switch (fork()) {
    case -1:
        perror("fork failed");
        break;
    case 0:
        close(fds[1]);
        read(fds[0], buffer, MAXBUF);
        printf("Message from child: %s\n", buffer);
        break;
    default:
        close(fds[0]);
        write(fds[1], msg, strlen(msg) + 1);
        break;
    }
    return 0;
}
