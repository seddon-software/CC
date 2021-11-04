#include "headers.h"

int main(void) {
    sigset_t newset, pending;

    sigemptyset(&newset);
    sigaddset(&newset, SIGINT);
    sigaddset(&newset, SIGQUIT);
    if (sigprocmask(SIG_BLOCK, &newset, NULL) < 0) {
        perror("sigprocmask failed");
        exit(1);
    }

    printf("Press ^C or ^\\ in the next 5 seconds\n");
    sleep(5); /* wait 5 seconds */

    if (sigpending(&pending) < 0) {
        perror("sigpending failed");
        exit(1);
    }

    if (sigismember(&pending, SIGQUIT))
        printf("SIGQUIT is pending\n");
    if (sigismember(&pending, SIGINT))
        printf("SIGINT is pending\n");
    if (!sigismember(&pending, SIGQUIT) && !sigismember(&pending, SIGINT))
        printf("You didn't press either key\n");

    if (sigprocmask(SIG_UNBLOCK, &newset, NULL) < 0) {
        perror("sigprocmask failed");
        exit(1);
    }

    printf("At end of program\n");
    return 0;
}
