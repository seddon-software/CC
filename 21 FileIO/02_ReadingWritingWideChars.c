/*
############################################################
#
#    wchar_t data
#
############################################################
*/

#include <wchar.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


extern int errno;

int writeWideChars(const char* fileName)
{
    setlocale(LC_ALL, "en_GB.utf8");
    wchar_t data[] = L"αβγδεζηθικλμνξοπρςστυφχψω"; 
    int size = sizeof(data)/sizeof(wchar_t) - 1;  // account for trailing \0
    
    FILE* fp = fopen(fileName, "w");
    if(fp == NULL)
    {
        char message[100];
        sprintf(message, "can't open %s for reading", fileName);
        perror(message);
        return EXIT_FAILURE;
    }

    int i = 0;
    while(i < size)
    {
        fputwc(data[i], stdout);
        fflush(stdout);
        int result = fputwc(data[i], fp);
        if (result == WEOF) 
        {
            if (errno == EILSEQ)
                puts("Encoding error in fputwc.");
            else
                puts("I/O error in fputwc.");
            return EXIT_FAILURE;
        }
        i++;
    }
    fputwc(L'\n', fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

int readWideChars(const char* fileName)
{
    FILE* fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        char message[100];
        sprintf(message, "can't open %s for reading", fileName);
        perror(message);
        return EXIT_FAILURE;
    }
    wint_t wc;
    errno = 0;
    while ((wc = fgetwc(fp)) != WEOF)
        putwchar(wc);
 
    if (ferror(fp)) {
        if (errno == EILSEQ)
            puts("Character encoding error while reading.");
        else
            puts("I/O error when reading");
    } else if (feof(fp))
        puts("End of file reached successfully");
    return EXIT_SUCCESS;
}

int main(void)
{
    const char* FILENAME = "myfile-2.wchar";
    writeWideChars(FILENAME);
    readWideChars(FILENAME);

    // check file type is UTF-8
    char cmd[100] = "";
    strcpy(cmd, "file ");
    strcat(cmd, FILENAME); 
    system(cmd);
}

