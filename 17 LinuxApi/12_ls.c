#include "headers.h"

/*
 * Display file details similar to the ls -l command
 * it recognises -i (inode), -l (long ) options
 */

int lflag = 0, iflag = 0;

int main(int argc, char *argv[]) {
    int i;
    char ch;
    void showfile(char*);

    /*
     * Check for -i and -l options
     */
    opterr = 0;
    while ((ch = getopt(argc, argv, "li")) != EOF) {
        switch (ch) {
        case 'l':
            lflag++;
            break;
        case 'i':
            iflag++;
            break;
        case '?':
            fprintf(stderr, "Unknown option %c\n", optopt);
            fprintf(stderr, "Usage: %s [-ail] pathnames...\n", argv[0]);
            exit(1);
        }
    }

    /*
     * Process the remaining arguments, which should be file or directory names
     */
    if (optind == argc) {
        printf("Please supply at least one pathname\n");
        exit(1);
    }

    for (i = optind; i < argc; i++)
        showfile(argv[i]);
    return 0;
}

/*
 * Display details of file specified in argument
 */
void showfile(char *filename) {
    struct stat buffer;
    int rwx;
    char ch = '?';
    char outstr[10];

    if (stat(filename, &buffer) < 0) {
        perror(filename);
        return;
    }

    /*
     * Inode number (if required)
     */
    if (iflag)
        printf("%5lu  ", buffer.st_ino);

    /*
     * Access permissions and type (if required)
     */
    if (lflag) {
        mode_t m = buffer.st_mode;
        if (S_ISDIR(m)) ch = 'd';
        if (S_ISCHR(m)) ch = 'c';
        if (S_ISBLK(m)) ch = 'b';
        if (S_ISREG(m)) ch = '-';
        if (S_ISFIFO(m)) ch = 'f';
        if (S_ISLNK(m)) ch = 'l';
        putchar(ch);

        /* print access permissions */
        rwx = buffer.st_mode & ( S_IRWXU | S_IRWXG | S_IRWXO);
        /* The bits for the user */
        outstr[0] = ((rwx & S_IRUSR) ? 'r' : '-');
        outstr[1] = ((rwx & S_IWUSR) ? 'w' : '-');
        outstr[2] = ((rwx & S_IXUSR) ? 'x' : '-');
        /* The bits for the group */
        outstr[3] = ((rwx & S_IRGRP) ? 'r' : '-');
        outstr[4] = ((rwx & S_IWGRP) ? 'w' : '-');
        outstr[5] = ((rwx & S_IXGRP) ? 'x' : '-');
        /* The bits for everyone else */
        outstr[6] = ((rwx & S_IROTH) ? 'r' : '-');
        outstr[7] = ((rwx & S_IWOTH) ? 'w' : '-');
        outstr[8] = ((rwx & S_IXOTH) ? 'x' : '-');
        outstr[9] = '\0';

        printf("%s \t", outstr);
    }

    printf("%-20s\n", filename);

}

