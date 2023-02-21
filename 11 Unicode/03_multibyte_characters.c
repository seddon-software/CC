/*
 *  As an alternative to wide mode you can use narrow mode; narrow mode uses multi-byte characters.  When 
 *  working with multi-byte characters you can't print them a character at a time; you print them as part
 *  of a null terminated multibyte string.
 *  
 *  To use the multibyte strings you declare the strings as:
 *      const char*
 * 
 *  and the multibyte strings themselves as:
 *      "...."
 * 
 *  You will notice you can print the Unicode characters themselves or use their code point 
 *  values.  I've copied the Unicode characters in this example from the following website:
 *              https://symbl.cc/en/unicode/blocks/
 * 
 *  When working with code points you use the u and U prefixes.  For example, for 16 bit code points:
 *              const char* star2 = "\u2605"
 *  and for 32 bit code points:
 *              const char* pài2 = "\U000200A2";
 */

#include <stdio.h>
#include <locale.h>


void usingCodePoints()
{
    const char* star = "\u2605";
    const char* pi = "\u03C0";
    const char* hebrew_alef = "\u05D0";
    const char* pài = "\U000200A2";

    // print individual wide characters
    printf("Star :%s\n", star);
    printf("Greek pi: %s\n", pi);
    printf("Hebrew Alef: %s\n", hebrew_alef);
    printf("pài: %s\n", pài);
}

void usingUnicodeSymbols()
{
    char* star = "★";
    char* pi = "π";
    char* hebrew_alef = "א";
    char* pài = "𠂢";

    // print individual wide characters
    printf("Star :%s\n", star);
    printf("Greek pi: %s\n", pi);
    printf("Hebrew Alef: %s\n", hebrew_alef);
    printf("pài: %s\n", pài);
}

int main() 
{
    setlocale(LC_ALL, "");
    usingCodePoints();
    usingUnicodeSymbols();
}
