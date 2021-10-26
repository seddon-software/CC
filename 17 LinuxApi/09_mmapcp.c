#include "headers.h"
#include <sys/mman.h>

#define NOMAP ((void*) -1)
#define PERMS (S_IRWXU|S_IRWXG|S_IRWXO)

#define SOURCE "data/source"
#define DESTINATION "data/destination"

int main(void) {
    int target, source, len;
    char *src, *dest;
    struct stat statbuf;

    source = open(SOURCE, O_RDONLY);
    if (source < 0) {
        perror(SOURCE);
        exit(1);
    }

    if (fstat(source, &statbuf) < 0) {
        perror("file stat failed");
        exit(1);
    }

    len = statbuf.st_size;

    target = open(DESTINATION, O_RDWR | O_CREAT, statbuf.st_mode & PERMS);
    if (target < 0) {
        perror(DESTINATION);
        exit(1);
    }

    // clear all data from desination file
    if (ftruncate(target, len) < 0) {
        perror("failed to truncate file");
        exit(1);
    }

    /*
     * Normally with file I/O we open a file and then use read() and write() calls.
     * However, when we do this the kernel reads data from disk into kernel memory
     * pages, before transferring a copy of the page to the running process.  This
     * saves the kernel from having to reload pages from disk if another process
     * opens the same file.  Thus data read from disk is double buffered.
     * 
     * The idea behind memory mapping is to avoid the double buffering and instead 
     * transfer data from the device driver directly into a process's memory using
     * the region between the heap and the stack (the 'Hole').
     */

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

    // now the files are mapped into out address space there is no need
    // to use read() and write() calls and hence we can close file descriptors.
    // Data will be transfered back to disk by the kernel during its normal
    // paging out operation.
    close(source);
    close(target);

    // now just copy the data in memory.  The kernel guarantees to page out the 
    // data within 30 seconds.
    memcpy(dest, src, len);
}
