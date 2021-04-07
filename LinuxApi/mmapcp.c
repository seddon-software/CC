#include "headers.h"
#include <sys/mman.h>

#define NOMAP ((void*) -1)
#define PERMS (S_IRWXU|S_IRWXG|S_IRWXO)

int main(int argc, char *argv[]) {
    int target, source, len;
    char *src, *dest;
    struct stat statbuf;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s source dest\n", argv[0]);
        exit(1);
    }

    source = open(argv[1], O_RDONLY);
    if (source < 0) {
        perror(argv[1]);
        exit(1);
    }

    if (fstat(source, &statbuf) < 0) {
        perror("file stat failed");
        exit(1);
    }

    len = statbuf.st_size;

    target = open(argv[2], O_RDWR | O_CREAT, statbuf.st_mode & PERMS);
    if (target < 0) {
        perror(argv[2]);
        exit(1);
    }

    if (ftruncate(target, len) < 0) {
        perror("failed to truncate file");
        exit(1);
    }

    src = mmap(0, len, PROT_READ, MAP_PRIVATE, source, 0);
    dest = mmap(0, len, PROT_WRITE, MAP_SHARED, target, 0);

    if (src == NOMAP) {
        perror("can't map source file");
        exit(1);
    }
    if (dest == NOMAP) {
        perror("can't map target file");
        exit(1);
    }

    close(source);
    close(target);

    memcpy(dest, src, len);
}
