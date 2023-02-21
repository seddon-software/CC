#include <stdio.h>
#include <wchar.h>
#include <uchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



/*
 *  A terminal can operate in wide character or narrow character mode, but not both at the same time.
 *  The first output to the terminal sets the mode and it can't then be changed.  The one exception is 
 *  if we reopen the terminal.  In that case we start again and the next output sets the mode.
 * 
 *  If you attempt to write wide characters to a narrow stream or vice versa you will probably corrupt
 *  the stream.
 * 
 *  Note, I've had trouble with VSCode because its terminal emulator is not standard.  So this example 
 *  might not work inside VSCode, but it will work if run on a proper terminal.
 *
 *  If you try to output both narrow and wide characters without resetting the terminal you will normally 
 *  see some output goes missing or worse still, the stream becomes corrupted.
 */

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

    // the next line sets narrow orientation
    printf("Narrow string: %s\n", multibyteStr);

    // trying to output wide characters will corrupt the stream (uncomment the next line and check)
    // wprintf(L"Wide string: %ls\n", wideStr);
    
    // freopen() is the only way to change the narrow/wide orientation of a stream once it has been 
    // established by an I/O operation or established by fwide().  A reopened stream has no orientation
    if (freopen(getTerminalName(), "w", stdout) == NULL)
    {
       perror("freopen() failed");
       return EXIT_FAILURE;
    }
 
    // the terminal has been reset, so the next line sets wide orientation
    wprintf(L"Wide string: %ls\n", wideStr);
}
