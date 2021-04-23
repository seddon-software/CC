#include "headers.h"

#define MAXBUF 256

int main(void) {
    int fds[2]; /* buffer for pipe file descriptor */
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
   printf("%d\n", getpid());
    switch (fork()) {
    case -1:
        perror("fork failed");
        break;
    case 0:
        printf("We are now in the child\n");
        close(fds[0]);      // close the read end of the pipe
        dup2(fds[1], 1);    // copy pipe write descriptor to stdout in file table
        close(fds[1]);
        /* file table now reads:
                0   -> keyboard
                1   -> pipe write end
                2   -> terminal
                3   -> closed
                4   -> closed
        */
        execlp("ls", "ls", NULL);  // "ls" will write to fd 1 (pipe write end)
        perror("exec ls failed");  // should never get here
        break;
    default:
        printf("We are now in the parent\n");
        close(fds[1]);      // close the write end of the pipe
        dup2(fds[0], 0);    // copy pipe read descriptor to stdin in file table
        close(fds[0]);
        /* file table now reads:
                0   -> pipe read end
                1   -> terminal
                2   -> terminal
                3   -> pipe read end
                4   -> pipe write end
        */
        execlp("wc", "wc", NULL);  // "wc" will read from fd 0 (pipe read end)
        perror("exec wc failed");  // should never get here
        break;
    }
}
