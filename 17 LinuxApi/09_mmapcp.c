/*
    MAP_SHARED

    Share this mapping. Updates to the mapping are visible to other processes that map this file, and are 
    carried through to the underlying file. The file may not actually be updated until msync(2) or munmap() 
    is called.

    MAP_PRIVATE

    Create a private copy-on-write mapping. Updates to the mapping are not visible to other processes 
    mapping the same file, and are not carried through to the underlying file.
*/

#include "headers.h"

#define NOMAP ((void*) -1)
#define PERMS (S_IRWXU|S_IRWXG|S_IRWXO)

#define SOURCE_FILE "resources/gcc.txt"
#define TARGET_FILE "resources/gcc_copy.txt"

int main() {
    int target, source, len;
    char *src, *dest;
    struct stat statbuf;

    source = open(SOURCE_FILE, O_RDONLY);
    if (source < 0) {
        perror(SOURCE_FILE);
        exit(1);
    }

    if (fstat(source, &statbuf) < 0) {
        perror("file stat failed");
        exit(1);
    }

    len = statbuf.st_size;

    target = open(TARGET_FILE, O_RDWR | O_CREAT, statbuf.st_mode & PERMS);
    if (target < 0) {
        perror(TARGET_FILE);
        exit(1);
    }

    // clear all data from desination file
    if (ftruncate(target, len) < 0) {
        perror("failed to truncate" TARGET_FILE);
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
