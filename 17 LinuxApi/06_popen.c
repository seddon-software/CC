#include "headers.h"

int main(void) {
    char buffer[1024];
    FILE *pipe_h = popen("tar -tvf tarfile", "r");

    while (fgets(buffer, 1024, pipe_h)) {
        fputs(buffer, stdout);
    }

    printf("Command exit status %d\n", pclose(pipe_h));
}
