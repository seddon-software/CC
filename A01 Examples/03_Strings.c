#include <stdio.h>

int main()
{
    char* t = "ABC";        // string literal, t is on stack, "ABC" in read only memory (text)
    int x = 100;
    char s[3] = "XYZ";       // s is on the stack, s[0], s[1] .. is on stack, "XYZ" is copied from text segment to stack, character array (c-string)
    s[0] = 'x';
//    t[0] = 'a';
    t++;
    printf("%s\n", t);
    printf("%s\n", s);
}