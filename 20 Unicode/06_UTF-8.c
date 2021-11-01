#include <stdio.h>
#include <wchar.h>
#include <uchar.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define __STDC_ISO_10646__

mbstate_t ss;    /* set shift state to the initial state */

void print_narrow_info()
{
    char32_t russian_Be = 'Б';

    printf("size of char32_t: %i\n", sizeof(char32_t));
    printf("UTF-8 encoding: %i \n", russian_Be);
}
void print_wide_info()
{
    wchar_t russian_Be = 'Б';

    wprintf(L"size of wchar_t: %i\n", sizeof(wchar_t));
    wprintf(L"UTF-8 encoding: %i \n", russian_Be);
 
}

int main(void)
{
    setlocale(LC_ALL, "");

    // recall you can only use wide or narrow streams, so comment out one of the next two calls
    //print_narrow_info();    // gives UTF-8
    print_wide_info();  // gives UTF-8
}
