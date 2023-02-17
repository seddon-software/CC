#include "headers.h"
extern int opterr;
extern int optopt;
extern int optind;


/*
 * Display file details similar to the ls -l command
 * it recognises -i (inode), -l (long ) options
 */

void print_headings(void);
void showfile(const char*);
int lflag = 0, iflag = 0;

int main(int argc, char *argv[]) {
    int i;
    char ch;

    // simulate command line in vscode:   12_ls.exe -l -i 12_ls.c 12_ls.exe
    if(argc == 1) {
        argc = 5;
        argv[0] = "12_ls.exe";
        argv[1] = "-l";
        argv[2] = "-i";
        argv[3] = "12_ls.c";
        argv[4] = "..";
    }    

    // Check for -i and -l options
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

    // Process the remaining arguments, which should be file or directory names
    if (optind == argc) {
        printf("Please supply at least one pathname\n");
        exit(1);
    }

    print_headings();
    for (i = optind; i < argc; i++)
        showfile(argv[i]);
}

void print_headings(void) {
    printf("%8s", "inode#");
    printf("%10s", "perms");
    printf("%13s", "size");
    printf("%10s", "fileName");
    printf("\n");
}

// Display details of file specified in argument
void showfile(const char *filename) {
    struct stat statBuffer;
    int rwx;
    char ch = '?';
    char outstr[10];

    if (stat(filename, &statBuffer) < 0) {
        perror(filename);
        return;
    }

    // Inode number (if required)
    if (iflag)
        printf("%8lu  ", statBuffer.st_ino);

    // Permissions and type (if required)
    if (lflag) {
        mode_t m = statBuffer.st_mode;
        if (S_ISDIR(m)) ch = 'd';
        if (S_ISCHR(m)) ch = 'c';
        if (S_ISBLK(m)) ch = 'b';
        if (S_ISREG(m)) ch = '-';
        if (S_ISFIFO(m)) ch = 'f';
        if (S_ISLNK(m)) ch = 'l';
        putchar(ch);

        // print access permissions
        rwx = statBuffer.st_mode & ( S_IRWXU | S_IRWXG | S_IRWXO);

        // user permissions
        outstr[0] = ((rwx & S_IRUSR) ? 'r' : '-');
        outstr[1] = ((rwx & S_IWUSR) ? 'w' : '-');
        outstr[2] = ((rwx & S_IXUSR) ? 'x' : '-');
        // group permissions
        outstr[3] = ((rwx & S_IRGRP) ? 'r' : '-');
        outstr[4] = ((rwx & S_IWGRP) ? 'w' : '-');
        outstr[5] = ((rwx & S_IXGRP) ? 'x' : '-');
        // other permissions
        outstr[6] = ((rwx & S_IROTH) ? 'r' : '-');
        outstr[7] = ((rwx & S_IWOTH) ? 'w' : '-');
        outstr[8] = ((rwx & S_IXOTH) ? 'x' : '-');
        outstr[9] = '\0';

        printf("%10s", outstr);

        // file size
        int length = statBuffer.st_size;
        printf("%10i", length);

    }
    printf("  %-20s\n", filename);
}

