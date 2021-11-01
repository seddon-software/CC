#include <stdio.h>
#include <wchar.h>
#include <uchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// This example doesn't work inside VSCode.  It must be run on a terminal.

// Note: stdout can only be in narrow OR wide orientation
//       The first output statement decides

#define SIZE 64
    
char path[SIZE];

char* getTerminalName()
{
    FILE *fp = popen("tty", "r");
    if (fp == NULL) printf("can't open pipe\n");

    while (fgets(path, SIZE, fp) != NULL) 
        ;// do nothing
    pclose(fp);
    path[strlen(path)-1] = 0; // remove '\n'
    return path;
}

int main()
{
    setlocale(LC_ALL, NULL);
    const char* multibyteStr = "АБВГДЕЖЗИЙКЛ";
    const wchar_t* wideStr = L"АБВГДЕЖЗИЙКЛ";

    printf("Narrow string: %s\n", multibyteStr);  // sets narrow orientation
    
    // freopen() is the only way to change the narrow/wide orientation of a stream once it has been 
    // established by an I/O operation or by fwide().  A reopened stream has no orientation
    if (freopen(getTerminalName(), "w", stdout) == NULL)
    {
       perror("freopen() failed");
       return EXIT_FAILURE;
    }
 
    wprintf(L"Wide string: %ls\n", wideStr); // sets wide orientation
}
