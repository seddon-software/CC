#include "headers.h"

/*
 * A version of the "cat" program that uses mmap
 * to gain access to the file being listed.
 */

#define SOURCE_FILE "resources/gcc.txt"

int main(int argc, char *argv[]) {
    int fd, length;
    struct stat sbuf;
    char *data;

    /*
     * The file needs to be opened and we need its size.
     * Should also check that it's a regular file - mmap won't
     * work on other stuff...
     */
    if ((fd = open(SOURCE_FILE, O_RDONLY)) < 0) {
        perror(SOURCE_FILE);
        exit(1);
    }

    // read the inode information and obtain file size
    // note: fstat() uses fds; stat() uses filenames
    if (fstat(fd, &sbuf) < 0) {
        perror("stat");
        exit(1);
    }
    length = sbuf.st_size;

    // use macro to check if regular file
    if (!S_ISREG(sbuf.st_mode)) {
        fprintf(stderr, "%s: not a regular file\n", argv[1]);
        exit(1);
    }

    // Map the file into our address space
    //   and return a pointer to the start of the file's data
    data = mmap(0, length, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == (char *) -1) {
        perror("mmap");
        exit(1);
    }

    // we don't need the file open any more
    close(fd);

    // Now simply copy the contents of the file to stdout
    write(1, data, length);

    exit(0);
}
