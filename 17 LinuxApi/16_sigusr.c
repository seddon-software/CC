#include "headers.h"

void handler(int id) {
    if (id == SIGUSR1)
        printf("SIGUSR1\n");
    if (id == SIGUSR2)
        printf("SIGUSR2\n");
}

int main(int argc, char *argv[]) {
    struct sigaction new;
    sigset_t emptymask, procmask;

    printf("%d\n", getpid());
    sigemptyset(&emptymask);
    new.sa_handler = handler;
    new.sa_mask = emptymask;
    new.sa_flags = 0;

    if (sigaction(SIGUSR1, &new, NULL) < 0) {
        perror("sigaction USR1 failed");
        exit(1);
    }
    if (sigaction(SIGUSR2, &new, NULL) < 0) {
        perror("sigaction USR2 failed");
        exit(1);
    }

    sigemptyset(&procmask);
    sigaddset(&procmask, SIGINT);

    if (sigprocmask(SIG_SETMASK, &procmask, NULL) < 0) {
        perror("sigprocmask failed");
        exit(1);
    }

    /* wait for signals */
    for (;;) {
        sigsuspend(&procmask);
        write(1, "...round again...\n", strlen("...round again...\n"));
    }
}
