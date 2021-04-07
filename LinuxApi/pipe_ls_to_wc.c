#include "headers.h"

#define MAXBUF 256

int main(void) {
    int fds[2]; /* buffer for pipe file descrp */
    if (pipe(fds) < 0) {
        perror("pipe failed");
        exit(1);
    }
    switch (fork()) {
    case -1:
        perror("fork failed");
        break;
    case 0:
        close(fds[0]);
        dup2(fds[1], 1);
        close(fds[1]);
        execlp("ls", "ls", NULL);
        perror("exec ls failed");
        break;
    default:
        close(fds[1]);
        dup2(fds[0], 0);
        close(fds[0]);
        execlp("wc", "wc", NULL);
        perror("exec wc failed");
        break;
    }
}
