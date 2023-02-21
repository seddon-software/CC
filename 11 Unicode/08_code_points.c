/*
 *  A Unicode character can be represented by the wide types char32_t and wchar_t.  When we wish to print 
 *  such characters we can choose to print them as wide or narrow characters.  Note that char32_t is 
 *  inheritanly wide and can't be printed as a narrow character, only its code point value can be printed.  
 *  However, we can place the character in a narrow string (when it can be printed with printf).
 * 
 *  No such problem exists in wide mode; we can print our UTF-8 encoded character using wprintf.
 * 
 *  In this example we just print of the code point value of '𠂢'.
 */

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <uchar.h>
#include <locale.h>

mbstate_t ss;    /* set shift state to the initial state */

void print_narrow_info()
{
    char32_t pài = U'𠂢';
    printf("size of char32_t: %li\n", sizeof(char32_t));
    // we can't print this character directly, but we can be print it as part of a string
    printf("code point of 𠂢: %08lx\n", (unsigned long)pài);
}
void print_wide_info()
{
    wchar_t pài = L'𠂢';
    wprintf(L"size of wchar_t: %li\n", sizeof(wchar_t));
    wprintf(L"code point of 𠂢: %08lx\n", (unsigned long)pài); 
}

int main(void)
{
    setlocale(LC_ALL, "");

    // recall you can only use wide or narrow streams, so comment out one of the next two calls
    //print_narrow_info();
    print_wide_info();
}
