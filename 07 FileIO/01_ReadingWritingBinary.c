/*
############################################################
#
#    binary data
#
############################################################
*/

#include <stdio.h>
#include <stdlib.h>

// note: BUFFER_SIZE must be >= size of file
enum { BUFFER_SIZE = 512 };

typedef unsigned char BYTE;

void writeBinary(const char* fileName, BYTE data[], int length)
{
    FILE* fp = fopen(fileName, "wb");
    fwrite(data, sizeof(unsigned char), length, fp);
    fclose(fp);
}

void readBinary(const char* fileName)
{
    BYTE data[BUFFER_SIZE];
    FILE* fp = fopen(fileName, "rb");
    size_t bytesRead = fread(data, sizeof(unsigned char), BUFFER_SIZE, fp);
    fclose(fp);
    printf("read back: ");
    for(size_t i = 0; i < bytesRead; i++)
        printf("%i ", data[i]);
    fflush(stdout);
}

int main(void)
{
    const char* FILENAME = "myfile-1.bin";
    BYTE out[] = "\x50\x51\x52\x53\x54\x55\x56\x57\x58\x59\x5A\x5B\x5C\x5D\x5E\x5F\x60\x61";
    writeBinary(FILENAME, out, sizeof(out));    
    readBinary(FILENAME);
}

