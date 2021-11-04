////////////////////////////////////////////////////////////
//
//
// Notes for vscode:
//     To debug across fork(), these commands have been added to launch.json
//     under "setupCommands":
//         set follow-fork-mode child
//         set detach-on-fork off
//
// To see which processes are being run (use debug console):
//     -exec info inferiors
// To switch processes #2:
//     -exec inferior 2
//
////////////////////////////////////////////////////////////

#include "headers.h"

int main() {
    pid_t pid;

    pid = fork();

    switch (pid) {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            printf("We are now in the child\n");
            printf("The child receives a return code of %d\n", pid);
            printf("Child process pid = %d\n", getpid());
            exit(0);
        default:
            printf("We are now in the parent\n");
            printf("The parent receives a return code of %d\n", pid);
            printf("Parent forked child %d\n", pid);
            break;
    }
    return 0;
}
