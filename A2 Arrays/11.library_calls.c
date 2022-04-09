/*
 *  C has a set of library functions to help you work with C-Strings.  To use these functions, include:
 *              #include <string.h>
 * 
 *  In this example we use some of the common library functions, complete with their prototypes:
 *              strlen(char* s)                     : length of s minus the terminator
 *              strcpy(char* t, const char* s)      : copy s into t 
 *              strcat(char* t, const char* s)      : append s to t
 *              puts(const char*);
 * 
 *  Where we say, const char*, we are stating that the parameter will not be changed by the function.
 * 
 *  Note, you need to be careful that each target C-String has enough memory allocated when using strcpy and strcat.  You can
 *  see how awkward it is to build a new string from other strings: 
 *              strcpy(hello_world, hello);
 *              strcat(hello_world, " ");
 *              strcat(hello_world, world);
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char hello[] = "Hello";
    int size1 = strlen(hello);
    char copy[size1+1];              // add 1 for the null terminator
    strcpy(copy, hello);             // like target = source

    puts(hello);
    puts(copy);

    char world[] = "World";
    int size2 = strlen(hello);

    char hello_world[size1+size2+2]; // add 1 for a space and 1 for the null terminator 
    strcpy(hello_world, hello);
    strcat(hello_world, " ");
    strcat(hello_world, world);
    puts(hello_world);
}

