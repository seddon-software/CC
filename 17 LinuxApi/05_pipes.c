#include "headers.h"


#define MAXBUF 256

int main() {
    int fds[2]; /* buffer for pipe file descriptors */
    char buffer[MAXBUF];
    char *msg = "Test message";

    if (pipe(fds) < 0) {
        perror("pipe failed");
        exit(1);
    }
    /* file table now reads:
    0   -> keyboard
    1   -> terminal
    2   -> terminal
    3   -> pipe read end
    4   -> pipe write end
    */

    switch (fork()) {
    case -1:
        perror("fork failed");
        break;
    case 0:
        printf("We are now in the child\n");
        close(fds[1]);
        printf("child reading from the pipe on fd = %i\n", fds[0]);
        read(fds[0], buffer, MAXBUF);
        printf("Message from child: %s\n", buffer);
        break;
        /* file table now reads:
        0   -> keyboard
        1   -> terminal
        2   -> terminal
        3   -> pipe read end
        4   -> closed
        */

    default:
        printf("We are now in the parent\n");
        close(fds[0]);
        printf("parent writing to the pipe on fd = %i\n", fds[1]);
        write(fds[1], msg, strlen(msg) + 1);
        /* file table now reads:
                0   -> keyboard
                1   -> terminal
                2   -> terminal
                3   -> closed
                4   -> pipe write end
        */
        break;
    }
    return 0;
}
