#include "headers.h"

int main(int argc, char *argv[]) {
    struct stat buffer;
    int i;

    for (i = 1; i < argc; i++) {
        char permissions[] = "---";
        int rwx;

        if (stat(argv[i], &buffer) == -1) {
            perror(argv[i]);
            continue;
        }

        printf("%s: size=%ld, ", argv[i], buffer.st_size);

        if (S_ISREG(buffer.st_mode))
            printf("file");
        else if (S_ISDIR(buffer.st_mode))
            printf("directory");
        else if (S_ISFIFO(buffer.st_mode))
            printf("fifo");
        else if (S_ISCHR(buffer.st_mode))
            printf("character device");
        else if (S_ISBLK(buffer.st_mode))
            printf("block device");

        rwx = buffer.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);

        if (rwx & S_IRUSR)
            permissions[0] = 'r';
        if (rwx & S_IWUSR)
            permissions[1] = 'w';
        if (rwx & S_IXUSR)
            permissions[2] = 'x';

        printf(", user permissions: %s \n", permissions);
    }
}
